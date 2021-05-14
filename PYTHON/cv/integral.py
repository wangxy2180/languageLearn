import cv2
import numpy as np
#
#计算积分图
#
def integral(img):
    integ_graph = np.zeros((img.shape[0],img.shape[1]),dtype = np.int32)
    for x in range(img.shape[0]):
        sum_clo = 0
        for y in range(img.shape[1]):
            sum_clo = sum_clo + img[x][y]
            integ_graph[x][y] = integ_graph[x-1][y] + sum_clo
    return integ_graph

if __name__=='__main__':
    img = cv2.imread('test_pic_gray.jpg',cv2.IMREAD_GRAYSCALE)
    cv2.imshow('src', img)
    # 计算积分图
    # sum = np.zeros((720+1, 960+1), np.float32)
    integ_graph_1=cv2.integral(img)
    result = np.zeros((720+1 , 960+1 ), dtype=np.uint8)
    cv2.normalize(integ_graph_1,result,0,255,cv2.NORM_MINMAX,cv2.CV_8UC1)
    cv2.imshow('integ_1',result)

    integ_graph_2=integral(img)
    # 归一化,方便显示.    # 转为8位int类型
    result = np.zeros((720 , 960 ), dtype=np.uint8)
    cv2.normalize(integ_graph_2,result,0,255,cv2.NORM_MINMAX,cv2.CV_8UC1)
    cv2.imshow('integ_2',result)

    cv2.waitKey(3000)
    cv2.destroyAllWindows()




