import numpy as np
import math
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from time import sleep

def line(point, angle, length):
    global endy, endx
    x, y = point
    endx = x + length * math.cos(angle)
    endy = y + length * math.sin(angle)
    ax.plot([x, endx], [y, endy])

def plot_point(p, l):

    x, y = p

    theta1 = math.acos((math.sqrt(x**2 + y**2)/2)/l) + math.acos(x/math.sqrt(x**2 + y**2))
    theta2 = 2*math.acos((math.sqrt(x**2 + y**2)/2)/l)

    ax.set_xlim([0, 20])
    ax.set_ylim([0, 20])

    line((0, 0), theta1, l)
    line((endx, endy), theta1 - theta2, l)

fig = plt.figure()
ax = fig.add_subplot(111)

# def raise():

def animate(i):
    ax.clear()
    plot_point((5, 2 * math.sin(math.radians(i*30)) + 5), 5)

char = [[9,4],[14,13],[20,24],[26,34],[29,43],[32,51],[35,62],[38,71],[41,78],[42,78],[48,59],[52,41],[57,28],[61,20],[63,16],[65,13],[67,11],[68,9]]
for i in char:
    plot_point((i[0]/10, i[1]/10), 5)

length = 5
#ani = animation.FuncAnimation(fig, animate, interval = 1)
plt.show()
