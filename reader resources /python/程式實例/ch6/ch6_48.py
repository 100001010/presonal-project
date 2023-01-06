# ch6_48.py
x = 10
y = 10
z = 15
r = z - 5
boolean_value = x is y
print(f"x位址 = {id(x)}, y位址 = {id(y)}")
print(f"x = {x}, y = {y}, ", boolean_value)

boolean_value = x is z
print(f"x位址 = {id(x)}, z位址 = {id(z)}")
print(f"x = {x}, z = {z}, ", boolean_value)

boolean_value = x is r
print(f"x位址 = {id(x)}, r位址 = {id(r)}")
print(f"x = {x}, r = {r}, ", boolean_value)

boolean_value = x is not y
print(f"x位址 = {id(x)}, y位址 = {id(y)}")
print(f"x = {x}, y = {y}, ", boolean_value)

boolean_value = x is not z
print(f"x位址 = {id(x)}, z位址 = {id(z)}")
print(f"x = {x}, z = {z}, ", boolean_value)

boolean_value = x is not r
print(f"x位址 = {id(x)}, r位址 = {id(r)}")
print(f"x = {x}, r = {r}, ", boolean_value)


