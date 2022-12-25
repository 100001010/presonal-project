# ch3_4.py
import requests

url = 'http://www.mcut.edu.tw'
response = requests.get(url)
print(type(response))


