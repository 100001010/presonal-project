# ch3_18.py
import urllib.request

url = 'https://www.mcut.edu.tw'
response = urllib.request.urlopen(url)
print('版本 : ', response.version)
print('網址 : ', response.geturl())
print('下載 : ', response.status)
print('表頭 : ')
for header in response.getheaders():
    print(header)










