def auto_print(func):
    # 注意，这里的*和**代表的是打包，就是将位置参数打包成元组，关键字参数打包为字典
    # 这样就不需要关心他的具体参数都有什么了
    def inner(*args, **kwargs):
        print("--- auto print start ---") 
        # 这里对他们两个解包，将位置参数和关键字参数放在该有的位置桑
        func(*args, **kwargs)
        print("--- auto print end   ---") 
        # 返回值的处理方式，inner要在这里return
        # return
    return inner

@auto_print
def print_num(num):
    for i in range(num):
        print(i,end='')
    print()

@auto_print
def print_str(str1,str2):
    print(str1)
    print(str2)

print_num(10)
print_str("decorator","dddddddd")
print('-------------')



def auto_print2(func):
    # 注意，这里的*和**代表的是打包，就是将位置参数打包成元组，关键字参数打包为字典
    # 这样就不需要关心他的具体参数都有什么了
    def inner(*args, **kwargs):
        print("--- auto print start2 ---") 
        # 这里对他们两个解包，将位置参数和关键字参数放在该有的位置桑
        func(*args, **kwargs)
        print("--- auto print end  2 ---") 
        # 返回值的处理方式，inner要在这里return
        # return
    return inner
# 多个装饰器其中2离这个函数最近，会先warp，然后被1warp，也就是说1warp的是已经带装饰器的函数
@auto_print
@auto_print2
def print_out():
    print("print_out")
print_out()


# -------------------------