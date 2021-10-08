# https://mp.weixin.qq.com/s/LvRsXpoC6orN9eULoDqyCA

import torch

# 这个x可以看作是一个卷积核，反向传播是为了看每个参数对最终结果其有多大的影响
x = torch.ones(3,3,requires_grad = True)
# 这个乘法是逐位相乘
t = x * x + 2 
z = 2 * t + 1
# y=7
# 这里的y可以理解为真实值与预测值的误差
y = z.mean()
# 这步平均，就体现在1/9上 y=(1/9)t
print(y)
y.backward()
# tz没有梯度
print('x.grad\n',x.grad)
print('x\n',x)

print('-----------------------------------------')


x = torch.ones(3,3,requires_grad = True)
t = x * x + 2
y = t - 9

v = torch.ones(3,3)
y.backward(v)
print(x.grad)