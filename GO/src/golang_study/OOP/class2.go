package main
// 继承

import "fmt"

type Human struct{
	name string
	sex string
}

func (man *Human) Eat(){
	fmt.Println("Eating....")
}


func (man *Human) Walk(){
	fmt.Println("Walking....")
}

// 继承
// 其实在go中不叫继承，叫做组合
type Superman struct{
	Human  //表示superman继承了Human类的属性
	level int
}

// 重定义父类
func (sman *Superman) Eat(){
	fmt.Println("Superman is Eating")
}

// 子类的新方法
func (sman *Superman) fly(){
	fmt.Println("superman is flying")
}

func main() {

	h:=Human{"zhangsan","male"}
	h.Eat()
	h.Walk()

	fmt.Println("---------------------------")

	s:=Superman{Human{"superman","male"},1}
	fmt.Println(s)
	s.Eat()
	s.fly()

	fmt.Println("---------------------------")

	var s2 Superman
	s2.name = "sisi"
	s2.sex = "female"
	s2.level = 88
	fmt.Println(s2)
	s2.Eat()
	s2.fly()
}