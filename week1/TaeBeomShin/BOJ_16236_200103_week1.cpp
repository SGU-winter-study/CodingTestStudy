/*
 삼성 SW 기출 문제 - 아기상어(BFS + 구현)
 
 문제에 나와있는 그대로 BFS를 이용해서 구현하면 되는 문제이다.
 문제에 사용되는 알고리즘은 심플한데, 문장을 몇개씩 빼먹어서 푸는데 오래 걸리긴 했지만
 아무것도 참고안하고 풀어서 뿌듯하다..
  
*/
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[21][21];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
	int n;cin>>n;
	pair <int,int> size={2,0},pos;
	vector<pair<int,int>> fish;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>board[i][j];
			if(board[i][j]==9){
				pos={i,j};
			}else if(board[i][j]>=1){
				fish.push_back({i,j});
			}
		}
	}

	int ans=0;
	while(!fish.empty()){
		int mdist=1000;//최소거리.
		int midx;
		pair <int,int> next; //다음 목적지 
		
		for(int i=0;i<fish.size();i++){
			auto f=fish[i];
			int x=f.X,y=f.Y;
			//상어의 크기가 더 큰지 체크.
			//크기가 같은 물고기는 먹을 수 없다(목적지가 될 수 없다.) 
			if(size.X<=board[x][y]) continue;
			//상어가 더 크다면 거리를 구한다. 
			
			queue<pair<int,int>> Q;
			bool visited[n][n]={0,};//방문 여부 확인.
			visited[pos.X][pos.Y]=true;
			int dist[n][n]={0,};
			
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++){
					visited[i][j]=false;
					dist[i][j]=1000;
				}
			
			Q.push(pos);//현재 위치 넣는다.
			dist[pos.X][pos.Y]=0;
			
			while(!Q.empty()){
				auto cur=Q.front();Q.pop();		
				for(int dir=0;dir<4;dir++){
					int nx=cur.X+dx[dir],ny=cur.Y+dy[dir];
					//지도를 벗어나면 못 이동함. 
					if(nx<0||ny<0||nx>=n||ny>=n) continue;
					// 더 큰 상어가 길목에 있으면 못 이동함. 
					if(size.X<board[nx][ny]) continue;
					// 이미 방문한 곳이면 안지나감.
					if(visited[nx][ny]) continue;
					Q.push({nx,ny});
					dist[nx][ny]=min(dist[nx][ny],dist[cur.X][cur.Y]+1);
					visited[nx][ny]=true;
				}
			}
			//5-1. 거리는 아기 상어가 있는 칸에서 지나야하는 칸의 갯수의 최솟값이다.
			if(dist[x][y]<mdist){		
				next={x,y};
				mdist=dist[x][y];
				midx=i;
			}else if(dist[x][y]==mdist){
			//5-2. 거리가 가까운 물고기 많다면 가장 위에 있는 물고기, 여러마리면 가장 왼쪽의 물고기
				if(x<next.X){
					next={x,y};
					mdist=dist[x][y];
					midx=i;
				}else if(x==next.X){
					if(y<next.Y){
						next={x,y};
						mdist=dist[x][y];
						midx=i;
					}
				}
			}
		}
/*
		1. 목적지의 원소를 삭제한다.
		2. board를 바꿔준다. -> 현재 물고기가 있는 위치를 0, 이동한 위치를 9로 변경.
		3. ans에 mdist만큼 더해준다. 
		4. 물고기 크기를 바꿔준다. 
*/		
		if(mdist==1000){//더이상 혼자 해결할 수 없음. 
			break;
		}
		
		fish.erase(fish.begin()+midx);
		board[next.X][next.Y]=9;
		board[pos.X][pos.Y]=0;
		pos=next;
		ans+=mdist;
		
		//자신의 크기와 같은 수의 물고기를 먹으면 크기가 1증가
		size.Y++;
		if(size.Y==size.X){
			size.X++;
			size.Y=0;
		}

	}
	cout<<ans;

}
