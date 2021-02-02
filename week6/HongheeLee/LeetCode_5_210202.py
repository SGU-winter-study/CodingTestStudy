'''
    문제설명
        리트코드 5 가장 긴 팰린드롬 부분 문자열
    해결전략
        기존에는 다이나믹 프로그래밍으로 이 문제를 해결했었다.
        하지만 다이나믹 프로그래밍을 이용하면 실행속도가 늦기 때문에 투포인터가 중앙을 중심으로 확장하는 형태로 풀이한다.
        홀수 개, 짝수 개 팰린드롬을 찾는 투포인터 두개를 앞에서부터 전진시켜나간다.
        문자열 시작부터 끝까지 탐색하면서 기존의 팰린드롬의 길이보다 긴 것을 발견했을 때 갱신하는 방식으로 최장 팰린드롬을 찾는다.
        또한 주어진 문자열의 길이가 1이거나 문자열을 뒤집었을 때 원래 문자열과 같다면 탐색할 필요없이 주어진 문자열이 그대로 최장 팰린드롬이 되므로 문자열을 그대로 리턴한다.
'''
class Solution(object):
    def longestPalindrome(self, s):
        def expand(left, right):
            while 0 <= left and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return s[left+1:right]
        
        if len(s) < 2 or s == s[::-1]:
            return s
        
        result = ""
        for i in range(len(s)):
            result = max(result,
                        expand(i, i+1),
                        expand(i, i+2),
                        key = len)
        return result
