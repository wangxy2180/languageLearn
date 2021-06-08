package main

import "fmt"

func main(){
	s:=[]int{1,2,3} //len=3,cap=3

	//[0,2)
	// [1,2]两个元素
	s1 := s[0:2]
	fmt.Println(s1)

	// s1其实是指向了s的内存
	// 修改s后，s1的值也变了
	s[0]=1000
	fmt.Println(s1)

	// 深拷贝
	s2:=make([]int,3) //s2=[0,0,0]
	// 将s中的值依次拷贝到s2中
	copy(s2,s)
	fmt.Println(s2)

}