# ch22_2.py
import requests, bs4

url = "https://www.railway.gov.tw/tra-tip-web/tip/tip004/tip421/restCode?RestNo=A210"
response = requests.get(url)
obj = bs4.BeautifulSoup(response.text, 'lxml')
restaurant = obj.find("h3", 'shop-title')
print(restaurant.text)
print("-"*70)      
food = obj.find("ul", class_="shop-item")
meals = food.find_all("li") 
for meal in meals:
    title = meal.find("div", class_="pro-title")
    print("台中鐵路便當 :", title.text)
    price = meal.find("strong")
    print("鐵路便當價格 :", price.text)
           


