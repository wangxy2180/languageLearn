package main

import "fmt"

func main()  {
	// 定义一个channel（无缓冲）
	c:=make(chan int)

	go func(){
		for i:=0;i<5;i++{
			c <-i
		}

		// close关闭channel
		// 如果不退出
		// fatal error: all goroutines are asleep - deadlock!
		close(c)
	}()

	// for{
	// 	// ok为true,表示channel没有关闭，false表示已经关闭
	// 	// 先执行第一个表达式，然后得到ok，然后判断ok
	// 	if data, ok := <-c; ok{
	// 		fmt.Println(data)
	// 	} else {
	// 		break
	// 	}
	// }

	// 尝试从c读数据，range会阻塞的等待数据
	// 使用range不断迭代操作channel
	for data:=range c{
		fmt.Println(data)
	}
	fmt.Println("main finished")

}