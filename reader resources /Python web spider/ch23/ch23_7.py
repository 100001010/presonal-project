# ch23_7.py
from pytrends.request import TrendReq
import pandas as pd

pytrend = TrendReq()
keywords = pytrend.suggestions(keyword='Taipei')
df = pd.DataFrame(keywords)
df.drop(columns='mid')
print(df.drop(columns='mid').head())





