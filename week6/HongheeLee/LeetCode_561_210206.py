'''
    문제설명 
        리트코드 561 배열 파티션1
        n개의 페어를 이용한 min(a,b)의 합으로 만들 수 있는 가장 큰 수를 출력
    해결전략
        min(a, b)가 되도록 커야한다. 이를 위해서는 주어진 nums를 정렬하는 것이 중요하다.
        min(a, b)를 이룰 수 있는 경우는 다양하지만 결국 정렬하고 앞에서부터 오름차순으로 인접 요소 페어를 만들면 
        이 페어들의 합이 곧 만들 수 있는 최대 합이 된다.
'''
# 오름차순 풀이
class Solution(object):
    def arrayPairSum(self, nums):
        nums.sort()
        sum = 0 
        pair = []

        for n in nums:
            pair.append(n)
            if len(pair) == 2:
                sum += min(pair)
                pair = []
        return sum

# 짝수 번째 값 계산
class Solution(object):
    def arrayPairSum(self, nums):
        nums.sort()
        sum = 0

        for i, n in enumerate(nums):
            if i % 2 == 0:
                sum += n
        return sum

# 파이썬스러운 방식
class Solution(object):
    def arrayPairSum(self, nums):
        return sum(sorted(nums)[::2])
