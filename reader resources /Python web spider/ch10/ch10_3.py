# ch10_3.py
import requests, bs4

url = 'https://udn.com/news/cate/2/7225'            # 全球頭條新聞
newshtml = requests.get(url)
objSoup = bs4.BeautifulSoup(newshtml.text, 'lxml')  # 取得HTML
items = objSoup.find('div', 'context-box__content')                 

news = items.find_all('a')
for new in news:
    print(new.text)




    
          


                     



    
    

    





















