package main

import "fmt"

func main()  {
	// 定义一个channel（无缓冲）
	c:=make(chan int)

	go func(){
		defer fmt.Println("goroutine is ended")
		fmt.Println("goroutine is running")
		// 将666写到c中
		c <- 666
	}()

	// channel会保证先后顺序。如果先到了主线程的赋值，会触发阻塞，等待c的值。当c中有值才会执行下边这条赋值语句
	// 从c中接收数据并赋值给num
	// fmt.Println("num is",<-c)
	num := <- c
	fmt.Println("num is",num)
	fmt.Println("main goroutine is ended")
}