# ch5_3.py
import bs4

response = open('myhtml.html', encoding='utf-8')
objSoup = bs4.BeautifulSoup(response, 'lxml')
print("物件類型  = ", type(objSoup.title))
print("列印title = ", objSoup.title)











