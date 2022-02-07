import numpy as np
import math
import matplotlib.pyplot as plt

def line(point, angle, length):
    global endy, endx
    x, y = point
    endx = x + length * math.cos(angle)
    endy = y + length * math.sin(angle)
    plt.plot([x, endx], [y, endy])

def plot_point(p, l):
    
    x, y = p

    theta1 = math.acos((math.sqrt(x**2 + y**2)/2)/l) + math.acos(x/math.sqrt(x**2 + y**2))
    theta2 = 2*math.acos((math.sqrt(x**2 + y**2)/2)/l)
    print((theta1, theta2))

    ax = plt.gca()
    ax.set_xlim([0, 20])
    ax.set_ylim([0, 20])

    line((0, 0), theta1, l)
    print(endx, endy)
    line((endx, endy), theta1 - theta2, l)

plot_point((10, 10), math.sqrt(200)/2)
plot_point((10, 9), math.sqrt(200)/2)
plot_point((9, 10), math.sqrt(200)/2)
plot_point((0, 9), 200)
print(endx, endy)

plt.show()
