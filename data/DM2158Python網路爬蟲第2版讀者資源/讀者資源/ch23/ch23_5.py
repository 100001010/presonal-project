# ch23_5.py
from pytrends.request import TrendReq

pytrend = TrendReq()
print("美國今天熱蒐的關鍵字")
print("-"*70)
df = pytrend.today_searches(pn='US')
print(df.head())        # 沒有註明, 表示列印前5筆




