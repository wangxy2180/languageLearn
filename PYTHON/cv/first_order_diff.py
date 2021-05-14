import cv2
import numpy as np

def sobel_opencv(img):

    cv2.waitKey(2000)
    cv2.destroyAllWindows()
    # 这张图位深度是3*8=24，如果转为灰度，那位深度就是8
    # dx dy 一般为0 1或2，0就表示在这个方向上没有倒数
    img2 = cv2.Sobel(img,cv2.CV_32F,1,1)
    cv2.imshow('test2',img2)
    cv2.waitKey(3000)
    cv2.destroyAllWindows()

# 查看位深度
def to_gray(img):
    img_out = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)
    cv2.imshow('test',img_out)
    cv2.imwrite('test_pic_gray.jpg',img_out)
    cv2.waitKey(1000)
    cv2.destroyAllWindows()

def first_order_diff(img):
    # img_pad =
    img_out_x = np.zeros((img.shape[0],img.shape[1]),dtype=np.uint8)
    img_out_y = np.zeros((img.shape[0],img.shape[1]),dtype=np.uint8)
    # cv2.imshow("black", img_out)
    # 列与列之间相减
    img = np.array(img)
    for i in range(1,img.shape[0]):
        for j in range(1,img.shape[1]):
            img_out_y[i][j]=int(img[i][j][0])-int(img[i][j-1][0])
    cv2.imshow("diff in y, v_line",img_out_y)

    # 行与行之间相减
    for i in range(1,img.shape[0]):
        for j in range(1,img.shape[1]):
            img_out_x[i][j]=int(img[i][j][0])-int(img[i-1][j][0])
    cv2.imshow("diff in x, h_line",img_out_x)


if __name__=="__main__":
    img = cv2.imread('test_pic_gray.jpg')
    cv2.imshow('src',img)
    # sobel_opencv(img)
    first_order_diff(img)

    cv2.waitKey(30000)
    cv2.destroyAllWindows()
