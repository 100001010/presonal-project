# ch23_12.py
from pytrends.request import TrendReq

pytrend = TrendReq(hl='en-US', tz=360)
pytrend.build_payload(kw_list=['covid-19'])
interest_region = pytrend.interest_by_region()
print(interest_region.sort_values(['covid-19'],ascending=False).head(15))







