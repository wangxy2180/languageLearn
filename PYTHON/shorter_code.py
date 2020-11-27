# 生成式，可以很容易的创建新的列表，字典和集合，可减少行数并提高可读性，可以用作append(),map(),reduce()的替代
# 列表
import numpy as np
num = [i for i in range(0, 50)]
print('num:\n', num)

square_num = [x ** 2 for x in range(0, 40) if x % 2 == 0]
print('square_num\n', square_num)

# 字典
even_square = {x: x ** 2 for x in range(0, 10) if x % 2 == 0}
print('even_square\n', even_square)

country = ['Canada', 'China', 'Tapan', 'America', 'Germany']
counter_2 = {c: c[:2] for c in country}
print('country_2\n', counter_2)

# 集合
import random

rand_num = {random.randint(10, 20) for num in range(25)}
print('rand_num\n', rand_num)

kms = [10, 10, 20, 20, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400]
mile_list = [k / 1.6 for k in kms if k < 100]
mile_dict = {k / 1.6 for k in kms if k < 100}
print('mile_list\n',mile_list)
print('mile_dict\n',mile_dict)

# 生成随机
a=[np.random.random() for _ in range(50)]
print(a)