a=3

def main():
    global a
    print(a)
    # 如果没有global，这句话会报错，有了global才能进行修改，反之只能访问
    a=7
    print(a)

if __name__=='__main__':
    main()
    print(a)
    # 输出为3 7 7