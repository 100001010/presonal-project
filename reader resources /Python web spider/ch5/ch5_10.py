# ch5_10.py
import bs4

response = open('myhtml.html', encoding='utf-8')
objSoup = bs4.BeautifulSoup(response, 'lxml')
objTag = objSoup.select('#author')
print(str(objTag[0].attrs))

