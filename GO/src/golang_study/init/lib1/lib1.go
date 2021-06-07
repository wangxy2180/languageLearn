package lib1

import "fmt"

// 当前lib1包提供的API
// 注意：如果这个函数要被外部引用，首字母大写
func Lib1_test(){
	fmt.Println("lib1_test() ...")

}

// 一个初始化函数
func init(){
	fmt.Println("lib1.init() ...")

}