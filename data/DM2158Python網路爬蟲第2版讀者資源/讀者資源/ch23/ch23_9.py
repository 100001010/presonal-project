# ch23_9.py
from pytrends.request import TrendReq

pytrend = TrendReq()
pytrend.build_payload(kw_list=['coronavirus'])
related_query = pytrend.related_queries()
print(related_query['coronavirus']['top'].head(15))
print(related_query['coronavirus']['rising'].head(15))





