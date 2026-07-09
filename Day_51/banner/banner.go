package main

import (
	"crypto/tls"
	"fmt"
	"net"
	"time"
)

var host = "192.168.5.1"
var ports = []int{
	53, 80, 443, 6789, 8080, 8443, 8444, 8843, 8880, 8900, 8901, 9443, 11083, 20201, 28082,
}

// safe banner read with timeout
func readBanner(conn net.Conn) string {
	conn.SetReadDeadline(time.Now().Add(2 * time.Second))
	buf := make([]byte, 1024)
	n, err := conn.Read(buf)
	if err != nil {
		return fmt.Sprintf("(read error: %v)", err)
	}
	return string(buf[:n])
}

func grabHTTP(port int) {
	target := net.JoinHostPort(host, fmt.Sprintf("%d", port))
	var conn net.Conn
	var err error

	// Detect HTTPS ports
	isHTTPS := false
	httpsPorts := map[int]bool{443: true, 8443: true, 8444: true, 8843: true, 9443: true}
	if httpsPorts[port] {
		isHTTPS = true
		conn, err = tls.DialWithDialer(&net.Dialer{Timeout: 3 * time.Second}, "tcp", target, &tls.Config{InsecureSkipVerify: true})
	} else {
		conn, err = net.DialTimeout("tcp", target, 3*time.Second)
	}

	if err != nil {
		fmt.Printf("[%d] FAIL: %v\n", port, err)
		return
	}
	defer conn.Close()

	// Send HTTP GET
	req := "GET / HTTP/1.0\r\nHost: " + host + "\r\n\r\n"
	conn.SetWriteDeadline(time.Now().Add(2 * time.Second))
	_, err = conn.Write([]byte(req))
	if err != nil {
		fmt.Printf("[%d] WRITE ERR: %v\n", port, err)
		return
	}

	banner := readBanner(conn)
	// Extract Server header or first line
	fmt.Printf("[%d] (%s) -> %s\n", port, map[bool]string{true: "HTTPS", false: "HTTP"}[isHTTPS], banner)
}

func main() {
	fmt.Printf("=== Banner grabbing %s on %d ports ===\n", host, len(ports))
	for _, p := range ports {
		grabHTTP(p)
	}
	fmt.Println("=== Done ===")
}