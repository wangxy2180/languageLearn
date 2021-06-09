package main

import "fmt"

func main(){
	// map[key]value 只是声明，并没有内存空间
	var my_map1 map[string]string
	if (my_map1 == nil) {
		fmt.Println("my map 1 is empty map")
	}

	// 分类内存
	// 使用map前先用make给他分配内存空间
	my_map1 = make(map[string]string, 10)
	my_map1["one"]="java"
	my_map1["two"]="c"
	my_map1["three"]="c++"
	my_map1["four"]="go"

	fmt.Println(my_map1)

	// 第二种声明方式，同时声明+分配内存
	// 可以不写容量，他会自动追加
	my_map2:=make(map[int]string)
	my_map2[1]="java"
	my_map2[2]="c"
	my_map2[3]="c++"
	my_map2[4]="go"
	fmt.Println(my_map2)

	// 3.创建的同时初始化
	my_map3:=map[string]string{
		"one":"ccc",
		"two":"bbb",
		"three":"cccc",
		// 注意最后一行也要有逗号
	}
	fmt.Println(my_map3)


}