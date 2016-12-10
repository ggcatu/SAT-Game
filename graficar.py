import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
'''
tablero = input("Coloque el input:")

resultado = input("Coloque el output")
'''
tablero = "5 5 .223. .2.02 .3.2. 1.2.2 ..2.."

resultado = "5 5 01010 100111 11101 100001 01000 111111 00100 000001 11111 100001 00100"



tablero = tablero.split()
resultado = resultado.split()


N = int(tablero[0])
M = int(tablero[1])

hor = []
ver = []

for i in range(len(resultado)):
	if i < 2:
		continue
	if i % 2 == 0:
		hor += [resultado[i]]
	else:
		ver += [resultado[i]]



fig1 = plt.figure()
ax = fig1.add_subplot(111)

plt.xlim(-1, N+1)
plt.ylim(-1, M+1)


for i in range(len(hor)):
	for j in range(len(hor[i])):
		if (hor[i][j] == '1'):
			plt.plot([j,j+1], [N-i,N-i], 'r-')

for i in range(len(ver)):
	for j in range(len(ver[i])):
		if (ver[i][j] == '1'):
			plt.plot([j,j], [N-i,N-i-1], 'r-')

alfa = 0.25
tablero = tablero[2:]

for i in range(len(tablero)):
	for j in range(len(tablero[i])):
		if (tablero[i][j] != '.'):
			ax.text(j+alfa,N-i-1+alfa,tablero[i][j],fontsize = 40)



plt.show()