package main

import (
	"fmt"
	"time"
)

func new_task(){
	i:=0
	for{
		i++
		fmt.Println("new goroutine : i =",i)
		time.Sleep(1*time.Second)
	}
}

func main()  {
	// 创建一个goroutine去执行new_task
	go new_task()

	// 主线程继续往下执行
	i:=0
	for{
		i++
		fmt.Println("main goroutine : i =",i)
		time.Sleep(1*time.Second)
	}
	
}