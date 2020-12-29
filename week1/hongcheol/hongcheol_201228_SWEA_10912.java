/*
    삼성 SW Expert Academy D3 10912 외로운 문자
    문제 출처 :https://swexpertacademy.com/main/code/problem/problemDetail.do
*/    
/*
    해결 전략
      1.2개씩 짝지을 수 있으면 삭제한다는 문제 조건을 통해서 홀수개 존재하는 알파벳을 사전순으로 출력하면 됨을 유추
      2.입력받은 문자열에 어떤 알파벳이 몇 개 있는지를 고려
      3.길이 26짜리 알파벳 배열을 처음부터 끝까지 검색
        3.1 알파벳이 홀수개 있으면 출력
*/

import java.util.Scanner;
import java.io.FileInputStream;


class Solution
{
	public static void main(String args[]) throws Exception
	{
		/*
		   표준입력 System.in 으로부터 스캐너를 만들어 데이터를 읽어옵니다.
		 */
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
		*/
		for(int test_case = 1; test_case <= T; test_case++)
		{
		String text;
			System.out.print("#"+test_case+" ");//테스트 케이스 출력 처리
			text = sc.next();//nextLine()을 사용시 \n을 따로 처리해야하는 불편함이 있고, 공백이 있는 입력을 받지않기때문에 next()를 사용
			int l = text.length();//입력받은 텍스트의 길이
			int[] alpha = new int[26];//텍스트에 보함된 알파벳의 갯수를 count하는 배열
			char[] charArray = text.toCharArray();//입력받은 string을 array로 저장
		
			int idx = 0;
			for(int i = 0;i<l;i++) {
				idx = (int)charArray[i] - 97;//아스키코드 'a' = 97
				alpha[idx] += 1;
			}//입력받은 text에 어떤 알파벳이 몇개 들어있는지 기록
			int good = 0;//홀수개만큼 있는 알파벳이 발견되면 값을 증가 -> 홀수개만큼 있는 알파벳이 없으면 0
			for(int i = 0;i<26;i++) {
				if(alpha[i] == 0) continue;//해당 알파벳 없으면 다음 알파벳으로
				else {
					if(alpha[i]%2 == 1) {
						System.out.print(((char)(i+97)));//아스키코드로 처리
						good++;
					}//해당 알파벳이 홀수개 있으면
				}//해당 알파벳이 있으면
			}
			if(good == 0) {
				System.out.print("Good");
			}//모든 알파벳이 짝수개만큼 있을 경우 Good(문제조건)
			System.out.println();//출력 형식 맞춤
		}
	}
}
