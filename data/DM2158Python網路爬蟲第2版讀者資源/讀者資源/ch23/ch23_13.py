# ch23_13.py
from pytrends.request import TrendReq
import matplotlib.pyplot as plt

pytrend = TrendReq(hl='en-US', tz=360)
pytrend.build_payload(kw_list=['covid-19'])
interest_region = pytrend.interest_by_region()
df = interest_region.sort_values(['covid-19'],ascending=False)
print(df.head(15))
df.head(15).plot(kind='bar')
plt.show()








