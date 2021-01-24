
侯捷：类的设计准则

1. 数据放在peivate
2. 参数尽可能传reference，是否要const需要看情况
3. 返回值尽量reference，注意局部变量不能用
4. 类的本体中的需要加const的函数，一定要加
5. 使用构造函数的初始化列表


只要你的类带有指针，就一定要写拷贝构造和拷贝赋值函数！！！还有析构函数，这三个叫做big three，三个特殊函数


## 堆(heap) 和 栈(stack)
1. stack:是存在于某个作用域(scope)中的一块内存空间，当你调用函数时，函数本身就会形成一个栈来存放所接收的参数以及返回地址，在函数体内部声明的任何变量，内存均在stack上
   
2. heap:是操作系统提供的一块**全局**内存空间，用new动态取得

```c++
{
    Complex c1(1,2);
    static Complex c2(1,2);
    Complex* p = new Complex(3);
    delete p;
}
```
- c1所占用的空间来自stack，离开scope后他的生命周期就结束了，会自动调用析构函数，这样的被叫做 local object 或者 auto object 因为他会被“自动”清理
  - static object:其生命在作用域结束后仍然存在，直到整个程序结束，如c2
- p占用的空间来自heap，你必须手动delete掉,delete后他的生命周期就结束了。如果不delete就会出现内存泄漏（你对这一块内存失去了控制），因为在离开作用域后，p这个指针就死亡了，但是内存空间仍然存在。
- 全局对象：在任何作用域之外，生命周期是整个程序的生命周期，程序结束才结束，你可以把它看作是static的，只不过他的作用域是整个程序

- 当你new的时候，先分类内存，再调用构造函数
```c++
Complex* pc = new Complex(1,2);
这一行代码被编译器转换为了三件事
void* mem = operator new(sizeof(Complex));   //分配内存，调用malloc(n)
pc = static_cast<Complex*>(mem); //转型，把void*转为Complex*
pc->Complex::complex(1,2); //构造函数
成员函数，一定有this pointor，谁调用，谁就是this，pc就是内存的起始位置
其实就是下边这行
Complex::Complex(pc,1,2);
```

- 当你delete时，先调用析构函数，再释放内存
```c++
Complex* pc = new Complex(1,2);
...
delete pc;
这局delete被转化为两个动作
Complex::~COmplex(pc);     //析构函数
operator delete(pc);    //释放内存，调用free(pc)
```


## delete和delete[]
new[] 要搭配 delete[]，叫做array new搭配array delete

![arrayNewDel](https://gitee.com/wangxy2180/imagehost/raw/master/codingTech/arrayNewDelete.png)

因为这样编译器才知道要调用多次析构函数

- 左边的调用了三次析构函数，释放了三个指针所申请的内存，因为你告诉了编译器你要删除的是一个数组
- 右边的调用了一次析构函数，仅释放了第一个指针所申请的内存
- **也就是说，内存泄漏，泄露的是对象中的指针所申请的内存中，并不是这个对象泄露了，不会影响21h那一块的删除**

[这篇博客讲的不错](https://blog.csdn.net/u012936940/article/details/80919880)