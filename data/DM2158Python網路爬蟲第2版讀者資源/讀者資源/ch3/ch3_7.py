# ch3_7.py
import requests

url = 'http://www.mcut.edu.tw'
response = requests.get(url)
if response.status_code == requests.codes.ok:
    print("取得網頁內容成功")
    print(response.text)            # 列印網頁內容
else:
    print("取得網頁內容失敗")





