# ch3_17.py
import urllib.request

url = 'https://www.mcut.edu.tw'
response = urllib.request.urlopen(url)
print(response.read().decode('utf-8'))







