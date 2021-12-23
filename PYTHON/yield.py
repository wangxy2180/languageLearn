def make_group(input_ls,group_size):
    group=[]
    for k in input_ls:
        group.append(k)
        if len(group)==group_size:
            yield tuple(group)
            group=group[1:]

def main():
    input_ls=[1,2,3,4,5,6,7,8,9]
    # 无法直接调用，下边这样是不会返回的，必须通过迭代器（循环）访问
    print(make_group(input_ls,2))
    
    for kk in make_group(input_ls,2):
        print(kk)



if __name__=="__main__":
    main()