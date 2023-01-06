# ch2_11_1.py
import csv

dictList = [{'姓名':'洪錦魁', '年齡':'45', '城市':'台北'},      # 定義串列,元素是字典
            {'姓名':'洪星宇', '年齡':'40', '城市':'新竹'}]
          
fn = 'out2_11_1.csv'
with open(fn, 'w', newline = '', encoding='utf-8') as csvFile:  # 開啟csv檔案
    fields = ['姓名', '年齡', '城市']
    dictWriter = csv.DictWriter(csvFile, fieldnames=fields)     # 建立Writer物件

    dictWriter.writeheader()                                    # 寫入標題
    for row in dictList:                                        # 寫入內容
        dictWriter.writerow(row)




