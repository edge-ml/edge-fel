from numpy import random
import csv

random.seed(1)
x = random.uniform(-4, 4, size=(1000))

with open('data_1k.csv', 'w', encoding='UTF8') as f:
    writer = csv.writer(f)
    low = 0
    high = 100
    for i in range(100):
        sub = x[low:high]
        writer.writerow(sub)
        low = high
        high += 100
        
