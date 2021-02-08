'''
    문제설명
        백준 2108 통계학 (정렬이용)
        산술평균, 중앙값, 최빈값, 범위 출력
    해결전략
        주어진 입력을 리스트에 받고 오름차순 정렬한다(팀소트)
        산술평균은 리스트 전체의 합 / 입력의 개수
        중앙값은 정렬한 리스트의 개수를 2로 나눈 몫을 인덱스로 리스트에 접근한다.
        최빈값은 Counter 객체를 이용한다. most_common()을 메소드를 이용하면 데이터 개수가 많은 순으로 정렬된 배열을 리턴한다.
        그 배열의 길이가 1보다 크고 첫번째, 두번째 원소의 데이터의 개수가 같으면 두번째 값을 출력, 다르면 첫번째 값을 출력, 길이가 1이면 첫번째 값을 출력한다.
        범위는 리스트의 최댓값에서 최솟값을 뺀다.
'''
import sys
import collections
input = sys.stdin.readline

n = int(input())
nums = []
for _ in range(n):
    nums.append(int(input()))
nums.sort()
print(round(sum(nums) / len(nums)))
print(nums[len(nums) // 2])
cnt = collections.Counter(nums).most_common()
if len(cnt) > 1:
    if cnt[0][1] == cnt[1][1]:
        print(cnt[1][0])
    else:
        print(cnt[0][0])
else:
    print(cnt[0][0])
print(max(nums) - min(nums))
