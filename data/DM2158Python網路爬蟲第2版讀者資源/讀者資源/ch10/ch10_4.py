# ch10_4.py
import requests, bs4
headers = { 'User-Agent':'Mozilla/5.0 (Windows NT 6.1; WOW64)\
            AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.101\
            Safari/537.36', }
url = 'https://money.udn.com/money/cate/5591'            
newshtml = requests.get(url, headers=headers)
objSoup = bs4.BeautifulSoup(newshtml.text, 'lxml')  
itemobj = objSoup.find('div', 'category_box_list')

items = itemobj.find_all('dt', 'more_5612')
for item in items:
    txt = item.a.text.strip()                
    print(txt)
    


    
          


                     



    
    

    





















