'''
    문제설명
        리트코드 819 가장 흔한 단어
        금지된 단어를 제외한 가장 흔하게 등장하는 단어 출력. 대소문자 구분 없고 구두점 무시.
    해결전략
        입력값에 대한 전처리를 위해 정규식을 이용한다. \w는 단어 문자를 뜻하며 ^는 not을 의미한다. 
        따라서 사용된 정규식은 단어 문자가 아닌 모든 문자를 공백으로 치환한다는 의미이다. 
        그리고 소문자로 변환하고 공백을 기준으로 분리한다. 이 중 금지된 단어를 제외하고 리스트 컴프리핸션으로 words에 할당한다. 
        가장 많이 사용된 단어를 추출하기 위해 Counter 객체를 사용한다. 
        most_common() 메소드는 데이터 개수가 많은 순으로 정렬된 배열을 리턴한다. 인자로 숫자를 넘기면 그 숫자만큼 리턴한다.
        여기서 리턴값은 (단어, 빈도)이므로 단어를 인덱싱으로 선택한다.
'''
class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        words = [word for word in re.sub(r'[^\w]', ' ', paragraph)
                                         .lower().split() 
                                         if word not in banned]
        counts = collections.Counter(words)
        return counts.most_common(1)[0][0]
