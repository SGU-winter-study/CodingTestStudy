/*
  문제 해결 전략
  그냥 dfs, bfs.
  dfs는 스택 이용해서 방문할 노드들을 관리.
  bfs는 큐를 이용해서 방문할 노드들을 관리.
*/
import java.util.*;

public class q1260 {
    public static void main(String args[]) throws Exception{
        Map<Integer, ArrayList<Integer>> graph = new TreeMap<Integer, ArrayList<Integer>>();
        int n = 0, m = 0, v= 0;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        v = sc.nextInt();//이렇게 하면 한 줄에 입력한거 다 받을 수 있다는거 까먹어서 구글링했음.

        for(int i = 0;i<n;i++){
            graph.put(i+1,new ArrayList<>());//입력 노드가 0부터가 아니라 1부터여서 이렇게 초기화.(for문의 조건문에 = 들어가는걸 별로 안좋아해서 이렇게 코딩)
        }//초기화 해줘야지 아래의 반복문에서 nullPointException 발생하지않는다.
        
        for(int i = 0;i<m;i++){
            int n1 = 0, v1 = 0;
            n1 = sc.nextInt();
            v1 = sc.nextInt();
            graph.get(n1).add(v1);
            graph.get(v1).add(n1);//그냥 이렇게하면 되는데 추가한거 그래프에 다시 넣으려는 삽질함.
        }
        
        //dfs 에 넣어주기 전이나 bfs에 넣어주기 전에 ArrayList 정렬할 때, 처음에 init할 때랑 똑같은 index를 사용해서 해야하는데 여기서 실수.
        for(int i = 0;i<n;i++) {
            if(graph.get(i+1).isEmpty()==false) {
                Collections.sort(graph.get(i+1));
                Collections.reverse(graph.get(i+1));
            }
        }
        dfs(graph,v);
        System.out.println();
        for(int i = 0;i<n;i++) {
            if(!graph.get(i+1).isEmpty()) {
                Collections.reverse(graph.get(i+1));
            }
        }//dfs에서 사용한 순서의 역순이 필요해서 뒤집음
        bfs(graph,v);

    }

    static void bfs(Map graph,int start_node){
        Queue<Integer> need_visit = new LinkedList<>();
        Queue<Integer> visited = new LinkedList<>();
        need_visit.add(start_node);//시작노드 방문처리

        while(need_visit.isEmpty()==false){
            int node = need_visit.poll();
            if(!visited.contains(node)){
                visited.add(node);
                ArrayList<Integer> temp = (ArrayList<Integer>) graph.get(node);
                for(int data : temp) need_visit.add(data);
            }//다음으로 방문해야할 node가 처음 방문하는 곳이라면 visited에 추가하고 그 노드에서 갈 수 있는 노드들 need_visit에 추가
        }//모든 노드 방문할 때까지 반복문 돌림
        for(int data : visited)System.out.print(data+" ");
    }

    static void dfs(Map graph,int start_node){
        Stack<Integer> visited = new Stack<>();
        Stack<Integer> need_visit = new Stack<>();
        need_visit.push(start_node);

        while(need_visit.isEmpty()==false){
            int node = need_visit.pop();
            if(visited.contains(node)==false){
                visited.add(node);
                ArrayList<Integer> temp = (ArrayList<Integer>) graph.get(node);
                for(int data : temp) need_visit.push(data);
            }//다음으로 방문해야할 node가 처음 방문하는 곳이라면 visited에 추가하고 그 노드에서 갈 수 있는 노드들 need_visit에 추가
        }//모든 노드 방문할 때까지 반복문 돌림
        for(int data : visited)System.out.print(data+" ");

    }


}
