import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import json

df = pd.read_csv("pressure.csv", sep=";")

r1 = np.polyfit(df["bar"], df["mV"], 1)
r2 = np.polyfit(df["bar"], df["mV"], 2)
r3 = np.polyfit(df["bar"], df["mV"], 3)
r4 = np.polyfit(df["bar"], df["mV"], 4)
p1 = np.poly1d(r1)
p2 = np.poly1d(r2)
p3 = np.poly1d(r3)
p4 = np.poly1d(r4)

ir1 = np.polyfit(df["mV"],df["bar"],  1)
ir2 = np.polyfit(df["mV"],df["bar"],  2)
ir3 = np.polyfit(df["mV"],df["bar"],  3)
ir4 = np.polyfit(df["mV"],df["bar"],  4)

coeffs = {}
coeffs["ir1"] = list(reversed(np.ndarray.tolist(ir1)))
coeffs["ir2"] = list(reversed(np.ndarray.tolist(ir2)))
coeffs["ir3"] = list(reversed(np.ndarray.tolist(ir3)))
coeffs["ir4"] = list(reversed(np.ndarray.tolist(ir4)))

print("// polynomial coefficients for order 1,2,3,4")
print(json.dumps(coeffs, indent=4, sort_keys=True))

# for t in range(20, 130, 10):
#     print(t, p1(t), p2(t), p3(t), p4(t))


df.insert(2, "o=1", p1(df["bar"]))
df.insert(3, "o=2", p2(df["bar"]))
df.insert(4, "o=3", p3(df["bar"]))
df.insert(5, "o=4", p4(df["bar"]))

ax = df.plot.scatter(x="bar", y="mV")

df.plot(x="bar", y="o=1", color="black", ax=ax)
df.plot(x="bar", y="o=2", color="Red", ax=ax)
df.plot(x="bar", y="o=3", color="Green", ax=ax)
df.plot(x="bar", y="o=4", color="Blue", ax=ax)

plt.show()
print(r3)
