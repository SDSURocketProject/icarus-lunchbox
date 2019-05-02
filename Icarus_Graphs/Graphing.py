import matplotlib.pyplot as plt
import numpy as np

timestamp, temperature, load, chamber = np.loadtxt('data.txt', delimiter=',', unpack= True)


plt.figure(1)
plt.plot(timestamp,temperature, label = 'Temperature vs Time')
plt.grid(True, lw = 1, ls = '--', c = '.5')
plt.xlabel('timestamp (mS)')
plt.ylabel('Temperature (F)')
plt.title('Temperature vs Time')

plt.figure(2)
plt.plot(timestamp,load, label = 'Thrust vs Time')
plt.grid(True, lw = 1, ls = '--', c = '.5')
plt.xlabel('timestamp (mS)')
plt.ylabel('Thrust (lbs)')
plt.title('Thrust vs Time')

plt.figure(3)
plt.plot(timestamp,chamber, label = 'Chamber Pressure vs Time')
plt.grid(True, lw = 1, ls = '--', c = '.5')
plt.xlabel('timestamp (mS)')
plt.ylabel('Chamber Pressure (lbs)')
plt.title('Chamber Pressure vs Time')
plt.legend()
plt.show()