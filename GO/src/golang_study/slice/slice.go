package main

import "fmt"

// slice是传引用
func print_array(my_slice []int){
	for index,value := range(my_slice){
		fmt.Println("index = ",index,"value = ",value)
	}
	// 可以在这里修改值
	my_slice[0]=1111
}

func main(){
	// 动态数组，slice
	my_array := []int{1,2,3,4}

	fmt.Printf("type of []int is %T\n",my_array)

	print_array(my_array)

	
	for index,value := range(my_array){
		fmt.Println("index = ",index,"value = ",value)
	}
}