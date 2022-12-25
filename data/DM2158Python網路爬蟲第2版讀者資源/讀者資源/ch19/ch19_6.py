# ch19_6.py
import facebook

token = "EAAIZCihE7RSkBAKGOOmFqV2ZAsYwwDN1TizKjJZApI8DTJeD68Tgv6zZBisL6urRixy2Ikw9FIG5PhbYeXLXVwQCpLuZB8mRv2wr4N5iDBDMPZCZCDToPLqjjxPY7zqxCFnYCtwBhFXQ7yX3Dch4ZBSm6nt5GZCbc1Vw8KrkgBgpQhJt9JE3BbWZA3V5F40nBqyBV3vxFNxHscs6boNa6cAbZBt"
graph = facebook.GraphAPI(access_token=token,version='3.1')
mylikes = graph.get_connections(id='me',
                               connection_name='likes')

likes = mylikes['data']
print("按讚的社團數 : ", len(likes))
for like in likes:
    print(like['name'])




    













