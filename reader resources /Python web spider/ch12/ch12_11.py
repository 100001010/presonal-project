# ch12_11.py
import bs4 
import re
from selenium import webdriver

url = "https://www.bloomberg.com/quote/CCMP:IND"
driverPath = 'D:\geckodriver\chromedriver.exe'
browser = webdriver.Chrome(driverPath)
browser.implicitly_wait(5)
browser.get(url)
soup = bs4.BeautifulSoup(browser.page_source, "lxml")

# 處理CCMP:IND
ccmp = re.compile('companyId*')                 # 正則表達式
ccmp_box = soup.find("span", class_= ccmp)
ccmp_title = ccmp_box.text
print(ccmp_title)

# 處理NASDAQ Composite Index
company = re.compile('companyName*')            # 正則表達式
nasdaq_box = soup.find("div", class_= company)
nasdaq_title = nasdaq_box.text
print(nasdaq_title)

# 處理指數
priceText = re.compile('priceText*')
nasdaq_Index = soup.find("span", attrs={"class":priceText})
nasdaq_final_index = nasdaq_Index.text
print(nasdaq_final_index)

