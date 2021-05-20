from sklearn.cluster import DBSCAN
from sklearn import datasets
import matplotlib.pyplot as plt
import numpy as np


def get_dataset():
    # 我的随机数据集
    # np.random.seed(2332)
    # b = np.random.uniform(0, 100, (200, 2))
    # a = np.random.uniform(-100, 100, (100, 2))
    # X = np.vstack((a, b))

    # (y-50)^2+(x-50)^2=900 O(50,50) x(20,80)
    # (y+50)^2+(x+50)^2=400 O(-50,-50) x(-30,-70)
    # 下边设置圆心，半径，以及x的个数
    # center of circle
    coc_1 = (10, 10)
    coc_2 = (-50, -50)
    radius_1 = 30
    radius_2 = 20
    x_cnt = 100

    np.random.seed(2332)
    noise = [np.random.random() * 5 for _ in range(x_cnt)]

    x_1 = np.linspace(coc_1[0] - radius_1, coc_1[0] + radius_1, x_cnt)
    y_1 = [np.sqrt(radius_1 ** 2 - np.power(x_1[i] - coc_1[0], 2)) + coc_1[1] + noise[i] for i in range(x_cnt)]

    x_2 = np.linspace(coc_2[0] - radius_2, coc_2[0] + radius_2, x_cnt)
    y_2 = np.sqrt((radius_2 ** 2 - np.power(x_2 - coc_2[0], 2))) + coc_2[1] + noise

    Discrete_point = np.random.uniform(-100,100,(300,2))

    C = []
    for i in range(x_cnt):
        C.append([x_1[i], y_1[i]])
        C.append([x_1[i], -y_1[i] + 2*coc_1[0]])
        C.append([x_2[i], y_2[i]])
        C.append([x_2[i], -y_2[i] + 2*coc_2[0]])
    C = np.array(C)
    C=np.vstack((C,Discrete_point))

    # 下边这两句是画原始图用的
    plt.xlim(-100,100)
    plt.ylim(-100,100)
    plt.figure(figsize=(5, 5))
    plt.scatter(C[:,0],C[:,1],color='k',s=10)
    # plt.savefig('scatter.png')
    return C

def get_move_dataset():

    # center of circle
    # coc_1=(17,19)
    # coc_2=(-60,-58)
    coc_1 = (25, 28)
    coc_2 = (-71, -71)
    radius_1 = 30
    radius_2 = 20
    x_cnt = 100

    # 2332 2333 2334
    np.random.seed(2333)
    noise = [np.random.random() * 3 for _ in range(x_cnt)]

    x_1 = np.linspace(coc_1[0] - radius_1, coc_1[0] + radius_1, x_cnt)
    y_1 = [np.sqrt(radius_1 ** 2 - np.power(x_1[i] - coc_1[0], 2)) + coc_1[1] + noise[i] for i in range(x_cnt)]

    x_2 = np.linspace(coc_2[0] - radius_2, coc_2[0] + radius_2, x_cnt)
    y_2 = np.sqrt((radius_2 ** 2 - np.power(x_2 - coc_2[0], 2))) + coc_2[1] + noise

    Discrete_point = np.random.uniform(-100, 100, (300, 2))

    C = []
    for i in range(x_cnt):
        C.append([x_1[i], y_1[i]])
        C.append([x_1[i], -y_1[i] + 2 * coc_1[0]])
        C.append([x_2[i], y_2[i]])
        C.append([x_2[i], -y_2[i] + 2 * coc_2[0]])
    C = np.array(C)
    C = np.vstack((C, Discrete_point))

    # 下边这两句是画原始图用的
    plt.figure(figsize=(5, 5))
    plt.xlim(-100,100)
    plt.ylim(-100,100)
    plt.scatter(C[:,0],C[:,1],color='k',s=10)

    # 第一到第二
    # x的序列，y的序列
    # x12 = [[10, 17],[-50,-60]]  # 要连接的点的x坐标序列
    # y12 = [[10, 19],[-50,-58]]  # 要连接的点的y坐标序列
    # for i in range(len(x12)):
    #     plt.plot(x12[i], y12[i], color='r')
    #     # col_= 'r' if i==0 else 'g'
    #     plt.scatter(x12[i][0], y12[i][0], color='r')
    #     plt.scatter(x12[i][1], y12[i][1], color='b')

    # 第一到第二到第三
    # y_1_new = np.mean(y_1)
    # y_2_new = np.mean(y_2)
    # print(y_1_new,y_2_new)
    x123 = [[10, 17, 25],[-50,-60,-71]]  # 要连接的点的x坐标序列
    y123 = [[10, 19, 28],[-50,-58,-71]]  # 要连接的点的y坐标序列
    for i in range(len(x123)):
        plt.plot(x123[i], y123[i], color='r')
        plt.scatter(x123[i][0], y123[i][0], color='r')
        plt.scatter(x123[i][1], y123[i][1], color='r')
        plt.scatter(x123[i][2], y123[i][2], color='b')
    # plt.savefig('afterafter.png')
    return C


#
def db(X):
    # # 构造聚类器
    clu = DBSCAN(eps=10, min_samples=10)
    clu.fit(X)

    core_samples_mask = np.zeros_like(clu.labels_, dtype=bool)  # 设置一个样本个数长度的全false向量
    core_samples_mask[clu.core_sample_indices_] = True  # 将核心样本部分设置为true
    label_pred = clu.labels_

    unique_labels = set(label_pred)
    colors = [plt.cm.Spectral(each) for each in np.linspace(0, 1, len(unique_labels))]

    # colors和unique_labels都是set
    plt.figure(figsize=(5, 5))
    plt.xlim(-100,100)
    plt.ylim(-100,100)
    for k, col in zip(unique_labels, colors):
        if k == -1:  # 聚类结果为-1的样本为离散点
            # 使用白色绘制离散点
            # 前三个是填充颜色，最后一个是啥呢？透明度？
            col = [0, 1, 0, 1]

        class_member_mask = (label_pred == k)  # 将所有属于该聚类的样本位置置为true

        xy = X[class_member_mask & core_samples_mask]  # 将所有属于该类的核心样本取出，使用大图标绘制
        plt.plot(xy[:, 0], xy[:, 1], 'o', markerfacecolor=tuple(col), markeredgecolor='k', markersize=6)

        xy = X[class_member_mask & ~core_samples_mask]  # 将所有属于该类的非核心样本取出，使用小图标绘制
        plt.plot(xy[:, 0], xy[:, 1], 'o', markerfacecolor=tuple(col), markeredgecolor='k', markersize=3)

def move_OF(move_dataset):
    plt.figure(figsize=(5, 5))
    plt.scatter(move_dataset[:,0],move_dataset[:,1],color='k',s=10)

if __name__ == "__main__":
    # clu_dataset = get_dataset()


    # db(clu_dataset)

    move_dataset = get_move_dataset()
    # move_OF(move_dataset)

    plt.show()
print(11111)
