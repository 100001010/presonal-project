# ch3_13_2.py
import requests

headers = { 'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64)'
                          'AppleWebKit/537.36 (KHTML, like Gecko)'
                          'Chrome/92.0.4515.159 Safari/537.36'}
url = 'https://www.kingstone.com.tw/new/basic/2013120504769?zone=book&lid=search&actid=WISE'
response = requests.get(url, headers=headers)
response.raise_for_status()
print("偽裝瀏覽器擷取網路資料成功")


