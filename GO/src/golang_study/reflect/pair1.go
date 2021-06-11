package main

import "fmt"

func main()  {
	var a string
	// pair<static type:string, value:"asdfg">
	a="asdfg"

	// 不管赋值给谁，pair的内容永远不变
	// 定义一个万能类型
	// pair<type:string,value:"asdfg">
	var all_type interface{}
	// 做一个赋值
	all_type=a
	value,_:=all_type.(string)
	fmt.Println(value)
}