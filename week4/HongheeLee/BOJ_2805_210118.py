'''
    문제설명
        백준 2805 나무 자르기(이분탐색 이용)
        적어도 m미터의 나무를 집에 가져가기 위해 절단기에 설정할 수 있는 높이의 최댓값 구하기
    해결전략
        설정높이는 가장 작을 때 0이고 가장 클 때는 주어진 나무의 높이 중 가장 큰 것과 같다.
        그래서 lt = 0, rt = max(tree)로 초기화하고 그 중간값으로 나무를 잘랐을 때 얻는 결과와 목표 결과를 비교해서 탐색 범위를 조정한다.
        나무를 잘랐을 때 얻는 길이는 tree 리스트에서 각 원소마다 설정 높이보다 큰 부분을 다 더한 것과 같다. (함수로 구현)
        그 길이가 목표보다 크거나 같으면 일단 그 설정높이가 답이 될 수 있기 때문에 res에 저장하고 
        더 좋은 값(최댓값)을 찾기 위해 lt를 mid+1로 갱신해 탐색 범위를 조정한채로 탐색을 계속한다.
        길이가 목표보다 작으면 rt를 mid-1로 갱신해 탐색 범위를 조정한 후 탐색을 계속한다.
        lt가 rt보다 커지면 탐색이 종료되고 그때의 res 값이 설정 높이의 최댓값이다.
'''
def check(hei):
    tot = 0
    for t in tree:
        if t > hei:
            tot += t - hei
    return tot
n, m = map(int, input().split())
tree = list(map(int, input().split()))
lt = 0
rt = max(tree)
res = 0
while lt <= rt:
    mid = (lt+rt) // 2
    if check(mid) >= m:
        lt = mid + 1
        res = mid
    else:
        rt = mid - 1
print(res)
