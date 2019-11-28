from numpy import *
from matplotlib.pylab import *

matriz = loadtxt("datos.txt")
for i in range(4):
    plot( linspace(0,0.1, len(matriz[i,:])), matriz[i,:])
savefig("ejercicio.png")
