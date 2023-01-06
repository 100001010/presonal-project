# ch23_3.py
from pytrends.request import TrendReq
import matplotlib.pyplot as plt

pytrend = TrendReq(hl="zh-TW", tz=-480)
keywords = ["江啟臣", "朱立倫", "張亞中", "卓伯源"]
pytrend.build_payload(
     kw_list=keywords,
     cat=0,
     timeframe="2021-09-01 2021-09-22",
     geo="TW",
     gprop="")

plt.rcParams["font.family"] = ["Microsoft JhengHei"]    # 微軟正黑體

df = pytrend.interest_over_time()
df = df.drop(["isPartial"], axis=1)
fig = plt.figure(dpi=80, figsize=(12, 8))
plt.plot(df.index, df.江啟臣, label=keywords[0])
plt.plot(df.index, df.朱立倫, label=keywords[1])
plt.plot(df.index, df.張亞中, label=keywords[2])
plt.plot(df.index, df.卓伯源, label=keywords[3])
fig.autofmt_xdate()
plt.legend()
plt.show()

