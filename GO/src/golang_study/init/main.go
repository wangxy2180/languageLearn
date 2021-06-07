package main

// 一般每个包都会有一个单独的文件夹
// 它默认会从GOROOT或者GOPATH的根目录下下寻找这两个lib，显然是找不到的
// import (
// 	"lib1"
// 	"lib2"
// )

// 导入的包必须使用他的API!否则会报错
// 如果只想使用init方法,不想使用他的对外接口,在前边加一个下划线_就可以，匿名别名
// 也可以起一个具名别名，然后就只能使用别名了
import (
	_ "golang_study/init/lib1"
	mylib2 "golang_study/init/lib2"
	// 如果使用下边这样的方法，就可以不用lib2.Lib2_test，可以直接调用Lib2_test()(不要轻易使用！！！)
	// . "golang_study/init/lib2"
)

func main(){
	// 可以看出他依然调用了init方法
	// lib1.Lib1_test()
	// lib2.Lib2_test()
	mylib2.Lib2_test()
	// 可以看出他是优先调用了init函数

}