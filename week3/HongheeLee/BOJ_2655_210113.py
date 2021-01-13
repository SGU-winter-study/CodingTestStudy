'''
    문제설명
        백준 2655 가장높은탑쌓기(DP 이용)
        넓이가 넓은 벽돌이 아래에, 무게가 무거운 벽돌이 아래에 가도록 하면서 가장 높은 탑 쌓는 방법 구하고 사용된 벽돌 번호 출력.
    해결전략
        가장 긴 증가하는 부분수열 구하는 DP 문제와 유사하다.
        우선 주어진 벽돌을 넓이 기준으로 내림차순 정렬한다.
        dy[i]는 i번째 벽돌이 제일 위에 있을 때 탑의 높이다. i번째 벽돌 앞에 있는 벽돌 중 무게는 크고, 탑의 높이는 높은 벽돌을 찾아 바로 아래의 벽돌로 삼는다.
        바로 아래 벽돌이 제일 위에 있을 때 탑의 높이 + i번째 벽돌의 높이 = dy[i]
        최대 높이는 모든 벽돌을 다 순회하며 검사할 때 구할 수 있고 꼭 마지막 벽돌이라는 보장은 없다.
        또한 최대 높이를 이루는 벽돌의 번호를 구하기 위해 최대 높이에서 역산해서 인덱스를 구한다.
'''
n = int(input())
bricks = []
dy = [0] * n
res = []
idx = 0
for i in range(n):
    a, b, c = map(int, input().split())
    bricks.append((a, b, c, i+1))
bricks.sort(reverse=True)
hei = bricks[0][1]
dy[0] = bricks[0][1]
for i in range(1, n):
    max_h = 0
    for j in range(i-1, -1, -1):
        if bricks[j][2] > bricks[i][2] and max_h < dy[j]:
            max_h = dy[j]
    dy[i] = max_h + bricks[i][1]
    if hei < dy[i]:
        hei = dy[i]
        idx = i
while idx != -1:
    if hei == dy[idx]:
        res.append(bricks[idx][3])
        hei -= bricks[idx][1]
    idx -= 1
print(len(res))
for x in res:
    print(x)
