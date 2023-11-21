import requests
import time
ok_time=0
wait_second=0
b=1
while 1==1:
    try:
        if b==0:
            break
        web = requests.get('https://www.mcu.edu.tw/student/new-query/sel-6-4.asp?text0=27201&text3=00999&ch=1')
        ok_time+=1
    except:
        time.sleep(1)
        
        wait_second+=1
        b=0
print(ok_time)
print(" ")
print(wait_second)

