package main

import "fmt"

// const进行枚举
const(
	// 可以在const()添加关键字 iota,每行的iota都会累加+1，第一行的iota默认值是0
	BEIJING = 10 * iota //iota = 0 * 10
	SHANGHAI 		//iota = 1 * 10
	SHENZHEN 		//iota = 2 * 10
)

// iota是逐行累加的,只能出现在const中
const (
	a,b = iota+1,iota+2  //iota = 0, a = iota+1,b=iota+2,a=1,b=2
	c,d					 //iota = 1, a = iota+1,b=iota+2,a=2,b=3
	e,f					 //iota = 2, a = iota+1,b=iota+2,a=3,b=4

	g,h = iota*2, iota*3 //iota = 3, a = iota*2,b=iota*3,a=6,b=9
	i,k					 //iota = 4, a = iota*2,b=iota*3,a=9,b=12

)

func main(){
	// 常量，只读
	const length int = 10
	fmt.Println("length =",length)
	// length = 100 这句会报错，因为常量不允许修改

	fmt.Println("BEIJING =",BEIJING)
	fmt.Println("SHANGHAI =",SHANGHAI)
	fmt.Println("SHENZHEN =",SHENZHEN)

}