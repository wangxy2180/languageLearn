package main

import "fmt"

func main(){
	// 1.声明slice1是一个切面，并初始化，默认值123，长度是3
	slice1:=[]int{1,2,3}

	fmt.Printf("len = %d,slice1=%v\n",len(slice1),slice1)

	// 声明slice2是一个切片，但是没有分类slice空间
	var slice2 []int
	slice2 = make([]int, 3)
	slice2[1]=10001
	fmt.Printf("len = %d,slice2=%v\n",len(slice2),slice2)

	// 合二为一
	var slice3 []int = make([]int , 3)
	slice3[1]=10101
	fmt.Printf("len = %d,slice3=%v\n",len(slice3),slice3)

	// 简写,**比较常用**
	slice4 := make([]int,3)
	slice4[1]=99
	fmt.Printf("len = %d,slice4=%v\n",len(slice4),slice4)

	// 判断slice是否为空
	var slice5 []int
	if(slice5==nil){
		fmt.Println("slice5 是空切片")
	}else{
		fmt.Println("slice5 不是空切片")

	}



}