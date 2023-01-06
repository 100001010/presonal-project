# ch14_2.py
import requests, json
import pandas as pd

url = "https://tcgbusfs.blob.core.windows.net/blobyoubike/YouBikeTP.json"
ubike_df = pd.DataFrame(columns=('sna', 'mday', 'tot', 'sbi', 'bemp'))

rowID = 121
response = requests.get(url)
data = json.loads(response.text)
df = pd.DataFrame.from_dict(data["retVal"], orient='index')
sna = df.iloc[rowID-1,1]
print("站點名稱 : ", sna)
mday = df.iloc[rowID-1,5]
print("更新時間 : ", mday)
tot = df.iloc[rowID-1,2]
print("停車格數 : ", tot)
sbi = df.iloc[rowID-1,3]
print("車輛數量 : ", sbi)
bemp = df.iloc[rowID-1,12]
print("空位格數 : ", bemp)

