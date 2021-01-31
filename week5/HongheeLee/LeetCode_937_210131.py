'''
    문제설명
        리트코드 937 로그파일 재정렬
        아래 네 가지 조건에 따라 로그파일 재정렬한다.
        로그의 가장 앞 부분 식별자다.
        문자로 구성된 로그가 숫자 로그보다 앞에 온다.
        식별자는 순서에 영향을 끼치지 않지만 문자가 동일할 경우 식별자 순으로 한다.
        숫자 로그는 입력 순서대로 한다.
        입력 예시 ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
    해결전략
        주어진 로그들을 하나씩 읽으며 isdigit()으로 판단해 숫자로그면 순서대로 모아두고 
        문자로그면 따로 모은 뒤 람다식으로 문자로 정렬, 동일하면 식별자로 정렬되도록 한다.
        문자로그 모음과 숫자로그 모음을 합쳐서 return한다.
'''
class Solution(object):
    def reorderLogFiles(self, logs):
        letters, digits = [], []
        for log in logs:
            if log.split()[1].isdigit():
                digits.append(log)
            else:
                letters.append(log)
        letters.sort(key = lambda x : (x.split()[1:], x.split()[0]))
        return letters + digits
