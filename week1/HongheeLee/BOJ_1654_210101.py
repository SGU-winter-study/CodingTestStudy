'''
    문제설명
        백준 1654 랜선 자르기 문제(이분탐색 알고리즘 이용)
    해결 전략
        이분탐색의 범위(자를 수 있는 랜선의 길이)는 1부터 가진 랜선의 최대 길이까지.
        범위의 양끝을 lt와 rt 변수에 할당하고 그 중간값을 목표와 비교해 범위를 조정하는 방식인 이분탐색
        이분탐색에는 오름차순이나 내림차순 정렬 필요한데 여기서는 범위가 연속된 자연수 구간이기 때문에 이미 정렬되어 있다고 볼 수 있다.
        목표보다 더 많은 랜선을 자를 수 있어도 답이 될 수 있으므로 일단 저장하고 범위를 계속 좁혀가며 최대 길이를 찾는다.
'''
def Count(len):
    cnt = 0
    for x in Line:
        cnt += (x // len)
    return cnt
k, n = map(int, input().split())
Line = []
largest = 0
for i in range(k):
    tmp = int(input())
    Line.append(tmp)
    largest = max(largest, tmp)
lt = 1
rt = largest
res = 0
while lt <= rt:
    mid = (lt+rt) // 2
    if Count(mid) >= n:
        res = mid
        lt = mid+1
    else:
        rt = mid-1
print(res)
