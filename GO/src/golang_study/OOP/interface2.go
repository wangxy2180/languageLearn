package main

import "fmt"

// interface{}是万能数据类型
// 空接口没有任何方法，所以都默认实现了空接口
func myFunc(arg interface{}){
	fmt.Println("myFunc is called...")
	fmt.Println(arg)

	// interface{}如何区分词是引用的数据类型到底是什么？
	// 给interface{}提供了“类型断言机制”
	
	value, ok := arg.(string)
	if !ok {
		fmt.Println("arg is not string")
	}else{
		fmt.Println("string val is",value)
	}
}

type Book struct{
	author string
}

func main(){
	book1:=Book{"lisi"}
	// 可以看出，myFunc不管任何数据类型都可以传进去
	myFunc(book1)
	myFunc(1001)
	myFunc("string")


}