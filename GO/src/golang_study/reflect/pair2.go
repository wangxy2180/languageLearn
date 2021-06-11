package main

import "fmt"

type Reader interface{
	ReadBook()
}


type Writer interface{
	WriteBook()
}

// 具类
type Book struct{

}

// Book类既实现了Reader，又实现了Writer接口
func (book *Book) ReadBook(){
	fmt.Println("read book  ...")
}

func (book *Book) WriteBook(){
	fmt.Println("write book ...")	
}

func main(){
	// b:pair<type:book,value:book{}地址>
	b:=&Book{}

	// 定义一个reader
	// r:pair<type:,value:>
	var r Reader
	// r:pair<type:book,value:book{}地址>
	r=b
	// 这里就相当于调用具体类型的方法
	r.ReadBook()

	// w:pair<type:,value:>
	var w Writer
	// w:pair<type:book,value:book{}地址>
	// 因为w和r具体的type一致，所以成功了，因为reader和writer都指向Book
	w=r.(Writer)
	w.WriteBook()

	
}