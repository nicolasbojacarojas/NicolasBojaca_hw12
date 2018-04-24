import numpy as np 
import matplotlib.pyplot as plt
#carga de datos generados en el archivo .cpp
data = np.loadtxt("advection.txt")
#asignacion de los valores de los x
x = data[:,1]
# asignacion de los valores que toma la funcion
u = data[:,0]
#grafica y guardado de esta
plt.plot(x, u)
plt.savefig("snapshots")

