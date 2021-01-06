#include <bits/stdc++.h>
using namespace std;
/*
	오타하나를 못찾아서 1시간 헤맨 문제..ㅠㅠ
	
	알고리즘은 간단하다. 
	스택이 비어있지 않고, 스택의 가장 윗 값의 가격이 현재 들어오는 가격보다 큰경우
	가격이 떨어진 것이기 때문에, 그 값을 끄집어내고 해당 가격이 떨어지지 않은 기간과 인덱스를
	정답 벡터로 반환한다.
	
	사람들 풀이보니 인덱스 값을 적절히 활용해서 더 간단하게 할 수  있는 듯. 
*/
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int,int>> ans;
    stack<pair<int,int>> S;
    for(int i=0;i<prices.size();i++){
        if(!S.empty()&&S.top().second>prices[i]){
            while(!S.empty()&&S.top().second>prices[i]){
                auto cur=S.top();
                ans.push({cur.first,i-cur.first});
                S.pop();
            }
        }
        S.push({i,prices[i]});
    }
    while(!S.empty()){
        auto cur=S.top();
        ans.push({cur.first,int(prices.size())-1-cur.first});
        S.pop();
    }
    while(!ans.empty()){
        answer[ans.top().first]=ans.top().second;
        ans.pop();
    }
    return answer;
}
