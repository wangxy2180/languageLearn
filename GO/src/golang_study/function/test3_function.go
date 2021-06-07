package main

import "fmt"

func foo1(a string, b int)int{
	fmt.Println("a =",a)
	fmt.Println("b =",b)

	c:=100
	return c
}

// 返回多个值,匿名
func foo2(a string, b int)(int, int){
	fmt.Println("a =",a)
	fmt.Println("b =",b)

	return 666,777
}

// 返回多个返回值，有形参名,最后直接return就可以
// r1 和 r2 作为两个局部形参赋值，默认初始值是0
func foo3(a string, b int)(r1 int, r2 int){
	fmt.Println("------foo3------")
	fmt.Println("a =",a)
	fmt.Println("b =",b)
	// 有名称的返回值赋值
	r1 = 1012
	r2 = 3021
	return
}

// 返回多个相同类型的返回值
func foo4(a string, b int)(r1,r2 int){
	fmt.Println("------foo3------")
	fmt.Println("a =",a)
	fmt.Println("b =",b)
	// 有名称的返回值赋值
	r1 = 122222
	r2 = 3444444
	return
}

func main() {
	c:=foo1("555",1)
	fmt.Println("c = ",c)

	ret1, ret2:=foo2("99999",7)
	fmt.Println("ret1 = ",ret1, "ret2 = ",ret2)

	r1, r2:=foo3("3333333333333",3)
	fmt.Println("r1 = ",r1, "r2 = ",r2)

	r1, r2=foo3("334444444444444444",4)
	fmt.Println("r1 = ",r1, "r2 = ",r2)

}