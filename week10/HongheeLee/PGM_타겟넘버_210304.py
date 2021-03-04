'''
    문제설명
        PGM 타겟넘버 (DFS/BFS)
        주어진 리스트의 정수들을 더하거나 빼서 목표 숫자를 만들 수 있는 방법의 수 구하기
    해결전략
        DFS(깊이우선탐색)으로 해결한다. 그래프를 그려보면 쉽게 해결할 수 있다. 주어진 정수는 더하거나 빼거나 둘 중에 하나의 경우.
        리스트의 숫자들에 level에 따라 하나하나 접근하면서 이전까지 숫자의 합에 지금 숫자를 더해가는 가지 하나, 빼가는 가지 하나씩 뻗어나간다.
        level(깊이)가 주어진 리스트의 길이만큼 되었을 때 그때까지의 합이 목표 숫자와 같으면 전체 count를 하나 증가시킨다.
        이때 전역변수의 값을 갱신하기 위해서 global을 사용한다.
'''
cnt = 0
def DFS(L, sum, nums, target):
    global cnt
    if L == len(nums):
        if sum == target:
            cnt += 1
    else:
        DFS(L+1, sum+nums[L], nums, target)
        DFS(L+1, sum-nums[L], nums, target)
        
def solution(numbers, target):
    global cnt
    DFS(0, 0, numbers, target)
    return cnt
