# ch23_10.py
from pytrends.request import TrendReq

pytrend = TrendReq()
pytrend.build_payload(kw_list=['Python'])
related_topic = pytrend.related_topics()
print(related_topic.values())







