# ch3_12_1.py
import requests

url = 'https://www.kingstone.com.tw/basic/2013120599512?zone=book&lid=search&actid=WISE'
response = requests.get(url)
response.raise_for_status()



