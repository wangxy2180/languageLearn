package main 
//主程序所在的包就是main包，只要包含main函数，那么就是main包，和文件名字没有任何关系


// import "fmt"
// import "time"
// 两种导包方式
import(
	"fmt"
	"time"
)


func main(){
// 注意，语句后边可以有分号，推荐不加分号
	fmt.Println("hello go!")

	time.Sleep(1*time.Second)
}
