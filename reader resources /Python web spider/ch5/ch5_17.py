# ch5_17.py
import requests
import bs4

response = requests.get('https://tw.yahoo.com/')
objSoup = bs4.BeautifulSoup(response.text, 'lxml')

dataTag = objSoup.select('#panel0-content')         # 尋找id是panel0-content
print("串列長度", len(dataTag))                     # 得到串列長度
  
headline_news = dataTag[0].find_all('a')            # 焦點新聞是在標籤<a>
for h in headline_news:
    print("焦點新聞 : " + h.text)                   # 列出焦點新聞標題
    print("新聞網址 : " + h.get('href'))            # 列出新聞網址




   














