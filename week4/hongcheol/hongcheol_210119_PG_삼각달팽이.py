'''
구현 부분에서 매끄럽지 못한 경우가 많아서 구현에 관한 문제를 진행했다.
코드를 짜는 시간보다 알고리즘 짜는 시간을 더 길게 해야할 필요가 있다.
'''

def solution(n):
    answer = []
    array =[[0]*n for _ in range(n)]
    number = 0
    para = n%3
    i,j = -1,0
    ran = n*(n+1)/2
    for k in range(n):
        if k%3 == 0:
            for _ in range(n-k):
                i += 1
                array[i][j] = number + 1
                number += 1
        elif k%3 == 1:
            for _ in range(n-k):
                j += 1
                array[i][j] = number + 1
                number += 1
                
        else:
            for _ in range(n-k):
                i -= 1
                j -= 1
                array[i][j] = number + 1
                number += 1
                
    for data in array:
        for num in data:
            if num == 0:
                break
            else:
                answer.append(num)
    return answer
