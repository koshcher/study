package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	source := rand.NewSource(time.Now().UnixNano())
	rnd := rand.New(source)
	var (
		compNum int8 = int8(rnd.Intn(100))
		userNum int8
		isRun   bool = true
	)

	fmt.Println("Number guessed!")

	for isRun {
		_, err := fmt.Scan(&userNum)
		if err != nil {
			fmt.Println("Input is incorrect")
			continue
		}
		if compNum > userNum {
			fmt.Println("Too small")
		} else if compNum == userNum {
			fmt.Println("You winner!")
			isRun = false
		} else {
			fmt.Println("Too big")
		}
	}
}
