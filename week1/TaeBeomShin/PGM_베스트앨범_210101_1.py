'''
프로그래머스 Hash 연습
https://programmers.co.kr/learn/courses/30/lessons/42579 베스트앨범 문제

정렬 + 딕셔너리(해쉬)를 이용한 간단한 구현
1.가장 많이 들은 장르 순서대로 저장
2.저장된 장르에 해당하는 노래 중 실행횟수가 많은 노래먼저 저장
3.저장된 결과 반환
파이썬의 key=lambda 함수를 통해 정렬기준 변경 ( C++의 greater과 유사)
'''


def solution(genres, plays):
    dict = {}
    for i in range(len(genres)):
        if genres[i] in dict:
            dict[genres[i]] += plays[i]
        else:
            dict[genres[i]] = plays[i]
    dict = sorted(list(dict.items()), key=lambda x: x[1], reverse=True)
    songs = []
    for d in dict:
        songs.append(d[0])

    answer = []
    for song in songs:
        temp = []
        for i in range(len(genres)):
            if (song == genres[i]):
                temp.append([i, plays[i]])
        temp.sort(key=lambda x: x[1], reverse=True)
        for i in range(len(temp)):
            if (i > 1): break
            answer.append(temp[i][0])

    return answer