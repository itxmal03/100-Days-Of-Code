package main

import (
	"crypto/tls"
	"fmt"
	"io"
	"net/http"
	"net/url"
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

func fetchPage(urlStr string) (string, *http.Response, error) {
	resp, err := client.Get(urlStr)
	if err != nil {
		return "", nil, err
	}
	defer resp.Body.Close()
	body, err := io.ReadAll(resp.Body)
	return string(body), resp, err
}

func extractVersion(html string) string {
	// Look for patterns like "v1.2.3", "version: 1.2.3", "UNIFI_OS_VERSION=1.2.3"
	patterns := []string{
		`(?:v|version)[\s:=]+["']?(\d+\.\d+\.\d+)`,
		`UNIFI_OS_VERSION\s*=\s*["'](\d+\.\d+\.\d+)`,
		`"version":"(\d+\.\d+\.\d+)"`,
		`<meta[^>]*name="version"[^>]*content="([^"]+)"`,
	}
	for _, pat := range patterns {
		re := regexp.MustCompile(pat)
		matches := re.FindAllStringSubmatch(html, -1)
		if len(matches) > 0 {
			return matches[0][1]
		}
	}
	return "not found"
}

func extractLoginEndpoint(html, baseURL string) string {
	// Look for form action
	re := regexp.MustCompile(`<form[^>]*action=["']([^"']+)["']`)
	matches := re.FindStringSubmatch(html)
	if len(matches) > 1 {
		action := matches[1]
		if strings.HasPrefix(action, "/") {
			return baseURL + action
		}
		return action
	}
	// Default endpoints
	common := []string{"/api/auth/login", "/api/login", "/login"}
	for _, path := range common {
		return baseURL + path
	}
	return baseURL + "/api/auth/login"
}

func tryLogin(loginURL, username, password string) (bool, error) {
	// Build POST data
	data := url.Values{}
	data.Set("username", username)
	data.Set("password", password)
	// Some forms expect "email" or "user" – try common fields
	// We'll send both to be safe
	req, err := http.NewRequest("POST", loginURL, strings.NewReader(data.Encode()))
	if err != nil {
		return false, err
	}
	req.Header.Set("Content-Type", "application/x-www-form-urlencoded")
	req.Header.Set("User-Agent", "Go-Scanner")

	resp, err := client.Do(req)
	if err != nil {
		return false, err
	}
	defer resp.Body.Close()

	// If we get a redirect to /dashboard or /overview, likely success
	if resp.StatusCode == 302 {
		location := resp.Header.Get("Location")
		if strings.Contains(location, "dashboard") || strings.Contains(location, "overview") {
			return true, nil
		}
	}
	// If status 200 but body contains "Invalid credentials" etc.
	body, _ := io.ReadAll(resp.Body)
	if strings.Contains(string(body), "Invalid") || strings.Contains(string(body), "incorrect") {
		return false, nil
	}
	// If status 200 and it looks like a dashboard (e.g., contains "Dashboard")
	if resp.StatusCode == 200 && strings.Contains(string(body), "Dashboard") {
		return true, nil
	}
	return false, nil
}

func main() {
	base := "https://192.168.5.1"
	fmt.Printf("=== Fingerprint & Login Test for %s ===\n", base)

	// 1. Get main page
	html, resp, err := fetchPage(base + "/")
	if err != nil {
		fmt.Printf("Failed to fetch main page: %v\n", err)
		return
	}
	fmt.Printf("Main page status: %d\n", resp.StatusCode)

	version := extractVersion(html)
	fmt.Printf("Detected version: %s\n", version)

	// 2. Extract login endpoint
	loginURL := extractLoginEndpoint(html, base)
	fmt.Printf("Login endpoint: %s\n", loginURL)

	// 3. Try default credentials
	creds := [][2]string{
		{"ubnt", "ubnt"},
		{"admin", "admin"},
		{"root", "ubnt"},
		{"admin", "ubnt"},
		{"ubnt", "admin"},
	}
	fmt.Println("\n--- Trying default credentials ---")
	for _, c := range creds {
		success, err := tryLogin(loginURL, c[0], c[1])
		if err != nil {
			fmt.Printf("[%s:%s] ERROR: %v\n", c[0], c[1], err)
			continue
		}
		if success {
			fmt.Printf("[%s:%s] ✅ SUCCESS\n", c[0], c[1])
		} else {
			fmt.Printf("[%s:%s] ❌ Failed\n", c[0], c[1])
		}
	}

	fmt.Println("\n=== Done ===")
}
