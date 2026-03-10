cnt = 0
flag =True

for _ in range(8):
    L = input()
    for i in range(8):
        if flag:
            if i % 2 == 0 and L[i] == 'F':
                cnt += 1
        else:
            if i % 2 == 1 and L[i] == 'F':
                cnt += 1

    flag = not flag

print(cnt)