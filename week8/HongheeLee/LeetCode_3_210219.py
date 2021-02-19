'''
    문제설명
        리트코드 3 중복 문자 없는 가장 긴 부분 문자열
    해결전략
        슬라이딩 윈도우와 투 포인터로 사이즈 조절하며 풀이한다.
        포인터 2개 모두 왼쪽에서 출발한다(start, index)
        주어진 문자열에서 문자를 하나씩 확인하며 이미 등장한 문자라면 used에 있을 것이고 이 떄 start 포인터를 used[char]+1 위치로 갱신한다.
        처음 보는 문자라면 매번 max()로 부분 문자열의 길이를 확인하면서 더 크면 max_length를 갱신한다.
        used[char]는 현재 문자를 키로 하는 해시 테이블이며 value로는 현재 위치를 삽입한다. 
        또한 이미 등장한 문자가 다시 등장했다고 다 start 위치를 갱신하는게 아니라 현재 슬라이딩 윈도우 바깥에 있는 문자는 무시해야한다. 
'''
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        used = {}
        max_length = start = 0
        for index, char in enumerate(s):
            # 이미 등장했던 문자라면 'start' 위치 갱신
            if char in used and start <= used[char]:
                start = used[char] + 1
            else: # 최대 부분 문자열 길이 갱신
                max_length = max(max_length, index - start + 1)
            
            # 현재 문자의 위치 삽입
            used[char] = index

        return max_length
