'''
    문제 설명
        리트코드 347 상위 K 빈도요소
    해결전략
        1. Counter를 이용한 음수 순 추출
            요소의 값을 키로 하는 해시 테이블을 만들고 여기에 빈도수를 저장한 다음 우선순위 큐를 이용해 k번만큼 추출한다.
            우선순위 큐는 heapq 모듈을 사용하고 빈도수는 collections.Counter를 이용한다.
            최소 힙에 넣을 때는 빈도수를 키로 하고 숫자를 값으로 했다. 힙은 키 순서대로 정렬되기 때문에 빈도 수를 키로 한다.
            또한 이를 음수로 저장했는데 기본적으로 heapq 모듈은 최소 힙만 지원하기 때문에 음수로 변환해 가장 빈도 수가 높은 값이 가장 큰 음수가 되게 한다.
'''
class Solution(object):
    def topKFrequent(self, nums, k):
        freqs = collections.Counter(nums)
        freqs_heap = []

        # 힙에 음수로 삽입
        for f in freqs:
            heapq.heappush(freqs_heap, (-freqs[f], f))
        
        topk = list()
        # k번 만큼 추출, 최소힙이므로 가장 작은 음수 순으로 추출
        for _ in range(k):
            topk.append(heapq.heappop(freqs_heap)[1])

        return topk

'''
        2. 파이썬다운 방식
            Counter에는 빈도수가 높은 순서대로 아이템을 추출하는 most_common() 메소드가 있다.
            zip() 함수는 2개 이상의 시퀀스를 짧은 길이를 기준으로 일대일 대응하는 새로운 튜플 시퀀스를 만드는 역할을 한다. 
            파이썬 3에서는 zip()의 결과로 제너레이터를 리턴해서 실젯값을 추출하기 위해선 list()로 묶어줘야 한다.
'''
class Solution(object):
    def topKFrequent(self, nums, k):
        return list(zip(*collections.Counter(nums).most_common(k)))[0]
