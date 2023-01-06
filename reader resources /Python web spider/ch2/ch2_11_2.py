# ch2_11_2.py
import csv

fn = 'out2_11_1.csv'
with open(fn, 'r', newline='', encoding='utf-8') as csvFile:  # 開啟csv檔案
    rows = csv.reader(csvFile)
    for row in rows:
        print(row)







