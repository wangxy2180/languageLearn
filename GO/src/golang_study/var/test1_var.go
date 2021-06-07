package main
// 四种变量声明方式
import "fmt"

// 声明全局变量，方法123
var gA int = 11
// 使用方法四是不可以的 :=只能用在函数体内
// gC := 123

func main() {
	// 1.声明单个变量，不做初始化，默认的值是0
	var a int
	fmt.Println("a =",a)


	// 2.声明一个变量，初始化一个值
	var b int = 100
	fmt.Println("b =",b)
	fmt.Printf("type of b = %T\n",b)

	// 3.在初始化的时候可以省去数据类型说明，通过值自动匹配当前的数据类型(不推荐)
	var c = 1000
	fmt.Println("c =",c)
	fmt.Printf("type of c = %T\n",c)

	// 4.（常用）省去var，直接自动匹配数据类型
	e := "string"
	fmt.Println("e =",e)
	fmt.Printf("type of e = %T\n",e)

	f := 3.14
	fmt.Println("e =",f)
	fmt.Printf("type of e = %T\n",f)

	fmt.Println("gA =",gA)
	fmt.Printf("type of gA = %T\n",gA)

	// 声明多个变量
	var xx,yy int = 101,202
	fmt.Println("xx =",xx,"yy =",yy)

	var kk,ll  = 102,"string"
	fmt.Println("kk =",kk,"ll =",ll)

	// 多行多变量声明
	var(
		vv int = 103
		jj bool = false
	)
	fmt.Println("vv =",vv,"jj =",jj)


}