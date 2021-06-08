package main

import "fmt"

func main(){
	// 数据类型，长度和容量
	// 容量表示底层一次性开辟的存储空间的单位
	var nums = make([]int,3,5)
	fmt.Printf("len=%d,cap=%d,slice=%v\n",len(nums),cap(nums),nums)

	// 向nums追加元素1，nums的len = 4 [0,0,0,1] cap=5
	nums = append(nums,1)
	fmt.Printf("len=%d,cap=%d,slice=%v\n",len(nums),cap(nums),nums)
	
	// 向nums追加元素2，nums的len = 5 [0,0,0,1,2] cap=5
	nums = append(nums,2)
	fmt.Printf("len=%d,cap=%d,slice=%v\n",len(nums),cap(nums),nums)

	// 此时cap已经被占满了，我们继续追加，显然此时已经没有位置了，但是go语言会继续开辟cap的容量
	// 向nums追加元素3，nums的len =6  [0,0,0,1,2，3] cap=10
	nums = append(nums,2)
	fmt.Printf("len=%d,cap=%d,slice=%v\n",len(nums),cap(nums),nums)

	fmt.Println("---------------------------")
	// 如果没有指定容量大小，那么他会认为你的len就是容量
	var nums2 = make([]int,3)
	fmt.Printf("len=%d,cap=%d,slice=%v\n",len(nums2),cap(nums2),nums2)
	// nums2.append(33) 这样的写法是错误的
	nums2 = append(nums2,333)
	fmt.Printf("len=%d,cap=%d,slice=%v\n",len(nums2),cap(nums2),nums2)


}