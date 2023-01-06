# ch3_5.py
import requests

url = 'http://www.mcut.edu.tw'
response = requests.get(url)
if response.status_code == requests.codes.ok:
    print("取得網頁內容成功")
    print("網址訊息   : ", response.url)
    print("表頭訊息   : ", response.headers)
    print("cookie訊息 : ", response.cookies)
else:
    print("取得網頁內容失敗")


