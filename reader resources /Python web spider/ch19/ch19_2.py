# ch19_2.py
import requests
import json

url = "https://graph.facebook.com/v3.3/me/posts?limit=2&access_token=EAAIZCihE7RSkBAKGOOmFqV2ZAsYwwDN1TizKjJZApI8DTJeD68Tgv6zZBisL6urRixy2Ikw9FIG5PhbYeXLXVwQCpLuZB8mRv2wr4N5iDBDMPZCZCDToPLqjjxPY7zqxCFnYCtwBhFXQ7yX3Dch4ZBSm6nt5GZCbc1Vw8KrkgBgpQhJt9JE3BbWZA3V5F40nBqyBV3vxFNxHscs6boNa6cAbZBt"

data = json.loads(requests.get(url).text)   # 下載json資料轉成字典

for info in data['data']:
    print("我的Facebook發文")    
    print("發文日期", info['created_time'])
    print("發文內容", info['message'])
    print("發文的id", info['id'])
    print()











