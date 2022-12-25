# ch5_2.py
import bs4

response = open('myhtml.html', encoding='utf-8')
objSoup = bs4.BeautifulSoup(response, 'lxml')
print("列印BeautifulSoup物件資料型態 ", type(objSoup))











