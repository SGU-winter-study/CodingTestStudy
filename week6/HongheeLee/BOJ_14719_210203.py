'''
    문제설명 
        백준 14719 빗물
        높이를 입력받아 비 온 후 얼마나 많은 물이 쌓일 수 있는지 계산.
    해결전략
        투포인터를 이용한다. 
        최대 높이의 막대까지 각각 좌우 기둥 최대 높이 left_max, right_max와 현재 높이와의 차이만큼 물 높이를 더해간다.
        투 포인터는 양 끝 점에서 시작해서 최대 높이를 향해서 이동해간다.
        좌우 기둥의 최대 높이를 비교해서 오른쪽이 크면 left 포인터를 이동하고 왼쪽이 크면 right 포인터를 이동한다. 
        이동 후에는 좌우 기둥 최대 높이를 갱신한다.
        결국에는 가장 높이가 높은 막대에서 좌우 포인터가 서로 만나며 탐색이 종료된다. 
'''
def rain(height):
    if len(height) <= 1:
        print(0)
        return

    volume = 0
    left, right = 0, len(height) - 1
    left_max, right_max = height[left], height[right]

    while left < right:
        left_max, right_max = max(left_max, height[left]), max(right_max, height[right])
        if left_max <= right_max:
            volume += left_max - height[left]
            left += 1
        else:
            volume += right_max - height[right]
            right -= 1
    print(volume)

h, w = map(int, input().split())
height = list(map(int, input().split()))
rain(height)
