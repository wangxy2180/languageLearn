package main

// package basic_grammar

import "fmt"

// 结构体定义
type Books struct {
	title   string
	author  string
	subject string
	book_id int
}

func main() {

	// 1、变量声明########################################
	// go语言声明变量的方式很特别，var var_name var_type[ = value]
	// 这里虽然声明了result变量，但并没有使用，编译器会报错的，所以如果没必要的变量，不要定义
	// var result int
	var num1 int = 100
	var num2 int = 101
	fmt.Println("max value is %d", max(num1, num2))

	// 也可以直接使用等于，不声明数据类型，让他自己判断
	var str1 = "str1"
	var str2 string = "str2"
	// 还可以使用：=进行赋值，但是左侧的变量必须是新出现的，前边不能出先他的声明
	a, b := my_swap(str1, str2)
	fmt.Println("multi ret value", a, b)

	fmt.Println("pass by ref,before", str1, str2)
	my_swap_ref(&str1, &str2)
	fmt.Println("pass by ref,after", str1, str2)

	// 同样你也可以进行常量的定义
	const LENGTH int = 50
	// 还可以进行枚举
	const (
		Unknown = 0
		Female  = 1
		Male    = 2
	)
	// 他甚至还有指针这种东西
	var ptr *int
	ptr = &num1
	fmt.Println("pointer", ptr, *ptr)

	fmt.Println("循环学习", loop_func(10))

	// 结构体初始化，使用花括号
	// 同样可使用.操作符进行成员访问
	fmt.Println("结构体：", Books{"GO", "wxy", "code", 111})
	fmt.Println("结构体：", Books{title: "GO", author: "wxy", subject: "code", book_id: 111})

}

// 函数的定义, []内的表示可以省略
// func func_name([param_list])[return type]{

// }
func max(num1, num2 int) int {
	var result int

	// 条件上边不需要加括号，你加了，vscode就自动给你去掉了，但是花括号必须要有
	if num1 > num2 {
		// 这里边同样可以嵌套if语句
		result = num1
	} else {
		result = num2
	}
	// 这里的else需要紧跟在if的}后边，花括号不能单占一行
	return result
}

// 函数还可以返回多个值,使用()进行包裹
func my_swap(str1, str2 string) (string, string) {
	return str2, str1
}

func my_swap_ref(str1 *string, str2 *string) {
	*str2, *str1 = *str1, *str2
}

func loop_func(num int) int {
	sum := 0

	// 普通的for循环
	// 注意，只有i++，没有++i
	for i := 0; i < num; i++ {
		sum += i
	}

	// 死循环
	for {
		// 这样就是一种死循环，只能ctrl+c退出
		break
	}

	// for each循环
	// 数组的定义方式是在数据类型前加[],[]中可以写大小
	// []也可以置空或者写成...他会自动进行长度推断
	str_list := []string{"str1", "str2", "str3", "str4"}
	for index, val := range str_list {
		fmt.Printf("第%d个是%s\n", index, val)
	}

	// 类似c中的while循环
	for sum < 100 {
		sum++
	}

	return sum
}
