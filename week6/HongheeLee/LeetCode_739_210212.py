'''
    문제설명
        리트코드 739 일일 온도(스택 이용)
        매일의 화씨 온도 리스트를 입력받고 더 따뜻한 날씨를 위해서는 며칠을 더 기다려야 하는지 출력
    해결전략
        현재의 인덱스를 계속 스택에 쌓아두다가, 이전보다 상승하는 지점에서 현재 온도와 스택에 쌓아둔 인덱스 지점의 온도 차이를 비교해서,
        더 높다면 스택의 값을 팝으로 꺼내고 현재 인덱스와 스택에 쌓아둔 인덱스의 차이를 정답으로 처리한다.
        만약 더 높은 온도가 나오지 않아 스택이 비워지지 않았다면 해당 인덱스의 답은 0으로 남게 된다.
        문제를 처음 봤을 때는 예제를 그래프 형태로 표현해보면 입력에 대한 정답이 어떤 방식으로 도출되는지 더 쉽게 파악할 수 있다.
        빗물 트래킹 문제와도 유사하다.
'''
class Solution(object):
    def dailyTemperatures(self, T):
        answer = [0] * len(T)
        stack = []

        for i, cur in enumerate(T):
            # 현재 온도가 스택의 top 값보다 크면 정답처리한다.
            while stack and T[stack[-1]] < cur:
                last = stack.pop()
                answer[last] = i - last
            stack.append(i)
        return answer
