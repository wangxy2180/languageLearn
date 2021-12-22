class CLASS_A(object):

    # 属性默认为类属性（可以给直接被类本身调用）
    num = "类属性"

    # 实例化方法（必须实例化类之后才能被调用）
    def func1(self): # self : 表示实例化类后的地址id
        print("func1")
        print(self) # 输出“<__main__.CLASS_A object at 0x7f256932bda0>”

    # 类方法（不需要实例化类就可以被类本身调用）
    @classmethod
    def func2(cls):  # cls : 表示没用被实例化的类本身，可以认为就是CLASS_A
        print("func2") 
        print(cls) #输出<class '__main__.CLASS_A'>
        print(cls.num) #输出“类属性”
        cls().func1()

    # 不传递传递默认self参数的方法（该方法也是可以直接被类调用的，但是这样做不标准）
    def func3():
        print("func3")
        print(CLASS_A.num) # 属性是可以直接用类本身调用的
    
# A.func1() 这样调用是会报错：因为func1()调用时需要默认传递实例化类后的地址id参数，如果不实例化类是无法调用的
CLASS_A.func2()
CLASS_A.func3()