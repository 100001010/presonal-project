# ch5_6_1.py
import bs4

response = open('myhtml.html', encoding='utf-8')
objSoup = bs4.BeautifulSoup(response, 'lxml')
objTag = objSoup.find_all('h1', limit=2)
for data in objTag:                       # 列印串列元素內容
    print(data.text)













