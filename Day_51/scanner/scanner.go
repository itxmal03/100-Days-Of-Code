package main

import (
	"fmt"
	"net"
	"sync"
	"time"
)

func main() {
	host := "192.168.5.1"
	const maxPort = 65535
	const concurrency = 500

	var wg sync.WaitGroup
	openPorts := []int{}
	var mu sync.Mutex

	// Worker that scans a single port
	scan := func(port int) {
		defer wg.Done()
		target := net.JoinHostPort(host, fmt.Sprintf("%d", port))
		conn, err := net.DialTimeout("tcp", target, 1*time.Second)
		if err == nil {
			conn.Close()
			mu.Lock()
			openPorts = append(openPorts, port)
			mu.Unlock()
			fmt.Printf("[+] Port %d open\n", port)
		}
	}

	// Launch workers with a semaphore to limit concurrency
	sem := make(chan struct{}, concurrency)
	for port := 1; port <= maxPort; port++ {
		wg.Add(1)
		sem <- struct{}{} // block if at limit
		go func(p int) {
			scan(p)
			<-sem // release slot
		}(port)
	}

	wg.Wait()
	fmt.Println("\n=== Scan complete ===")
	if len(openPorts) == 0 {
		fmt.Println("No open ports found.")
	} else {
		fmt.Printf("Open ports: %v\n", openPorts)
	}
}