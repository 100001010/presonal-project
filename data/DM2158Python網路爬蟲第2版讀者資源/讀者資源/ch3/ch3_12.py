# ch3_12.py
import requests

url = 'http://aaa.24ht.com.tw/'
response = requests.get(url)
response.raise_for_status()



