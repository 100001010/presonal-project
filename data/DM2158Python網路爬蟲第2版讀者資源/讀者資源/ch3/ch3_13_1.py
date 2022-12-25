# ch3_13_1.py
import requests

headers = { 'User-Agent':'Mozilla/5.0 (Windows NT 6.1; WOW64)\
            AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.101\
            Safari/537.36', }
url = 'https://www.kingstone.com.tw/basic/2013120599512?zone=book&lid=search&actid=WISE'
response = requests.get(url, headers=headers)
response.raise_for_status()
print("偽裝瀏覽器擷取網路資料成功")


