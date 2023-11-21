import requests
import time
from bs4 import BeautifulSoup
Department_list=[0,1,2,4,5,9,10,11,13,14,17,18,19,21,22,23,24,26,27,30,31,32,33,36,37,38,39,40,41,42,43,44,45,46,48,50,52,54,56,57,59,60,61,62,65,67,68,70,75,81,82,83,85,88,89,90,91,96,99]
map = list()
for Department in Department_list:
    for grade in range(1,7):
        cl=1
        while cl <20:
            try:
                c=Department*1000+grade*100+cl
                if Department<10:
                    web = requests.get('https://www.mcu.edu.tw/student/new-query/sel-6-4.asp?text0=0'+str(c)+'&text3=00997&ch=1')
                else:
                    web = requests.get('https://www.mcu.edu.tw/student/new-query/sel-6-4.asp?text0='+str(c)+'&text3=00997&ch=1')
                print(c)
                web.encoding='big5'

                soup = BeautifulSoup(web.text, "html5lib") 
                test =soup.find_all('td',align="center")
            
                #print(map)

                temp_id=0
                for i in test:
                    if i.get_text()[0]=='0' or i.get_text()[0]=='1':
                        temp_id=i.get_text()
                    elif i.get_text()[0] !='必':
                        map.append({"id":temp_id,"name":i.get_text(),"class":c})
                cl+=1
            except:
                time.sleep(1)



print ("ok")

import csv
labels = ["id", "name","class"]
try:
    with open("id_name.csv", "w") as f:
        writer = csv.DictWriter(f, fieldnames=labels)
        writer.writeheader()
        for elem in map:
            writer.writerow(elem)
except IOError:
    print("I/O error")
