### 회의실 배정 ###

n = int(input())
schedule = [tuple(map(int, input().split())) for _ in range(n)]
schedule = sorted(schedule, key=lambda x:(x[1],x[0]))

result = 0
current = 0
for start, end in schedule:
    if start >= current:
        result += 1
        current = end

print(result)
