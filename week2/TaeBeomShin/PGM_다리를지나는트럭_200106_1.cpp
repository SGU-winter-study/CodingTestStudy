#include<bits/stdc++.h>
using namespace std;
/*
	다리에 올라갈 수 없는 트럭이 나오면 초를 증가 시켜주고
	마지막 트럭이 올라오면 다리의 길이만큼 초를 더해서 정답을 반환한다. 
*/
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer=0,sum=0,idx=0;
    queue<int> Q;
    
    while(true){
        if(idx==truck_weights.size()){
            answer+=bridge_length;
            break;
        }
        answer++;
        
        int temp=truck_weights[idx];
        
        if(Q.size()==bridge_length){
            sum-=Q.front();
            Q.pop();
        }
        if(sum+temp<=weight){
            Q.push(temp);
            sum+=temp;
            idx++;
        }else{
            Q.push(0);
        }
    }
    return answer;
} 
