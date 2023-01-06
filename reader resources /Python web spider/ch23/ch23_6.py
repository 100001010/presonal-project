# ch23_6.py
from pytrends.request import TrendReq

pytrend = TrendReq()
print("全球2020年熱蒐的關鍵字")
df = pytrend.top_charts(2020, hl='en-US', tz=300, geo='GLOBAL')
print(df.head(10))      # 列印前10筆
print("-"*70)

print("台灣2020年熱蒐的關鍵字")
df = pytrend.top_charts(2020, hl='zh-tw', tz=-480, geo='TW')
print(df.head(10))      # 列印前10筆


