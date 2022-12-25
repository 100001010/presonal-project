# ch6_14.py
import requests
import os
import json
import hashlib

def save_newaqi():
    '''儲存newaqi.json'''
    with open(fn, 'w') as f:
        json.dump(response.json(),f)            # 寫入json檔案至newaqi.json
def save_hashvalue():
    '''儲存哈希值至hashvalue.txt'''
    with open(fn_hash, 'w') as fileobj:
        fileobj.write(newhash)                  # 寫入哈希值至hashvalue.txt
def cal_hashvalue():
    ''' 計算hash value''' 
    data = hashlib.md5()
    data.update(response.text.encode('utf-8'))
    hashdata = data.hexdigest()
    return hashdata                             # 傳回哈希值

url = 'https://data.epa.gov.tw/api/v1/aqx_p_432?format=json&api_key=9be7b239-557b-4c10-9775-78cadfc555e9'
try:
    response = requests.get(url)                # 將檔案下載至response
    print('下載成功')
except Exception as err:
    print('下載失敗')
aqi = response.json()['records']                # 取得需要的空氣品質資料

fn = 'newaqi.json'
fn_hash = 'hashvalue.txt'                       # 檔案名稱
if os.path.exists(fn_hash):                     # 如果hashvalue.txt存在
    newhash = cal_hashvalue()                   # 計算新的哈希值hashvalue
    print('newhash = ',newhash)
# 開啟hashvalue.txt檔案
    with open(fn_hash, 'r') as fnObj:           # 讀取舊的哈希值
        oldhash =  fnObj.read()
        print('oldhash = ', oldhash)        
    if newhash == oldhash:                      # 比對新舊哈希值
        print('環保署空氣品質資料未更新')
    else:
        print('環保署空氣品質資料已經更新')
        save_newaqi()                           # 儲存newaqi.son
        save_hashvalue()                        # 儲存哈希值至hashvalue.txt
else:                                           # 如果hashvalue.txt不存在
    print('第一次啟動此程式')
    newhash = cal_hashvalue()
    print('哈希值 = ', newhash)
    save_hashvalue()                            # 儲存哈希值至hashvalue.txt
    save_newaqi()                               # 儲存newaqi.son



    
    






    















