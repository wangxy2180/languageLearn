import argparse

# 这个action很好理解，对于其他参数，你需要用制定参数名和参数值
# 但是对于这样的布尔类型参数，只要加上参数名，他就会自动按照store的值进行赋值
parser = argparse.ArgumentParser()
parser.add_argument('--isTest',action="store_true",default=False)
# parser.add_argument('--isTest',action="store_false",default=False)
args = parser.parse_args()
print(args.isTest)


# $ python3 action.py 
# False
# $ python3 action.py --isTest
# True