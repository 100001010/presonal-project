# ch3_6.py
import requests

url = 'http://www.mcut.edu.tw'
response = requests.get(url)
if response.status_code == requests.codes.ok:
    print("取得網頁內容成功")
    print("網頁內容大小 = ", len(response.text))
else:
    print("取得網頁內容失敗")





