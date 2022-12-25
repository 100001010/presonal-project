# ch23_4.py
from pytrends.request import TrendReq

pytrend = TrendReq()
print("美國目前熱蒐的關鍵字")
df = pytrend.trending_searches(pn='united_states')
print(df.head())        # 沒有註明, 表示列印前5筆
print("-"*70)

print("日本目前熱蒐的關鍵字")
df = pytrend.trending_searches(pn='japan')
print(df.head())        # 沒有註明, 表示列印前5筆
print("-"*70)

print("台灣目前熱蒐的關鍵字")
df = pytrend.trending_searches(pn='taiwan')
print(df.head(10))      # 列印前10筆


