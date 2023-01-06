# ch5_1.py
import requests, bs4

response = requests.get('https://deepmind.com.tw')
objSoup = bs4.BeautifulSoup(response.text, 'lxml')
print("列印BeautifulSoup物件資料型態 ", type(objSoup))











