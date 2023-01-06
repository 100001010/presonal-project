# ch5_7_2.py
import bs4

response = open('myhtml.html', encoding='utf-8')
objSoup = bs4.BeautifulSoup(response, 'lxml')
objTag = objSoup.find_all(id='content')
for tag in objTag:
    print(tag)
    print(tag.text)














