package main

import "fmt"

// 声明一种新的数据类型 my_int，实际是int的别名
type my_int int

// 定义一个结构体
type my_book struct{
	title string
	author string
}

// 他是pass by value
func changebook(book my_book){
	book.author = "lisi"
}

func changebook2(book *my_book){
	book.author = "lisi"
}

func main(){

	var a my_int = 101
	fmt.Println("a =",a)
	fmt.Printf("typr of a is %T\n",a)

	var book1 my_book
	book1.title="GO-language"
	book1.author="zhangsan"

	// %v表示可以打印任何数据类型
	fmt.Printf("book1 is %v\n",book1)

	// 从下边的可以看出，如果传结构体，最好使用传指针的方式
	changebook(book1)
	fmt.Printf("book1 is %v\n",book1)
	changebook2(&book1)
	fmt.Printf("book1 is %v\n",book1)


}