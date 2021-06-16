package main

import "fmt"

func fibo(c,quit chan int){
	x,y:=1,1
	// select 多路监控channel状态
	for{
		select{
		case c<-x:
			// 如果c可写，就会进入这里
			x,y = y,x+y
			// 如果quit可读，就会进入下边这个
		case <-quit:
			fmt.Println("quit")
			return 
		}
	}

}

func main()  {
	c:=make(chan int)
	quit:=make(chan int)

	go func(){
		for i :=0;i<6;i++{
			fmt.Println(<-c)
		}
		quit<-0
	}()


	fibo(c,quit)
}