import csv
l=[1,2,3,45]

with open("test.csv", "w") as f:‘
    csv.writer(f).writerow(l)