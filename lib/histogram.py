import numpy as np
import cv2, os
import matplotlib as mpl
from matplotlib import pyplot as plt

def histogram():
    img = cv2.imread("lena.png", cv2.IMREAD_GRAYSCALE)
    histogram = cv2.calcHist(images = [img], channels=[0], mask=None,
            histSize=[256], ranges=[0, 256])
    mpl.use('Agg')
    plt.title("Histogram")
    plt.xlabel("Intensity")
    plt.ylabel("Pixels")
    plt.xlim([0, 256])
    plt.plot(histogram)

    os.mkdir("./save")

    plt.savefig('./save/histogram.jpg')
