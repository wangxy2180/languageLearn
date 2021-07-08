'''
Author: your name
Date: 2021-07-08 20:33:17
LastEditTime: 2021-07-08 21:36:25
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: /CTEST/pydraw/SAE.py
https://www.cnblogs.com/112358nizhipeng/p/10175136.html
'''
# 使用方法：
# 将要画的数据分行放入File.txt中，然后修改_x,_y的值使其相匹配
# ！！！！请在与该文件同级目录下运行该程序！！！！

import os
import numpy as np
import matplotlib.pyplot as plt

from mpl_toolkits.mplot3d import Axes3D  # noqa: F401 unused import


cur_path = os.getcwd()
file_name = 'File.txt'

file_path = os.path.join(cur_path,file_name)
print("cur_path is:",file_path)

file = open(file_name)
lines = file.readlines()


# 画布宽长比例
fig = plt.figure(figsize=(10, 5))  
# 设定坐标系1
ax1 = fig.add_subplot(121, projection='3d')
ax1.set_title('SAE')

# fake data
_x = np.arange(-4, 5)
_y = np.arange(-4, 5)
_xx, _yy = np.meshgrid(_x, _y)
x, y = _xx.ravel(), _yy.ravel()#ravel扁平化

# print(lines)
# top：每个柱体的高度
top = []
for line in lines:
    line=eval(line.strip(' \n'))
    top.append(line)

#每个柱的起始位置的值
bottom = np.zeros_like(top)
#x,y方向的宽厚，这个值不建议修改，就是1就行了
width = depth = 1

ax1.bar3d(x, y, bottom, width, depth, top, shade=True)  #x，y为数组

ax1.set_xlabel('X')
ax1.set_ylabel('Y')
ax1.set_zlabel('timestamp diff value')


# 单独画每个柱子，可以给其标上颜色
ax2 = fig.add_subplot(122, projection='3d')
ax2.set_title("colored")

for i in range(1, 10):
    for j in range(1, 10):
        z = top[i*j-1] #该柱的高
        color = np.array([255, 255, z*2550])/255.0#颜色 其中每个元素在0~1之间
        ax2.bar3d(j, i, 0, width, depth, z, color=color)   #每次画一个柱

ax2.set_xlabel('X')
ax2.set_ylabel('Y')
ax2.set_zlabel('pixel value')

# plt.axis('off')
plt.show()