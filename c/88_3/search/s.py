from random import randint, random, choice

M = 10

b = randint(1, M)
print b
a = range(1, M+1)
a.remove(b)
print choice(a)

for i in range(randint(1, M)):
    for j in range(randint(1, M)):
        if random() < 0.9:
            d = randint(1, 20)
            if randint(0, 1) == 1:
                print i, j, d
            else:
                print j, i, d
