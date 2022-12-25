# ch17_3.py
from selenium import webdriver
from bs4 import BeautifulSoup

url = "https://www.cwb.gov.tw/V8/C/W/County/County.html?CID=63"
dirverPath = 'D:\geckodriver\chromedriver.exe'
browser = webdriver.Chrome(dirverPath)

browser.get(url)
soup = BeautifulSoup(browser.page_source, "lxml")
span = soup.select_one("li:nth-child(2) > span.tem > span.tem-C.is-active")
print(span.text)



