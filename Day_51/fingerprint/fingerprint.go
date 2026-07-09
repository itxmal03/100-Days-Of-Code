package main

import (
	"crypto/tls"
	"fmt"
	"io"
	"net/http"
	"regexp"
	"time"
)

var client = &http.Client{
	Timeout: 5 * time.Second,
	Transport: &http.Transport{
		TLSClientConfig: &tls.Config{InsecureSkipVerify: true},
	},
}

func fetch(url string) (body string, status int, err error) {
	resp, err := client.Get(url)
	if err != nil {
		return "", 0, err
	}
	defer resp.Body.Close()
	b, err := io.ReadAll(resp.Body)
	if err != nil {
		return "", resp.StatusCode, err
	}
	return string(b), resp.StatusCode, nil
}

func main() {
	base := "https://192.168.5.1"
	endpoints := []string{
		base + "/",
		base + "/api/self",
		"https://192.168.5.1:8443/manage",
		"https://192.168.5.1:8444/protect",
	}

	for _, url := range endpoints {
		fmt.Printf("\n--- Fetching %s ---\n", url)
		body, status, err := fetch(url)
		if err != nil {
			fmt.Printf("ERROR: %v\n", err)
			continue
		}
		fmt.Printf("Status: %d\n", status)
		if status != 200 {
			// Show first 200 chars of body
			if len(body) > 200 {
				body = body[:200] + "..."
			}
			fmt.Printf("Body preview: %s\n", body)
			continue
		}

		// Try to extract version from body
		// Look for patterns like "v1.2.3", "version":"x.y.z", etc.
		re := regexp.MustCompile(`(?i)(?:v|version)[\s:=]+["']?(\d+\.\d+\.\d+)`)
		matches := re.FindAllStringSubmatch(body, -1)
		if len(matches) > 0 {
			fmt.Printf("Found version(s): ")
			for _, m := range matches {
				fmt.Printf("%s ", m[1])
			}
			fmt.Println()
		}

		// Show title if present
		titleRe := regexp.MustCompile(`<title>(.*?)</title>`)
		titleMatch := titleRe.FindStringSubmatch(body)
		if len(titleMatch) > 1 {
			fmt.Printf("Title: %s\n", titleMatch[1])
		}

		// Print first 500 chars for inspection
		if len(body) > 500 {
			fmt.Printf("Body preview (first 500 chars):\n%s...\n", body[:500])
		} else {
			fmt.Printf("Body:\n%s\n", body)
		}
	}
}