# ch5_7_5.py
import bs4
import re

response = "<h1 class='boldtext'>深智數位</h1>"
objSoup = bs4.BeautifulSoup(response, 'lxml')
tag = objSoup.find('h1', class_=re.compile('text'))
print(tag)
print(tag.text)














