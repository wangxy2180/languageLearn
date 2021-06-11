package main

import (
	"fmt"
	"reflect"
)

// 标签为`key-value`格式，使用``包含，可以写多个
// 主要作用是判断属性在包里具体如何使用

type resume struct{
	Name string `info:"name" doc:"我的名字"`
	Sex string `info:"sex"`
}

func find_tag(str interface{})  {
	// 当前结构体全部元素
	t:= reflect.TypeOf(str).Elem()

	for i := 0; i < t.NumField(); i++ {
		tag_info:=t.Field(i).Tag.Get("info")
		tag_doc:=t.Field(i).Tag.Get("doc")
		fmt.Println("info: ",tag_info,"doc: ",tag_doc)
	}
	
}

func main()  {
	var re resume
	// 这里要注意传地址
	find_tag(&re)
}