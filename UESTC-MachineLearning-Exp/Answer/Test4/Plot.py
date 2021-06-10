import matplotlib.pyplot as plt
linekernelx = [1, 2, 3, 4, 5]
linekernely = [20, 40, 40, 40, 40]
gaussiankernelx = [1, 2, 3, 4, 5]
gaussiankernely = [20, 40, 60, 60, 60]
plt.plot(linekernelx, linekernely, label='linekernel line', linewidth=3,
color='r', marker='o',
 markerfacecolor='blue', markersize=12)
plt.plot(gaussiankernelx, gaussiankernely, label='gaussiankernel line',
linewidth=3, color='r', marker='o',
 markerfacecolor='yellow', markersize=12)
plt.xticks(linekernelx, ("1", "100", "10000", "1000000", "100000000"),
rotation=70)
plt.xlabel('C')
plt.ylabel("Accuracy :%")
plt.legend()
plt.show()
