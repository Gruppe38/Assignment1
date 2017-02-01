package main

import (
	. "fmt"
	"runtime"
	"time"
)

var i int = 0
var iChan = make(chan int, 1)

func thread1() {
	for j := 0; j < 1000000; j++ {
		k := <-iChan
		k += 1
		i = k
		iChan <- i
	}
}

func thread2() {
	for j := 0; j < 1000001; j++ {
		k := <-iChan
		k -= 1
		i = k
		iChan <- i
	}
}

func main() {
	iChan <- i
	runtime.GOMAXPROCS(runtime.NumCPU())
	go thread1()
	go thread2()

	// We'll come back to using channels in Exercise 2. For now: Sleep.
	time.Sleep(1000 * time.Millisecond)
	i := <-iChan
	Println(i)
}
