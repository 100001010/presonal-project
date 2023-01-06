# ch5_4.py
print("奇數偶數判斷")
num = input("請輸入任意整值: ")
rem = int(num) % 2
if (rem == 0):
    print(f"{num} 是偶數")
else:
    print(f"{num} 是奇數")

# Python風格
if rem:
    print(f"{num} 是奇數")
else:
    print(f"{num} 是偶數")

# 高手用法
print(f"{num} 是奇數" if rem else f"{num} 是偶數")


