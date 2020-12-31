'''
    문제설명
        백준 9291 스도쿠 채점 문제. 
        9*9 격자판에서 모든 행, 열, 3*3 정사각형에 정수 1~9이 한 번씩 등장하는지 검사
    해결전략
        행과 열은 2중 for문, 3*3 정사각형은 4중 for문으로 검사한다.
        0으로 초기화된 10칸 리스트를 정답지로 활용한다.
        각 행, 열, 정사각형을 하나씩 검사할 때 발견한 정수를 인덱스로 삼아 정답지 리스트의 해당 인덱스 원소를 1로 만든다. 
        1~9까지 정수가 하나씩 존재한다면 정답지 리스트의 합이 9가 되고 중복되는 정수가 있다면 합이 9가 안된다. 
        테스트 케이스 사이마다 빈줄이 하나씩 있으므로 제거해준다.
'''
def check(a):
    for i in range(9):
        ch1 = [0] * 10
        ch2 = [0] * 10
        for j in range(9):
            ch1[a[i][j]] = 1
            ch2[a[j][i]] = 1
        if sum(ch1) != 9 or sum(ch2) != 9:
            return False
    for i in range(3):
        for j in range(3):
            ch3 = [0] * 10
            for k in range(3):
                for s in range(3):
                    ch3[a[3*i+k][3*j+s]] = 1
            if sum(ch3) != 9:
                return False
    return True

n = int(input())
for i in range(n):
    a = [list(map(int, input().split())) for _ in range(9)]
    if check(a):
        print("Case %d: CORRECT" %(i+1))
    else:
        print("Case %d: INCORRECT" %(i+1))
    if i != n-1:
        input()
