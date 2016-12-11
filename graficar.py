import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
'''
tablero = input("Coloque el input:")

resultado = input("Coloque el output")
'''
tablero = "10 10 .1..3..... 2..1..2322 21.3...31. 22.2.313.. .2.332..22 ..30..1... .13..2321. .2..2.2.2. .323..1.21 ..2..3322."

resultado = "10 10 1110111111 10011000001 1010101101 01100110110 0011010100 01001001010 1011010101 10100110101 0101000101 11011111010 1010101010 00100000100 0010110101 00011011011 1110101000 10000100011 1101011110 00111000001 0100010110 01011111011 0110101001"

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
			ax.text(j+alfa,N-i-1+alfa,tablero[i][j],fontsize = 20)



plt.show()
