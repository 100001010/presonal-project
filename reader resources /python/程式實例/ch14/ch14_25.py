# ch14_25.py

fn = 'sse.txt'              # 設定欲開啟的檔案
with open(fn) as file_Obj:  # 用預設mode=r開啟檔案,傳回檔案物件file_Obj
    obj_list = file_Obj.readlines()  # 每次讀一行

str_Obj = ''                # 先設為空字串
for line in obj_list:       # 將各行字串存入
    str_Obj += line.rstrip()

findstr = input("請輸入欲搜尋字串 = ")
index = str_Obj.find(findstr)     # 搜尋findstr字串是否存在
if  index >= 0:             # 搜尋檔案是否有欲尋找字串
    print(f"搜尋 {findstr} 字串存在 {fn} 檔案中")
    print(f"在索引 {index} 位置出現")
else:
    print(f"搜尋 {findstr} 字串不存在 {fn} 檔案中")






    
