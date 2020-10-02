import numpy as np
import matplotlib.pyplot as plt
datax,datay =np.loadtxt("datos.txt",unpack = True)

fig, ax = plt.subplots()
ax.plot(datax, datay, 'r-o',label="DAta")
ax.legend()
fig.savefig("fig.pdf")
