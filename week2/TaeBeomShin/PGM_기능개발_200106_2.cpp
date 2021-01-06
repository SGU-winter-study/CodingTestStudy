#include <bits/stdc++.h>
using namespace std;
/*
 	큐의 간단한 응용.
	 
	자료구조 응용문제는 보통 스택 문제였는데, 큐를 응용한 문제여서 새롭다.
	
	로직은 간단하다. 
	1. queue에 우선순위 순서대로 종료일자를 집어넣어준다. 
	2. Q.front()를 살펴보며 최상위 우선순위보다 개발일자가 앞이거나 같을 경우까지 진행한다.
	3. 더 뒷 개발일자가 나오면 pop하고 다음 Q.front()로 넘어간다.
	4. 배포별 기능 갯수를 저장한다. (반복) 
*/
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Q;
    int size=speeds.size();
    
    for(int i=0;i<size;i++){
        int day=int(ceil((double)(100-progresses[i])/speeds[i]));
        Q.push(day);
    }
    while(!Q.empty()){
        int num=Q.front();
        int count=1;
        Q.pop();
        while(!Q.empty()){
            if(Q.front()<=num){
                count++;
                Q.pop();
            }else{
                break;
            }
        }
        answer.push_back(count);
    }
    return answer;
}
