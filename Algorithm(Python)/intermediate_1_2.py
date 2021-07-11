T = int(input()) # 노선 수

for line in range(1,T+1):
    ##입력##
    K, N, M = map(int, input().split())
    stopswithcharger = map(int, input().split())
    stops = [0] * (N+1)

    ##알고리즘##
    recent_charged_stop = 0
    for i in stopswithcharger:
        if stops[i] - recent_charged_stop > K:
            return 0




    nochargenum = 0
    for stop in range(1, N+1):
        nochargenum += 1
        if stop.isin(stopswithcharger):
            nochargenum = 0
