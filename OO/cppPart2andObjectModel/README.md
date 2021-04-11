
目录
![](https://gitee.com/wangxy2180/imagehost/raw/master/codingTech/cpp_2menu.png)

## 智能指针的一些事（Pointer like class，让一个类像一个指针）
迭代器也是一种智能指针

![](https://gitee.com/wangxy2180/imagehost/raw/master/codingTech/shared_ptr.png)


```c++
T* operator->()const
{return px}
```
这里会有一个疑问，上边的这个`->`符号，在`sp->`这里已经被消耗掉了啊，后续`px`怎么还能使用`->`呢
因为有一个特殊的机制，就是他作用下去得到的结果，`->`符号还会继续作用下去，因为这样子解释才解释的通

## 仿函数（让一个类像一个函数）
如果`class`有重载`()`，那么他就是想变成一个函数，就叫做函数对象

## 模板
三大类，class template, function template, member template


## 模板特化
- 泛化：你需要时指定我就好了
- 特化：作为设计者，某些独特的类型要做特殊的设计