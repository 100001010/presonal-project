# ch6_10.py
import requests
import json

url = 'https://data.epa.gov.tw/api/v1/aqx_p_432?format=json&api_key=9be7b239-557b-4c10-9775-78cadfc555e9'
try:
    response = requests.get(url)                # 將檔案下載至response物件
    print('下載成功')
except Exception as err:
    print('下載失敗')       
aqi = response.json()['records']                # 取得需要的空氣品質資料              

fn = "aqi.json"                                 # 建立欲儲存的json檔案 
with open(fn, 'w') as f:
    json.dump(aqi,f)                            # 寫入json檔案至aqi.json





    















