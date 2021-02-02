
## 复合 Composition
has-a 我里边有另外一种东西

比如标准库中的`queue`，可以看出`queue`是默认利用`deque`完成的。这只是一种特例，自己没做任何事情，完全满足`queue`需要的功能

这也表现出一种设计模式，叫做`Adapter`，就是已经有一个很好的了，客户想要另一个东西，现有的完全满足，但是名称完全不一样，我们就改造一下`queue`就是`Adapter`

![原始](https://gitee.com/wangxy2180/imagehost/raw/master/codingTech/composition_1.jpg)

我们替换一下，他就是这样的。一个实心菱形表示`queue`中有`deque`

![替换](https://gitee.com/wangxy2180/imagehost/raw/master/codingTech/composition_2.jpg)

- 构造和析构函数关系
  - 会先调用包含的那个类的**默认**构造函数，然后才执行自己；也就是说由内而外构造；如果默认的构造函数不满足你的需求，你就需要自己在初始化列表中手动调用内部的那个构造函数
  - 析构则是先执行自己，然后执行内部 Component的析构
  - 当然，以上两个部分不需要我们自己去写


## 委托 Delegation (Composition by reference)
可以理解为has-a，但是这个"has"是通过指针实现的

用指针指向一个类，和复合的区别在于，复合是直接存储了这个类，而委托则是用指针指向这个类

复合关系，在创建时就创建了它所包含的那个类；而委托关系只是创建了这个类的指针，在需要时再创建这个类的对象


## 继承 Inheritance
is-a
```
class A : public B
{};
```
A使用public继承自B，表示is-a

- 继承和虚函数搭配才是最有价值的


## 虚函数
如果你的class是一个父类，那么他的析构函数必须是`virtual`的，否则会`undefine behavior`

只要在成员函数之前加上`virtual`关键字，他就是个虚函数

数据的继承应该从内存的角度理解，但是函数的继承，继承的是**调用权**；

- 非虚函数：不希望子类(derived class)重新定义(override)它
- 虚函数：希望派生类重新定义它，并且已经有默认的定义；
- 纯虚函数：希望子类一定要重新定义，不可以不定义，因为父类根本没有定义；

![](https://gitee.com/wangxy2180/imagehost/raw/master/codingTech/virtualfunc.jpg)

执行步骤中，按照灰色的线的顺序，会先按父类执行函数，然后发现子类有实现这个函数，他在跑到子类去执行子类的函数

![](https://gitee.com/wangxy2180/imagehost/raw/master/codingTech/inheritanceWithVirtual.jpg)

一种常见的用法，即**MVC**

![](https://gitee.com/wangxy2180/imagehost/raw/master/codingTech/MVC.jpg)


## override overload
一个是重载(overload)，一个是重写(override)
- overload：同一个类中存在多个同名函数，只要参数列表不一样就可以重载
- override：子类重写父类方法