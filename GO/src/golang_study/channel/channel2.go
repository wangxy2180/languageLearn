package main

import (
	"fmt"
	"time"
)

func main()  {
	// 缓冲为3的channel
	c:=make(chan int,3)

	fmt.Println("len(c)=",len(c),", cap(c)=",cap(c))

	go func(){
		defer fmt.Println("go routine is ended")
		for i:=0;i<3;i++{
			time.Sleep(2*time.Second)
			c<-i
			fmt.Println("go is running, ","发送的元素=",i,"len(c)=",len(c),", cap(c)=",cap(c))
		}
	}()

	// time.Sleep(2*time.Second)

	for i :=0;i<3;i++{
		// 从c中接收并赋值
		num := <-c
		fmt.Println("num is:",num)
	}

	// fmt的先后顺序无法保证
	fmt.Println("main is ended")
	
}