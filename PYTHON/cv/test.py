import numpy as np
import cv2

img = cv2.imread("test_pic.jpg",0)  # 读取图片

# Initiate FAST object with default values
fast = cv2.FastFeatureDetector_create()  # 实例化fast
# find and draw the keypoints
kp = fast.detect(img, None)  # 找出图片中的关键点
img2 = cv2.drawKeypoints(img, kp, None, color=(255, 0, 0))  # 画出检测出来的点

cv2.imshow('fast.png', img2)  # 显示图片
cv2.waitKey(0)
