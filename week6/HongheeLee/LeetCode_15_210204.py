''' 
    문제 설명
        리트코드 15 세 수의 합
        배열을 입력 받아 합으로 0을 만들 수 있는 3개의 엘리먼트 출력
    해결 전략
        처음 봤을 때는 브루트 포스로 계산하는 방식을 택했다.
        3중 for문을 돌면서 세 수의 합이 0이 되는 값을 찾고 그게 결과 리스트에 없으면 추가하는 방식으로. 
        그런데 그러면 O(n^3) 정도가 걸려서 시간 초과가 발생했다.
        그래서 다른 풀이로는 i를 축으로 하고 나머지 두 값을 투포인터로 합을 계산하는 방식으로 풀이할 수 있었다.
        i를 축으로 하고 중복된 값이 있을 수 있으므로 continue를 이용해 건너 뛴다. 
        left는 i의 다음 지점, right는 마지막 지점으로 설정하고 간격을 좁혀가며 sum을 계산한다. 
        nums는 정렬되어 있으므로 sum이 0보다 작으면 left를 오른쪽으로 이동하고 0보다 크면 right를 왼쪽으로 이동한다.
        0이 되면 결과 리스트에 값을 추가하고 left, right 양 옆으로 동일한 값이 있을 수 있으므로 left += 1, right -= 1을 반복해서 스킵하도록 한다.
        마지막으로 left를 한 칸 우측으로, right를 한 칸 좌측으로 이동하고 다음으로 넘긴다.
'''
# 내 브루트포스 풀이
class Solution(object):
    def threeSum(self, nums):
        nums.sort()
        res = []
        for i in range(len(nums)):
            tot = 0
            for j in range(i+1, len(nums)):
                for k in range(j+1, len(nums)):
                    if nums[i] + nums[j] + nums[k] == 0:
                        if [nums[i], nums[j], nums[k]] not in res:
                            res.append([nums[i], nums[j], nums[k]])
        return res

# 책에서 브루트포스 풀이 (중복 제거하는 방식이 다름)
class Solution(object):
    def threeSum(self, nums):
        nums.sort()
        res = []
        
        # 브루드포스 n^3 반복
        for i in range(len(nums) - 2):
            #중복된 값 건너뛰기
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, len(nums) - 1):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                for k in range(j + 1, len(nums)):
                    if k > j + 1 and nums[k] == nums[k - 1]:
                        continue
                    if nums[i] + nums[j] + nums[k] == 0:
                        res.append([nums[i], nums[j], nums[k]])
        return res

# 책에서 투포인터의 합 이용한 풀이
class Solution(object):
    def threeSum(self, nums):
        nums.sort()
        res = []
        
        for i in range(len(nums) - 2):
            #중복된 값 건너뛰기
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            left, right = i + 1, len(nums) - 1
            while left < right:
                sum = nums[i] + nums[left] + nums[right]
                if sum < 0:
                    left += 1
                elif sum > 0:
                    right -= 1
                else:
                    #sum이 0인 경우, 결과를 리스트에 추가한다. 그리고 중복 무시하면서좌우포인터이동
                    res.append([nums[i], nums[left], nums[right]])
                    
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
        return res
