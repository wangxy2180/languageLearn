package main

import (
	"fmt"
	"time"
)

func new_task()  {
	// for i :=0;;i++ range()
	i:=0
	for{
		i++
		fmt.Printf("new go routine : i=%d\n",i)
		time.Sleep(1*time.Second)
	}
}

func main()  {
	// 创建一个goroutine，去执行task流程
	go new_task()

	// 主线程结束，子线程也会结束

	fmt.Println("main goroutine exit")

	// i:=0
	// for{
	// 	i++
	// 	fmt.Printf("main go routine : i=%d\n",i)
	// 	time.Sleep(1*time.Second)
	// }
}