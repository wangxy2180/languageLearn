package main

import (
	"fmt"
	"runtime"
	"time"
)

func main(){
	// 匿名函数
	// 用go创建承载一个形参为空，返回值为空的函数
	go func(){
		defer fmt.Println("A.defer")
		func(){
			defer fmt.Println("B.defer")
			// 退出goroutine，如果单纯使用return，无法完整执行完再退出
			// 这样他不会执行“A”“B”，因为他提前退出了
			runtime.Goexit()
			fmt.Println("B")
		}()
		// 注意上边的小括号，就是调用

		fmt.Println("A")
	}()

	// 有参数的函数
	// 这个返回值无法通过传统的赋值方式获得，需要使用channel进行go程间的通信
	go func(a int, b int) bool{
		fmt.Println("a=",a,"b=",b)
		return true
	}(10,20)

	// 死循环，保证不死亡
	for{
		time.Sleep(1*time.Second)
	}

}