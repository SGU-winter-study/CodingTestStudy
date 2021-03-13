'''
    문제설명
        리트코드 17 전화번호 문자 조합
        2에서 9까지 숫자가 주어졌을 때 전화 번호로 조합 가능한 모든 문자 출력
    해결전략
        모든 경우의 수를 DFS로 탐색하고 백트래킹으로 결과를 조합하면서 리턴한다.
        DFS 함수는 자릿수가 입력과 동일할 때까지 재귀 호출을 반복하다 끝까지 탐색하면 결과를 추가하고 리턴한다.
'''
class Solution(object):
    def letterCombinations(self, digits):
        res = []
        match = {
            "2" : "abc",
            "3" : "def",
            "4" : "ghi",
            "5" : "jkl",
            "6" : "mno",
            "7" : "pqrs",
            "8" : "tuv",
            "9" : "wxyz"
        }
        
        def DFS(L, comb):
            if L == len(digits):
                res.append(comb)
            else:
                for x in match[digits[L]]:
                    DFS(L+1, comb+x)
                
        if len(digits) == 0:
            return res
        else:
            DFS(0, "")
        return res
