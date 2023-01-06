# ch5_4.py
import bs4

response = open('myhtml.html', encoding='utf-8')
objSoup = bs4.BeautifulSoup(response, 'lxml')
print("列印title = ", objSoup.title)
print("title內容 = ", objSoup.title.text)













