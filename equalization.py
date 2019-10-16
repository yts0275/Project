import cv2
import numpy as np
import matplotlib as mpl
from matplotlib import pyplot as plt

def equalization():
    img = cv2.imread("lena.png", cv2.IMREAD_GRAYSCALE)
    dst = cv2.equalizeHist(img)

    hs = np.hstack((img, dst))
    cv2.imwrite("./save/equalization.jpg", hs)
