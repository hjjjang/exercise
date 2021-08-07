### 시각 ###

n = int(input())

cnt=0
for hr in range(0,n+1):
    for min in range(60):
        for sec in range(60):
            if '3' in str(hr)+str(min)+str(sec):
                cnt+=1

print(cnt)

'''My code: (failed)
cnt = 0
for hr in range(0,n+1):
    if hr%10==3:
        cnt+=60*60
    else:
        for min in range(60):
            if min%10==3 or str(min)[0]==3:
                cnt+=60
            else:
                for sec in range(60):
                    if sec%10==3 or str(sec)[0]==3:
                        cnt+=1

print(cnt)
'''
