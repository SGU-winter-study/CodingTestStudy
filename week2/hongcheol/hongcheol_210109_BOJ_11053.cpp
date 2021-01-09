'''
정말 간단한 dp 문제였다.
출력 과정에서 최댓값 계산하는 구문을 복붙했는데 잘못 복붙한지도 모르고 i,j 영역을 수정해보면서 채점했더니 계속 실패뜨다가 처음부터 차근차근 살펴본 결과
최댓값 구하는 부분에서 잘못된 변수에 대입을 하고있었다.
실수가 많은 것 같다. 복붙할 때는 좀 더 꼼꼼히 살피거나 함수로 따로 빼는 습관을 꼭 만들어야겠다.
'''

#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d",&n);
    int a[1001] = {0,};
    int d[1001] = {0,};
    for(int i = 0;i<n;i++) scanf("%d",&a[i]);
    for(int i = 0;i<n;i++){
        d[i] = 1;
        for(int j = 0;j<i;j++) if (a[j]<a[i]) d[i] = d[i]<d[j]+1 ? d[j]+1 : d[i];    
    }
    int ans = 0;
    for(int i = 0;i<n;i++)ans = ans<d[i]?d[i]:ans; 
    printf("%d",ans);
}
