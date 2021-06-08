package main

import "fmt"

// 数组传参必须要精确数组的长度
// [10]int是传值
func print_array(my_array [5]int){
	// 值拷贝
	for index, value := range my_array{
		fmt.Println("index = ",index,"value = ",value)
	}
}

func main(){
	// 表示定长数组
	var my_array1 [10]int

	for i:=0;i<len(my_array1);i++{
		fmt.Println(my_array1[i])
	}

	my_array2:=[5]int{1,2,3,4}
	for index, value := range my_array2{
		fmt.Println("index = ",index,"value = ",value)
	}

	// 查看数组的数据类型
	fmt.Printf("typr of array is %T\n",my_array1)

	// 这里只能输入my_array2，因为my_array1的长度不符合，也就是类型不匹配
	print_array(my_array2)
}