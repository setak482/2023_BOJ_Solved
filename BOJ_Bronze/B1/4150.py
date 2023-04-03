fibo = [0] * 10000
fibo[1] = 1
fibo[2] = 1
a = int(input())
for i in range(3, a+1):
    fibo[i] = fibo[i-2] + fibo[i-1]

print(fibo[a])