# ch17_2.py
import requests, bs4

url = 'https://www.thsrc.com.tw'
response = requests.get(url)
print(response.encoding)
response.encoding = 'utf-8'
print(response.encoding)
objSoup = bs4.BeautifulSoup(response.text, 'lxml')

stations = objSoup.find('select', id='select_location01').find_all('option')
print("高鐵站名")
for station in stations:
    if station['value']:
        print(station.text.strip(), station['value'])












