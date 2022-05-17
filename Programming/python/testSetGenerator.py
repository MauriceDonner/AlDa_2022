import numpy as np

n = 10
e = []
w = []

i=0
while (i<10):
    tmp = np.random.randint(0,100)
    if tmp in e:
        continue
    e.append(tmp)
    i+=1

i=0
while (i<10): 
    tmp = np.random.randint(0,100)
    if tmp in w:
        continue
    w.append(tmp)
    i+=1

print(e, len(e))
print(w, sum(w))
