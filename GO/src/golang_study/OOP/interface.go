package main

import "fmt"

// interface本质是一个指针
type AnimalIF interface{
	Sleep()
	GetColor() string //获取动物颜色
	GetType() string //获取动物种类

}

// 具体的类
type Cat struct{
	color string
}

// 必须完全实现接口中所有方法，否则该接口无法指向该类
func (cat *Cat) Sleep(){
	fmt.Println("cat is sleeping")
}

func (cat *Cat) GetColor() string{
	fmt.Println("cat color is",cat.color)
	return cat.color
}

func (cat *Cat) GetType() string{
	fmt.Println("type is","cat")
	return "cat"
}


// 又一个新的类
type Dog struct{
	color string
}

// 必须完全实现接口中所有方法，否则该接口无法指向该类
func (dog *Dog) Sleep(){
	fmt.Println("dog is sleeping")
}

func (dog *Dog) GetColor() string {
	fmt.Println("dog color is",dog.color)
	return dog.color
}

func (dog *Dog) GetType() string {
	fmt.Println("type is","dog")
	return "dog"
}

// 这个函数既可以狗也可以猫
func showanimal(animal AnimalIF){
	fmt.Println("--------show--------")
	animal.Sleep()
	fmt.Println("type",animal.GetType())
	fmt.Println("color",animal.GetColor())
}



func main()  {
	var animal AnimalIF //接口类型，就是父类的指针
	animal = &Cat{"green"}
	// 下边这句调用的就是cat的get_color
	animal.GetColor()

	animal = &Dog{"red"}
	// 下边这局是dog的个get_color
	animal.GetColor()

	fmt.Println("----------------------------------")

	cat1:=Cat{"black"}
	dog1:=Dog{"white"}

	// 这里记的是传地址
	showanimal(&cat1)
	showanimal(&dog1)
}