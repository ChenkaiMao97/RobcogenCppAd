import time
import pybind_robots
import numpy as np


count = 10000

q = np.array([0.0, 1.0])
qd = np.array([2.0, 3.0])
tau = np.array([0.5, 0.5])

start = time.time()
for i in range(count):
    ret_val = pybind_robots.acrobot_step(q, qd, tau)
    end = time.time()
print((end - start)/count)
print(ret_val)
