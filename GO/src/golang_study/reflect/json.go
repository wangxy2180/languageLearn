package main

import (
	"fmt"
	"encoding/json"
)

// 如果你想转换为json，就必须定义为json，后边的就是这个字段在json中显示的内容
type Movie struct{
	Title string	`json:"title"`
	Year int	`json:"year"`
	Price int	`json:"rmb"`
	Actors []string	`json:"actors"`
}

// 结构体标签在json中的应用
func main()  {
	movie := Movie{"喜剧之王",2000,10,[]string{"星爷","张柏芝"}}

	// 编码过程，结构体转json
	jsonStr,err:=json.Marshal(movie)
	if err!=nil{
		fmt.Println("json marshal err",err)
		return
	}

	fmt.Printf("jsonStr=%s\n",jsonStr)

	fmt.Println("---------------------------------")
	// json 转结构体
	// jsonStr={"title":"喜剧之王","year":2000,"rmb":10,"actors":["星爷","张柏芝"]}
	my_movie:=Movie{}
	err = json.Unmarshal(jsonStr, &my_movie)
	if err!=nil{
		fmt.Println("json unmaeshal failed")
		return 
	}
	fmt.Printf("%v\n",my_movie)

}