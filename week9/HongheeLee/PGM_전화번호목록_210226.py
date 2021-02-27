'''
    문제설명
        프로그래머스 전화번호목록
        주어진 전화번호 중 다른 전화번호를 접두사로 쓰는 번호가 있으면 False 없으면 True를 반환한다.
    해결전략
        1. 정렬과 zip(), startswith()을 이용해서 해결할 수 있다.
            문자열을 정렬하면 가장 앞에를 기준으로 정렬된다.
            (0번 인덱스부터 ~ 마지막에서 하나 앞 인덱스까지 + 1번 인덱스부터 마지막 인덱스까지) 동일한 크기의 리스트를 zip해서 쌍으로 묶어준다.
            정렬되었기 때문에 근처끼리만 startswith()으로 검사해줘도 결과를 얻을 수 있다.
        2. 해시를 이용한 비교를 통해 해결할 수 있다.
            전화번호를 키로 딕셔너리를 만든다.
            다시 전화번호를 하나씩 꺼내고 그 번호에서도 한자리씩 추가해가면서 그것이 딕셔너리의 키로 존재하는지 그리고 그게 해당 번호와 다를 떄 False로 반환한다.
            이런 경우가 아니면 True 반환한다.
'''
def solution(phone_book):
    phone_book.sort()
    for p1, p2 in zip(phone_book[:-1], phone_book[1:]):
        if p2.startswith(p1):
            return False
    return True

def solution(phone_book):
    answer = True
    hash = dict()

    for num in phone_book:
        hash[num] = 1
    
    for num in phone_book:
        tmp = ""
        for n in num:
            tmp += n
            if tmp in hash and tmp != num:
                answer = False
    return answer
