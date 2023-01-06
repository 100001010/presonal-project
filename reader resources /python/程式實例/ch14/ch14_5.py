# ch14_5.py
import os

mydir = 'testch14'
# 如果mydir不存在就建立此資料夾
if os.path.exists(mydir):
    print(f"已經存在 {mydir} ")
else:
    os.mkdir(mydir)
    print(f"建立 {mydir} 資料夾成功")








