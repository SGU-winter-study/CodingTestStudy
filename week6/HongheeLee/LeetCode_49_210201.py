'''
    문제설명
        리트코드 49 그룹 애너그램
        문자열 배열을 받아 애너그램 단위로 그룹핑하라
    해결전략
        애너그램을 판단하기 위해서 정렬하여 비교하는 방법을 택했다. 
        애너그램 관계인 단어들은 정렬하면 서로 같은 값을 갖기 때문이다.
        sorted()는 문자열을 정렬하고 정렬한 결과를 리스트로 리턴하는데 이를 다시 딕셔너리의 키로 사용하기 위해 join()으로 합쳤다.
        애너그램끼리는 같은 키를 갖게 되고 여기에 append하는 형태로 구성했다. 
        존재하지 않는 키를 삽입하면 KeyError가 발생하므로 에러가 나지 않도록 디폴트를 생성해주는 defaultdict()로 선언했다.
'''
class Solution(object):
    def groupAnagrams(self, strs):
        anagrams = collections.defaultdict(list)
        
        for word in strs:
            # 정렬해서 딕셔너리에 추가
            anagrams[''.join(sorted(word))].append(word)
        return anagrams.values()
