# ch23_8.py
from pytrends.request import TrendReq

pytrend = TrendReq()
pytrend.build_payload(kw_list=['coronavirus'])
related_query = pytrend.related_queries()
print(related_query.values())

