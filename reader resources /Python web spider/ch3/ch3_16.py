# ch3_16.py
import urllib.request

url = 'https://www.mcut.edu.tw'
response = urllib.request.urlopen(url)
print(response.read())







