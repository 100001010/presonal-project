# ch22_4.py
import requests
import bs4 

url = "https://www.books.com.tw/web/sys_saletopb/books/19?attribute=30"
headers = { 'User-Agent':'Mozilla/5.0 (Windows NT 6.1; WOW64)\
            AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.101\
            Safari/537.36', }
response = requests.get(url, headers=headers)
soup = bs4.BeautifulSoup(response.text, 'lxml')

it_top100 = soup.find('div', class_="type02_m035")
it_books = it_top100.find('ul', class_='clearfix')
books = it_books.find_all("li", class_="item")
for book in books:
    top = book.find('strong', class_='no')
    print(f"排行榜 : {top.text.strip()}")
    title = book.find('h4')
    print(f"書名   : {title.text.strip()}")   
    price = book.find('ul', class_='msg').find('li',class_='price_a')
    print(f"售價   : {price.text.strip()}")
    
