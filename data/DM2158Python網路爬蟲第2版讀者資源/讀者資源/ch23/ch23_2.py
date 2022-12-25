# ch23_2.py
from pytrends.request import TrendReq

pytrend = TrendReq(hl="zh-TW", tz=-480)
keywords = ["江啟臣", "朱立倫", "張亞中", "卓伯源"]
pytrend.build_payload(
     kw_list=keywords,
     cat=0,
     timeframe="2021-09-01 2021-09-22",
     geo="TW",
     gprop="")

print(pytrend.interest_over_time())

