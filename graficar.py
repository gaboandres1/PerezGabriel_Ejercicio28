import numpy as np
import matplotlib.pyplot as plt
data1 = np.loadtxt('data1.dat')
data2 = np.loadtxt('data2.dat')
plt.plot(data1[:,1], data1[:,3], label='Sin fricción');
plt.plot(data2[:,1], data2[:,3], label='Con fricción')
plt.legend()
plt.xlabel('x')
plt.ylabel('y')
plt.savefig('grafica.png')