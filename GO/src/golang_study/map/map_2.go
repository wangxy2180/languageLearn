package main

import "fmt"

func print_map(my_map map[string]string){
	// 这里是引用传递！！！
	for key,value := range(my_map){
		fmt.Printf("country:%s,city:%s\n",key,value)
	}
	my_map["USA"]="BBBBB"
}

func add_map(my_map map[string]string){
	my_map["addit"]="asdasdasd"

}

func main(){
	city_map:=make(map[string]string)

	// 添加key value
	city_map["china"]="beijing"
	city_map["japan"]="tokyo"
	city_map["USA"]="NYC"

	for key,value := range(city_map){
		fmt.Printf("country:%s,city:%s\n",key,value)
	}

	// map的删改
	delete(city_map,"china")
	city_map["USA"]="AAAA"

	
	fmt.Println("------------------------")

	print_map(city_map)

	add_map(city_map)

	// 可以看出，print_map对数据进行了修改
	fmt.Println("------------------------")
	for key,value := range(city_map){
		fmt.Printf("country:%s,city:%s\n",key,value)
	}
}