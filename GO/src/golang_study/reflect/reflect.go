package main

import (
	"fmt"
	"reflect"
)
func reflect_num(arg interface{}){
	fmt.Println("type:",reflect.TypeOf(arg))
	fmt.Println("value:",reflect.ValueOf(arg))
}

// ----------------------------------------------------

type User struct{
	Id int
	Age int
	Name string
}

func (user User) Call(){
	fmt.Println("User is called....")
	fmt.Printf("%v\n",user)
}

func do_file_method(input interface{}){
	// 获取input的type
	input_type:=reflect.TypeOf(input)
	// 获取input的value
	input_value:=reflect.ValueOf(input)
	fmt.Println("input_type  is",input_type)
	fmt.Println("input_value is",input_value)

	// 通过type获取里边的字段，
	// 1.获取interface的reflect类型，通过type获取字段，进行遍历
	// 2.得到每个数据类型，
	// 3.通过interface方法得到对应的value
	for i:=0;i<input_type.NumField();i++{
		// 获取字段和值
		field:=input_type.Field(i)
		value:=input_value.Field(i).Interface()
		fmt.Printf("%s:%v=%v\n",field.Name,field.Type,value)
	}

	// 再通过type获取里边的方法并调用
	// 这里有个坑，如果你写方法时用的是(user *User)，那么这里是查不到的，他的输出值是0
	fmt.Println(input_type.NumMethod())
	for i := 0; i < input_type.NumMethod(); i++ {
		m:=input_type.Method(i)
		fmt.Printf("%s:%v\n",m.Name,m.Type)
	}

}

func main(){
	var num float64 = 1.2345
	reflect_num(num)
	// -----------------------------
	fmt.Println("-----------------------------------------")



	user:=User{1,2,"wang"}
	do_file_method(user)


}