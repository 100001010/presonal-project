# ch6_9.py
import requests
import json

url = 'https://data.epa.gov.tw/api/v1/aqx_p_432?format=json&limit=5&api_key=9be7b239-557b-4c10-9775-78cadfc555e9'
try:
    response = requests.get(url)        # 將檔案下載至aqijsons
    print('下載成功')
except Exception as err:
    print('下載失敗')

aqi = response.json()['records']        # 取json資料
for pm in aqi:
    print(pm['County'], pm['SiteName'], pm['Status'], pm['PM2.5'])  

 




    















