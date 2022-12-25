# ch22_1.py
from bs4 import BeautifulSoup
from selenium import webdriver

url = "https://rent.housefun.com.tw/region/台北市/?cid=0000"
dirverPath = 'D:\geckodriver\chromedriver.exe'
browser = webdriver.Chrome(dirverPath)
browser.implicitly_wait(5)
browser.get(url)

obj = BeautifulSoup(browser.page_source, "lxml")
houseobj = obj.find("div", id="SearchContent")
houses = houseobj.find_all("article")

for house in houses:
    title = house.find("h3", class_="title").find("a")
    if title:
        print("標題 : ", title.text)
    address = house.find("address", class_="addr")
    if address:
        print("地址 : ", address.text.strip())
    level = house.find("span", class_="level")
    if level:
        print("內容 : ", level.text)
    pattern = house.find("span", class_="pattern")
    if pattern:
        print("樓層 : ", pattern.text)
    price = house.find("span", class_="infos")
    if price:
        print("租金 : ", price.text)
    print("-"*70)

