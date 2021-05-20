# https://zhuanlan.zhihu.com/p/54833132
from sklearn.cluster import DBSCAN
from sklearn import datasets
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

iris = datasets.load_iris()
# print(iris)
# X = iris.data[:, :4] # #表示我们取特征空间中的4个维度
# print(X)

# 我的随机数据集
np.random.seed(2332)
b=np.random.uniform(0,2,(200,2))
a=np.random.uniform(-2,2,(100,2))
X=np.vstack((a,b))

# 构造聚类器
clu=DBSCAN(eps=0.6,min_samples=10)
clu.fit(X)

core_samples_mask = np.zeros_like(clu.labels_, dtype=bool)  # 设置一个样本个数长度的全false向量
core_samples_mask[clu.core_sample_indices_] = True #将核心样本部分设置为true
label_pred=clu.labels_

unique_labels = set(label_pred)
colors = [plt.cm.Spectral(each) for each in np.linspace(0, 1, len(unique_labels))]

plt.figure(figsize=(10,6))
for k, col in zip(unique_labels, colors):
    if k == -1:  # 聚类结果为-1的样本为离散点
        # 使用黑色绘制离散点
        col = [0, 0, 0, 1]

    class_member_mask = (label_pred == k)  # 将所有属于该聚类的样本位置置为true

    xy = X[class_member_mask & core_samples_mask]  # 将所有属于该类的核心样本取出，使用大图标绘制
    plt.plot(xy[:, 0], xy[:, 1], 'o', markerfacecolor=tuple(col),markeredgecolor='k', markersize=14)

    xy = X[class_member_mask & ~core_samples_mask]  # 将所有属于该类的非核心样本取出，使用小图标绘制
    plt.plot(xy[:, 0], xy[:, 1], 'o', markerfacecolor=tuple(col),markeredgecolor='k', markersize=6)

# plt.title('Estimated number of clusters: %d' % n_clusters_)
sns.despine()
plt.show()

print(11111)