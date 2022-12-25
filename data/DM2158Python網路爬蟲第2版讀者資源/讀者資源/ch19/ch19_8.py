# ch19_8.py
import facebook
import os
import shutil
import requests

token = "EAAIZCihE7RSkBAKGOOmFqV2ZAsYwwDN1TizKjJZApI8DTJeD68Tgv6zZBisL6urRixy2Ikw9FIG5PhbYeXLXVwQCpLuZB8mRv2wr4N5iDBDMPZCZCDToPLqjjxPY7zqxCFnYCtwBhFXQ7yX3Dch4ZBSm6nt5GZCbc1Vw8KrkgBgpQhJt9JE3BbWZA3V5F40nBqyBV3vxFNxHscs6boNa6cAbZBt"
graph = facebook.GraphAPI(access_token=token,version='3.1')

picture = graph.get_connections(id='me',connection_name='photos?fields=images')

photos = picture['data']

mydir = "out19_8"
if not os.path.exists(mydir):
    os.mkdir(mydir)
n = 0
for p in photos:
    imageList = p['images']
    n += 1
    if n > 10:
        break
    for pict in imageList:
        filename = pict['source'].split('/')[-1].split('?')[0]
        dst = open(mydir+'/'+filename, 'wb')
        fig = requests.get(pict['source'], stream=True)
        shutil.copyfileobj(fig.raw, dst)
        dst.close()

















