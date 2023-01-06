# -*- coding: utf-8 -*-
import scrapy
import bs4

class YahooSpider(scrapy.Spider):
    name = 'yahoo'
    allowed_domains = ['tw.yahoo.com']
    start_urls = ['http://tw.yahoo.com/']

    def parse(self, response):
        objSoup = bs4.BeautifulSoup(response.text, 'lxml')
        dataTag = objSoup.select('#panel0-content')         # 尋找id是panel0-content
        print("串列長度", len(dataTag))                     # 得到串列長度
  
        headline_news = dataTag[0].find_all('a')            # 焦點新聞是在標籤<a>
        for h in headline_news:
            news = {
                'news_info' : h.text,
                'links_info ': h.get('href')
                }
            yield news


