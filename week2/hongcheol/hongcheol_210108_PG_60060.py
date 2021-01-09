'''
https://programmers.co.kr/learn/courses/30/lessons/60060
카카오 블라인드 2020 가사검색문제.
트라이를 이용해서 풀이를 진행.
총 3번의 대대적인 공사를 통해서 효율성까지 통과.
#1
트라이에서 검색을 할 때, 현재 사용하는 쿼리문의 길이를 검색해서 사용.(데이터의 갯수가 늘어나고 길이가 길어지면 그만큼의 불필요한 시간이 증가함)
#2
그래서 트라이 노드에 딕셔너리를 defaultdict(int)로 초기화해서 검색함수 호출할 때, 넘겨받은 길이를 이용해서 저장을 함.
그랬더니 효율성테스트 2문제를 제외하고 정답이 나왔음.
#3
그래도 시간이 줄어들지않아서 무엇이 문제일까 생각을 해봤는데, 처음부터 트라이를 입력받은 word의 길이에 따라서 각각 생성해놓은 다음. 그 길이에 해당하는 트라이만 탐색하면 된다는 결론을 냈다.
이런 방식을 선택한 결과 트라이에서 검색을 할 때, 길이가 5인 문자에대한 검색을 할 때, 길이가 5가 아닌 문자들에대해서도 검사하는 것을 줄일 수 있었다.

'''

class Node(object):
    def __init__(self):
        self.child = {}
        self.cnt = 0
        
class Trie(object):
    def __init__(self):
        self.root = Node()
    
    def insert(self,string):
        cur_node = self.root
        #cur_node.cnt += 1
        for char in string:
            
            if char not in cur_node.child:
                cur_node.child[char] = Node()
            cur_node = cur_node.child[char]
            cur_node.cnt += 1
            
        # string의 마지막 글자가 나오면 data 필드에 저장하려는 문자열 전체를 저장
        cur_node.data = string
        
    def start_with(self,prefix):
        result = 0
        '''
        if prefix == '':
            for count in self.root.child.values():
                result += count.cnt
            return result
        '''
        node = self.root
        for char in prefix:
            if node.child.get(char):
                node = node.child[char]
                result = node.cnt
            else:
                return 0
        
        return node.cnt

def solution(words, queries):
    answer = []
    #처음에는 접미사, 접두사 트라이를 하나씩만 이용할 계획이였는데
    #그렇게되면 효율성 측면에서 너무 복잡한 결과가 나왔다.
    #그래서 길이에 따른 트라이를 구성해서 문제풀이를 진행했다.
    #ㄴ 문제에서 트라이에서 검색을 실행할 때, 어차피 문자열의 길이를 계산한 후에 넘겨주는 점에서 착안
    postfixSet = [Trie() for i in range(10001)]
    prefixSet = [Trie() for i in range(10001)]
    for word in words:
        l = len(word)
        postfixSet[l].insert(word[::-1])
        prefixSet[l].insert(word)
    
    for query in queries:
        l = len(query)
        if query == '?'*l:
            result = 0
            for count in postfixSet[l].root.child.values():
                result += count.cnt
            answer.append(result)
        elif query[0] == '?':
            post = query[::-1].split('?')[0]
            answer.append(postfixSet[l].start_with(post))
        else:
            pre = query.split('?')[0]
            answer.append(prefixSet[l].start_with(pre))
            
    return answer
