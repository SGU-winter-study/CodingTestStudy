'''
리스트로 하면 풀리는데, heapq를 이용해서 배열에 저장한 경우에는 틀리다고 나왔다.
틀렸던 이유는 heapq를 이용했을 때는, 최소힙으로 사용하려면 heappop()으로 꺼내야하는데
그냥 저장된 순서로 했기 때문에 틀린 결과가 나왔다.

'''
import heapq
import math

N = int(input())
arr =[]
gcd = 0
for i in range(N):
    arr.append(int(input()))
    if i == 1:
       gcd = abs(arr[1]-arr[0])
    gcd = math.gcd(abs(arr[i]-arr[i-1]),gcd) 
ans = []
root_gcd = int(gcd**0.5)
for i in range(2,root_gcd+1):
    if gcd % i == 0:
        heapq.heappush(ans,i)
        if gcd//i != i:
            heapq.heappush(ans,gcd//i)

while ans:
    print(heapq.heappop(ans),end= ' ')
print(gcd,end='')

