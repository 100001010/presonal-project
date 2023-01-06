# ch14_3.py
import pandas as pd

df = pd.read_csv("youbike.csv")
df = df[["sna", "tot", "sbi", "bemp"]]
print(df.head())
print('-'*70)
df["車輛效率"] = 1 - df["sbi"] / df["tot"]
print(df.head())
print('-'*70)
youbike_used = df[['sna', '車輛效率']]
print(youbike_used.head())


