import cv2
import numpy as np
import copy

# detector parameters
block_size = 5
sobel_size = 3
k = 0.04





def harris(image):
    # image2=np.zeros((image.shape[0],image.shape[1]))
    image2 = copy.deepcopy(image)

    gray_img = cv2.cvtColor(image2, cv2.COLOR_BGR2GRAY)
    # modify the data type setting to 32-bit floating point
    gray_img = np.float32(gray_img)

    # detect the corners with appropriate values as input parameters
    corners_img = cv2.cornerHarris(gray_img, block_size, sobel_size, k)

    # result is dilated for marking the corners, not necessary
    dst = cv2.dilate(corners_img, None)


    # Threshold for an optimal value, marking the corners in Green
    image2[corners_img > 0.01 * corners_img.max()] = [0, 0, 255]

    # cv2.imwrite('new_bird.jpg', image)
    cv2.imshow("harris", image2)

def shi_tomasi(image):
    image2=copy.deepcopy(image)
    maxCorners = 100
    qualityLevel = 0.01
    minDistance = 10
    gray = cv2.cvtColor(image2, cv2.COLOR_BGR2GRAY)
    corners = cv2.goodFeaturesToTrack(gray, 0, qualityLevel, minDistance)

    corners = np.int0(corners)
    for i in corners:
        x, y = i.ravel()
        cv2.circle(image2, (x, y), 2, (0, 0, 255), -1)
    cv2.imshow("shi_tomasi", image2)

def fast_detect(image):
    image2=copy.deepcopy(image)
    fast = cv2.FastFeatureDetector_create()
    fast.setNonmaxSuppression(0)
    key_point = fast.detect(image2)
    image2=cv2.drawKeypoints(image2,key_point,None,(255,0,0))
    cv2.imshow("fast2",image2)

if __name__=="__main__":
    image = cv2.imread('test_pic.jpg')
    harris(image)
    # cv2.imshow("image",image)

    fast_detect(image)

    shi_tomasi(image)

    cv2.waitKey(30000)
    cv2.destroyAllWindows()
