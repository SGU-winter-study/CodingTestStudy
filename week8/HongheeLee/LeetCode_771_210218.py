'''
    문제설명 
        리트코드 771 보석과 돌
    해결전략
        해시 테이블을 이용한 풀이, defaultdict을 이용한 풀이, Counter를 이용한 풀이, 파이썬다운 방식으로 풀이 4가지 방식으로 풀어보았다.
'''
# 해시 테이블을 이용한 기본 풀이ㅣ
class Solution(object):
    def numJewelsInStones(self, jewels, stones):
        freqs = {}
        cnt = 0
        
        # 돌의 빈도수 계산
        for char in stones:
            if char not in freqs:
                freqs[char] = 1
            else:
                freqs[char] += 1
        
        # 보석의 빈도수 합산
        for char in jewels:
            if char in freqs:
                cnt += freqs[char]
        return cnt

# defaultdict을 이용한 비교 생략
class Solution(object):
    def numJewelsInStones(self, jewels, stones):
        freqs = collections.defaultdict(int)
        cnt = 0
        
        # 비교 없이 돌 빈도수 계산
        for char in stones:
            freqs[char] += 1
        
        # 비교 없이 보석 빈도수 합산
        for char in jewels:
            cnt += freqs[char]
            
        return cnt

# Counter로 계산 생략
class Solution(object):
    def numJewelsInStones(self, jewels, stones):
        freqs = collections.Counter(stones) # 돌 빈도수 계산
        cnt = 0
        # 비교 없이 보석 빈도수 합산
        for char in jewels:
            cnt += freqs[char]
        return cnt

# 파이썬다운 방식(리스트 컴프리헨션, for문과 비교 구문), 결과는 True의 개수
class Solution(object):
    def numJewelsInStones(self, jewels, stones):
        return sum(s in jewels for s in stones)
