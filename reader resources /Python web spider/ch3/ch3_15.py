# ch3_15.py
import urllib.request

url = 'https://www.mcut.edu.tw'
response = urllib.request.urlopen(url)
print(type(response))
print(response)





