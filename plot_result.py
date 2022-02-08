import numpy as np
import matplotlib.pyplot as plt; plt.ion()


i = np.loadtxt('original.txt')
o = np.loadtxt('result.txt')

f, ax = plt.subplots(nrows=1, ncols=1, figsize=(5,3))
ax.plot(i[:,0], i[:,1], 'o', color='orangered', label='Original')
ax.plot(o[:,0], o[:,1], '-', color='black', label='Interpolated')
ax.set_xlabel('x')
ax.set_ylabel('y')

ax.legend(frameon=False, loc='lower right')
f.set_tight_layout(True)
f.savefig('fig_result.pdf', format='pdf', dpi=250)
