'''
    문제설명
        프로그래머스 h_index
    해결전략
        [1, 18, 19, 20]이 주어졌을 때 답이 1이 아니라 3이라는 것을 유의해야한다.
        h번 이상 인용된 논문이 h편 이상이라고 하였으니 (h 넘는 논문 갯수) >= h여야 한다.
        citations을 오름차순 정렬한 후 반복문을 통해 하나씩 돌면서 해당 조건에 맞는 h의 최댓값을 찾는다.   
'''
def solution(citations):
    ans = 0
    citations.sort()
    for idx in range(len(citations)):
        if citations[idx] >= len(citations) - idx:
            ans = max(ans, len(citations) - idx)
    return ans
