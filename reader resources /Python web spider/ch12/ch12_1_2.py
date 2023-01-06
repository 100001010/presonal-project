# ch12_1_1.py
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

url = 'https://www.tpex.org.tw/web/stock/aftertrading/daily_trading_info/st43.php?l=zh-tw'

driverPath = 'D:\geckodriver\chromedriver.exe'
browser = webdriver.Chrome(executable_path=driverPath)
browser.get(url)                    # 網頁下載至瀏覽器

text_date = browser.find_element_by_id('input_date')
text_date.send_keys('110/1')        # 這個設定只是啟動下一層的年和月

text_month = browser.find_element_by_class_name('ui-datepicker-month')
text_month.send_keys('7月')         # 設定7月
time.sleep(3)

text_stock = browser.find_element_by_id('input_stock_code')
text_stock.send_keys('5351')        # 設定股票代號
text_stock.send_keys(Keys.ENTER)
time.sleep(3)

btn = browser.find_elements_by_class_name('download-csv')
btn[1].click()                      # 按另存CSV鈕
time.sleep(3)


















