import numpy as np
import matplotlib.pyplot as plt
import os
import cv2
import random
import pickle

IMG_SIZE = 64
DATADIR = "./img"

training_data = []

def create_training_data():
    for root, dirs, files in os.walk(DATADIR):
        for img in files:
            try:
                img_array = cv2.imread(os.path.join(root, img), cv2.IMREAD_GRAYSCALE)
                new_array = cv2.resize(img_array, (IMG_SIZE, IMG_SIZE))
                training_data.append(new_array)
            except Exception as e:
                pass

create_training_data()

img = training_data[0]

for i in img:
	print("[", end = '')
	for j in i:
		print(j, end = '')
		print(', ', end = '')
	print("],")


