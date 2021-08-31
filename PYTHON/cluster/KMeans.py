from sklearn.cluster import KMeans
from sklearn import datasets
import matplotlib.pyplot as plt
import numpy as np

iris = datasets.load_iris()
# print(iris)
X = iris.data[:, :4] # #表示我们取特征空间中的4个维度
# print(X)

# 构造聚类器
clu=KMeans(n_clusters=3)
clu.fit(X)
label_pred=clu.labels_

x0=X[label_pred==0]
x1=X[label_pred==1]
x2=X[label_pred==2]

plt.scatter(x0[:,0],x0[:,1],c='red',marker='o',label='label0')
plt.scatter(x1[:,0],x1[:,1],c='blue',marker='*',label='label1')
plt.scatter(x2[:,0],x2[:,1],c='green',marker='+',label='label2')