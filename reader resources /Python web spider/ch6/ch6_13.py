# ch6_13.py
import requests
import hashlib
import json

url = 'https://data.epa.gov.tw/api/v1/aqx_p_432?format=json&api_key=9be7b239-557b-4c10-9775-78cadfc555e9'
try:
    response = requests.get(url)                # 將檔案下載至response物件
    print('下載成功')
except Exception as err:
    print('下載失敗')       
aqi = response.json()['records']                # 取得需要的空氣品質資料              

data = hashlib.md5()
data.update(response.text.encode('utf-8'))
hashdata = data.hexdigest()
print('環保署PM2.5的哈希值 = ', hashdata)

fn = "out6_13.txt"
with open(fn, 'w') as fileobj:
    fileobj.write(hashdata)





    















