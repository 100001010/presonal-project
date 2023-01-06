# ch5_13_1.py
import requests, bs4

url = 'ch5_2_1.html'
response = open(url, encoding='utf-8')              
objSoup = bs4.BeautifulSoup(response, 'lxml')
titleobj = objSoup.find_all('h2')               # h2標題
print(titleobj[2].text)

itemobj = objSoup.find('ol', type='I')          # type='I'
items = itemobj.find_all('li')
for item in items:               
    print(item.text)



    
          


                     



    
    

    





















