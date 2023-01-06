# ch5_7_1.py
import bs4

response = open('myhtml.html', encoding='utf-8')
objSoup = bs4.BeautifulSoup(response, 'lxml')
objTag = objSoup.find(id='author')
print(objTag)
print(objTag.text)













