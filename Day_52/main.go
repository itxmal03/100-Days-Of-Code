package main

import (
	"bufio"
	"bytes"
	_ "embed"
	"fmt"
	"io"
	"os"
	"os/exec"
	"strings"
	"time"

	"github.com/faiface/beep"
	"github.com/faiface/beep/mp3"
	"github.com/faiface/beep/speaker"
)

//go:embed music.mp3
var musicData []byte

const (
	reset   = "\033[0m"
	bold    = "\033[1m"
	rose    = "\033[38;2;233;69;96m"
	gold    = "\033[38;2;255;200;87m"
	white   = "\033[38;2;255;255;255m"
	green   = "\033[38;2;0;255;100m"
	cyan    = "\033[38;2;0;255;220m"
	magenta = "\033[38;2;220;50;200m"
	pink    = "\033[38;2;255;150;180m"
	yellow  = "\033[38;2;255;220;50m"
	red     = "\033[38;2;255;0;0m"
)

const passcode = "1228"

func clearScreen() { fmt.Print("\033[2J\033[H") }
func hideCursor()  { fmt.Print("\033[?25l") }
func showCursor()  { fmt.Print("\033[?25h") }

func playMusic() {
	if len(musicData) == 0 {
		return
	}
	streamer, format, err := mp3.Decode(io.NopCloser(bytes.NewReader(musicData)))
	if err != nil {
		return
	}
	speaker.Init(format.SampleRate, format.SampleRate.N(time.Second/10))
	// Loop forever using a custom StreamerFunc that resets when EOF
	speaker.Play(beep.StreamerFunc(func(samples [][2]float64) (n int, ok bool) {
		n, ok = streamer.Stream(samples)
		if !ok {
			streamer.Close()
			// re‑decode
			newS, _, err2 := mp3.Decode(io.NopCloser(bytes.NewReader(musicData)))
			if err2 != nil {
				return 0, false
			}
			streamer = newS
			n, ok = streamer.Stream(samples)
		}
		return n, ok
	}))
}
func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// passwordPrompt – box with '=', red prompt, safe padding, and "Press Enter" to keep message
func passwordPrompt() bool {
	for attempts := 0; attempts < 5; attempts++ {
		clearScreen()
		boxWidth := 60
		fmt.Println(rose + "+" + strings.Repeat("=", boxWidth) + "+" + reset)
		fmt.Println(rose + "|" + strings.Repeat(" ", boxWidth) + "|" + reset)
		title := "* >>>E,,,,,,*"
		fmt.Printf(rose+"|  %-*s  |\n", boxWidth-4, title)
		fmt.Println(rose + "|" + strings.Repeat(" ", boxWidth) + "|" + reset)
		prompt := "--Enter password (4-digits):"
		fmt.Printf(red+"|  %-*s  |\n", boxWidth-4, prompt)
		fmt.Print(red + "|  " + reset)
		showCursor()
		entered := readLine()
		hideCursor()

		if entered == passcode {
			return true
		}

		fmt.Println(rose + "|  " + reset + "\033[41m\033[97m WRONG \033[0m" + rose + strings.Repeat(" ", boxWidth-12) + "  |" + reset)

		if entered == "1201" {
			msg := "Sorry this was never your password 😊\n Enter your passwd thanx!"
			pad := boxWidth - len(msg) - 4
			if pad < 0 {
				pad = 0
			}
			fmt.Println(rose + "|  " + reset + msg + strings.Repeat(" ", pad) + "  |" + reset)
		}

		fmt.Println(rose + "+" + strings.Repeat("=", boxWidth) + "+" + reset)
		fmt.Println(gold + "Press Enter to continue..." + reset)
		reader := bufio.NewReader(os.Stdin)
		reader.ReadString('\n')
	}
	return false
}

// wrapLine splits a long line into chunks ≤ maxLen (based on spaces)
func wrapLine(text string, maxLen int) []string {
	if len(text) <= maxLen {
		return []string{text}
	}
	var lines []string
	words := strings.Fields(text)
	var current strings.Builder
	for _, word := range words {
		if current.Len()+len(word)+1 > maxLen {
			lines = append(lines, current.String())
			current.Reset()
			current.WriteString(word)
		} else {
			if current.Len() > 0 {
				current.WriteString(" ")
			}
			current.WriteString(word)
		}
	}
	if current.Len() > 0 {
		lines = append(lines, current.String())
	}
	return lines
}

// typewriter – left‑aligned, with automatic wrapping
func typewriter(lines []string, color string) {
	clearScreen()
	for _, raw := range lines {
		for _, line := range wrapLine(raw, 60) {
			fmt.Print(color)
			for _, ch := range line {
				fmt.Print(string(ch))
				time.Sleep(50 * time.Millisecond)
			}
			fmt.Print(reset)
			fmt.Println()
			time.Sleep(150 * time.Millisecond)
		}
		fmt.Println() // blank line between paragraphs
	}
}

// staticLovedBox – prints the loved box 50 times vertically
func staticLovedBox() {
	boxWidth := 50
	line := "+" + strings.Repeat("=", boxWidth) + "+"
	empty := "|" + strings.Repeat(" ", boxWidth) + "|"
	inner := "   I AM SORRRRYYYYY.   "
	padded := fmt.Sprintf("|  %-*s  |", boxWidth-4, inner)

	for i := 0; i < 50; i++ {
		fmt.Println(gold + bold + line + reset)
		fmt.Println(gold + bold + empty + reset)
		fmt.Println(gold + bold + padded + reset)
		fmt.Println(gold + bold + empty + reset)
		fmt.Println(gold + bold + line + reset)
		fmt.Println()
	}
}

func main() {
	exec.Command("cmd", "/c", "").Run()
	hideCursor()
	defer showCursor()
	go playMusic()

	if !passwordPrompt() {
		clearScreen()
		fmt.Println(rose + "\nToo many attempts. Come back when you are ready." + reset)
		return
	}

	// Main apology – wrapped lines
	message := []string{
		"",
	}
	typewriter(message, green)

	// Loved box (50 times)
	staticLovedBox()

	// Exit prompt
	fmt.Println(gold + strings.Repeat("=", 60) + reset)
	fmt.Println(gold + "Type 'e' and press Enter to close." + reset)

	showCursor()
	reader := bufio.NewReader(os.Stdin)
	for {
		line, _ := reader.ReadString('\n')
		if strings.TrimSpace(strings.ToLower(line)) == "e" {
			break
		}
	}
}
