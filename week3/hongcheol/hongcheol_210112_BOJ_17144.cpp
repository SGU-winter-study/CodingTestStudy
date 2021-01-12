'''
https://www.acmicpc.net/problem/17144
시뮬레이션해본 결과를 만들어내는 문제였다.
입력의 크기가 최대 2500이여서 O(N^2)알고리즘을 써도 괜찮을 것이라 판단했고, 그 이후에는 문제에서 주어진대로
차근차근 한단계씩 구현했다.

중간에 증감문에서 연산자를 잘못써서 bus error를 만들었는데 금방 고쳤다.
노트에다가 쓰고 그걸 구현해서 한 번에 통과할 수 있었던 문제였다.

'''

#include <stdio.h>
#include <stdlib.h>

int room[50][50] = {0,};
int afterWind[50][50] = {0,};
int R = 0, C = 0;
int airR0 = 0, airC0 = 0;
int airR1 = 0, airC1 = 0;
void isSide(int r,int c);
void spread(int r,int c);
void upperWind();
void lowerWind();
int cleanDust = 0;
int arr[4] = {0,0,0,0};
int main(){
    int T = 0;
    int airCondNum = 0;
    int totalDust = 0;
    scanf("%d %d %d",&R, &C, &T);
    //input처리하면서 청정기 위치 저장
    for(int r = 0;r<R;r++){
        for(int c = 0;c<C;c++){
            scanf("%d",&room[r][c]);
            if(room[r][c] != -1) totalDust += room[r][c];
            if(room[r][c] == -1){
                if(airCondNum == 0){
                    airR0 = r;
                    airR1 = r+1;
                    airCondNum++;
                }
            }
        }
    }
    for(int t = 0;t<T;t++){
        for(int r = 0;r<R;r++){
            for(int c = 0;c<C;c++){
                if(room[r][c] > 0)spread(r,c);
            }
        }
        for(int r = 0;r<R;r++){
            for(int c = 0;c<C;c++){
                if(room[r][c] == -1)continue;
                room[r][c] += afterWind[r][c];
                afterWind[r][c] = 0;
            }
        }
        upperWind();
        lowerWind();
    }
    
    printf("%d",totalDust-cleanDust);
}
void isSide(int r,int c){
    if(r == 0){
        if(c == 0){
            arr[0]=1;
            arr[1]=0;
            arr[2]=0;
            arr[3]=1;
        }
        else if(c == C-1){ 
            arr[0]=0;
            arr[1]=0;
            arr[2]=1;
            arr[3]=1;
        }
        else{
            arr[0]=1;
            arr[1]=0;
            arr[2]=1;
            arr[3]=1;
        }
    }
    else if(r == R-1){
        if(c == 0){
            arr[0]=1;
            arr[1]=1;
            arr[2]=0;
            arr[3]=0;
        }
        else if(c == C-1){
            arr[0]=0;
            arr[1]=1;
            arr[2]=1;
            arr[3]=0;
        }
        else{
            arr[0]=1;
            arr[1]=1;
            arr[2]=1;
            arr[3]=0;
        }
    }
    else{
        if(c == 0){
            arr[0]=1;
            arr[1]=1;
            arr[2]=0;
            arr[3]=1;
        }
        else if(c == C-1){
            arr[0]=0;
            arr[1]=1;
            arr[2]=1;
            arr[3]=1;
        }
        else{
            arr[0]=1;
            arr[1]=1;
            arr[2]=1;
            arr[3]=1;
        }
    }
    
}
void spread(int r,int c){
    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    isSide(r,c);
    int spreadDust = 0;
    for(int i = 0;i<4;i++){
        if(arr[i] == 1){
            if(room[r+dir[i][0]][c+dir[i][1]] == -1) continue;
            afterWind[r+dir[i][0]][c+dir[i][1]] += room[r][c]/5;
            spreadDust += room[r][c]/5;
        }
    }
    room[r][c] -= spreadDust;
}
void upperWind(){
    //윗쪽 공기청정기로인한 공기순환
    for(int r = airR0-1;r>-1;r--){
        if(r == airR0-1) cleanDust += room[r][0];
        else room[r+1][0] = room[r][0];
        }
    
    for(int c = 1;c<C;c++) room[0][c-1] = room[0][c];
    for(int r = 0; r<airR0;r++) room[r][C-1] = room[r+1][C-1];
    for(int c = C-1;c>1;c--) room[airR0][c] = room[airR0][c-1];
    room[airR0][1] = 0; 
}
void lowerWind(){
    for(int r = airR1+1;r<R;r++){
        if(r == airR1+1) cleanDust += room[r][0];
        else room[r-1][0] = room[r][0];
    }
    for(int c = 0;c<C-1;c++) room[R-1][c] = room[R-1][c+1];
    for(int r = R-1; r>airR1;r--) room[r][C-1] = room[r-1][C-1];
    for(int c = C-1;c>1;c--) room[airR1][c] = room[airR1][c-1];
    room[airR1][1] = 0;   
}
