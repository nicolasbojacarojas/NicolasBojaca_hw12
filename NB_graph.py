import numpy as np 
import matplotlib.pyplot as plt
data = np.loadtxt("advection.txt")
x = data[:,1]
u = data[:,0]
plt.plot(x, u)
plt.savefig("snapshots")

