package main

import "fmt"

// 如果类名首字母大写，其他包就能访问
// 如果属性首字母大写，则表明其他包可以访问，反之只能类内访问
type Hero struct{
	Name string
	Ad int
	level int
}

// 下边的写法是有问题的！！！见下方
/*
func (this Hero) show(){
	fmt.Println(this)
}

// 他的方法这么写,括号表示绑定了哪个类
func (this Hero) get_name() string {
	fmt.Println("get name is", this.Name)
	return this.Name
}

func (this Hero) set_name(name string) {
	// 当前this是调用该方法的对象的一个副本
	// set操作会出现问题
	this.Name = name
	fmt.Println("set name is",name)
}
*/

// 注意，（）中的this并不是关键字，而是一个声明，因此可以任意更换字母
func (heros *Hero) show(){
	fmt.Println(heros)
}

// 他的方法这么写,括号表示绑定了哪个类
func (hhh *Hero) get_name() string {
	fmt.Println("get name is", hhh.Name)
	return hhh.Name
}

func (qqq *Hero) set_name(name string) {
	// 当前this是调用该方法的对象的一个副本
	// set操作会出现问题
	qqq.Name = name
	fmt.Println("set name is",name)
}

func main(){
	// 创建对象的方式
	// var hero1 Hero
	// hero1 := Hero{"zhangsan",10,10}
	hero1 := Hero{Name : "zhangsan" , Ad : 10 , level : 10}
	hero1.show()
	hero1.set_name("aaaa")
	hero1.show()

	hero1.get_name()

}