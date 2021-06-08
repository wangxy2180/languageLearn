package main

import "fmt"

// 在函数结束前出发defer关键字
// defer是一种压栈的方式，也就是说从后向前执行

func deferFunc()int{
	fmt.Println("this is defer call")
	return 0
}

func returnFunc()int{
	fmt.Println("this is return call")
	return 0
}

func returnANDdefer() int{
	defer deferFunc()
	return returnFunc()

}

func main(){
	// 写入defer关键字
	// 压栈式执行，先执行2，在执行1
	defer fmt.Println("main end 1")
	defer fmt.Println("main end 2")


	fmt.Println("main::hello world go 1")
	fmt.Println("main::hello world go 2")
	fmt.Println("--------------------------------")

	// 先触发return，再触发defer
	returnANDdefer()
}