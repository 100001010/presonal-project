# ex7_14.py
answer = 30                 # 正確數字
guess = 0                   # 設定所猜數字的初始值
index = 1                   # 猜測次數
while guess != answer:
    guess = int(input("請猜1-100間的數字 = "))
    if guess > answer:
        print("請猜小一點")
    elif guess < answer:
        print("請猜大一點")
    else:
        print("恭喜答對了")
        print(f"共猜 {index} 次")
    index += 1


