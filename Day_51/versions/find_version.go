package main

import (
	"crypto/tls"
	"fmt"
	"io"
	"net/http"
	"regexp"
	"strings"
	"time"
)

var client = &http.Client{
	Timeout: 10 * time.Second,
	Transport: &http.Transport{
		TLSClientConfig: &tls.Config{InsecureSkipVerify: true},
	},
}

func fetch(url string) (string, error) {
	resp, err := client.Get(url)
	if err != nil {
		return "", err
	}
	defer resp.Body.Close()
	body, err := io.ReadAll(resp.Body)
	return string(body), err
}

func extractScriptSrc(html, base string) []string {
	re := regexp.MustCompile(`<script[^>]*src=["']([^"']+)["']`)
	matches := re.FindAllStringSubmatch(html, -1)
	var urls []string
	for _, m := range matches {
		src := m[1]
		if strings.HasPrefix(src, "//") {
			src = "https:" + src
		} else if strings.HasPrefix(src, "/") {
			src = base + src
		} else if !strings.HasPrefix(src, "http") {
			src = base + "/" + src
		}
		urls = append(urls, src)
	}
	return urls
}

func searchVersion(text string) string {
	patterns := []string{
		`(?:v|version)[\s:=]+["']?(\d+\.\d+\.\d+)`,
		`build["']?\s*[:=]\s*["']?([A-Za-z0-9]+)`,
		`"version"\s*:\s*"([^"]+)"`,
		`<meta[^>]*name="version"[^>]*content="([^"]+)"`,
		`UNIFI_OS_VERSION\s*=\s*["']([^"']+)`,
		`UNIFI_OS_BUILD\s*=\s*["']([^"']+)`,
	}
	for _, pat := range patterns {
		re := regexp.MustCompile(pat)
		matches := re.FindAllStringSubmatch(text, -1)
		if len(matches) > 0 {
			return matches[0][1]
		}
	}
	return ""
}

func main() {
	base := "https://192.168.5.1"
	fmt.Printf("=== Version extraction from %s ===\n", base)

	// 1. Get main page
	html, err := fetch(base + "/")
	if err != nil {
		fmt.Printf("Failed to fetch main page: %v\n", err)
		return
	}

	// 2. Extract script URLs
	scriptURLs := extractScriptSrc(html, base)
	fmt.Printf("Found %d script files.\n", len(scriptURLs))

	// Search version in main page first
	ver := searchVersion(html)
	if ver != "" {
		fmt.Printf("Version found in main page: %s\n", ver)
	} else {
		fmt.Println("No version in main page; scanning scripts...")
	}

	// 3. Download and search each script
	for i, u := range scriptURLs {
		fmt.Printf("Fetching script %d: %s\n", i+1, u)
		content, err := fetch(u)
		if err != nil {
			fmt.Printf("  ERROR: %v\n", err)
			continue
		}
		ver = searchVersion(content)
		if ver != "" {
			fmt.Printf("  Found version: %s\n", ver)
			break
		}
		// Also print first 100 chars to see if it's minified or not
		if len(content) > 100 {
			fmt.Printf("  Preview: %s...\n", content[:100])
		}
	}

	// 4. Try public API endpoints
	apis := []string{
		"/api/system/info",
		"/api/status",
		"/proxy/network/api/self",
	}
	fmt.Println("\n--- Trying public API endpoints ---")
	for _, path := range apis {
		url := base + path
		resp, err := client.Get(url)
		if err != nil {
			fmt.Printf("%s -> ERROR: %v\n", path, err)
			continue
		}
		body, _ := io.ReadAll(resp.Body)
		resp.Body.Close()
		fmt.Printf("%s -> Status: %d, body preview: %s\n", path, resp.StatusCode, string(body[:200]))
		if resp.StatusCode == 200 {
			ver = searchVersion(string(body))
			if ver != "" {
				fmt.Printf("  Found version in API: %s\n", ver)
			}
		}
	}

	fmt.Println("=== Done ===")
}