# ex13_4.py
import random                               # 導入模組random
dices = []
for loop in range(1,6):
    for i in range(3):
        dice = random.randint(1,6)
        dices.append(dice)
    print(f"{loop} : 隨機3組骰子值 : {sorted(dices)}")
    for i in range(3):
        dices.pop()
    















