# ch19_4.py
import facebook

token = "EAAIZCihE7RSkBAKGOOmFqV2ZAsYwwDN1TizKjJZApI8DTJeD68Tgv6zZBisL6urRixy2Ikw9FIG5PhbYeXLXVwQCpLuZB8mRv2wr4N5iDBDMPZCZCDToPLqjjxPY7zqxCFnYCtwBhFXQ7yX3Dch4ZBSm6nt5GZCbc1Vw8KrkgBgpQhJt9JE3BbWZA3V5F40nBqyBV3vxFNxHscs6boNa6cAbZBt"
graph = facebook.GraphAPI(access_token=token, version='3.1')

idsList = ['1116138285252667_1792295917636897',
           '1116138285252667_1113470975519398']           
mypost = graph.get_objects(ids=idsList)

for ids in idsList:
    post = mypost[ids]                  # 取得特定id發文物件
    print("列出發文資料內容 : ", post)
    print("發文日期 : ", post['created_time'])
    print("發文內容 : ", post['message'])
    print("發文的id : ", post['id'])
    print()


















