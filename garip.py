xxx = input()
xx = xxx.split(" ")
l = int(xx[0])
n = int(xx[1])

sum = 0
list = []

for i in range(n):
    list.append(int(input()))

t = int(input())


for i in list:
    if i*t < l:
        sum += i
print(n - 1 - float(t / l)*sum)

#
# xxx = input()
# xx = xxx.split(" ")
# L = int(xx[0])
# N = int(xx[1])
# V = []



xxx = input()
xx = xxx.split(" ")
L = int(xx[0])
N = int(xx[1])
V = []
for i in range(N):
    inpt = int(input())
    if inpt < 0:
        V.append(inpt*-1)
    elif inpt > 0:
        V.append(inpt)
T = int(input())
pay = 1
payda = 1
for i in V:
    if L <= i*T:
        pay = 0
        break
    pay *= L - T * i
    payda *=L
print(float(payda - pay)/float(payda))