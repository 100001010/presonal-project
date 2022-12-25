# ch14_1.py
import requests, json
import pandas as pd

url = "https://tcgbusfs.blob.core.windows.net/blobyoubike/YouBikeTP.json"
fn = "youbike.csv"
response = requests.get(url)
ybike = json.loads(response.text)

# 下列orient是資料方向, index是將字典的鍵當作索引
df = pd.DataFrame.from_dict(ybike["retVal"], orient='index')
df.to_csv(fn, index=False, encoding="utf-8")

