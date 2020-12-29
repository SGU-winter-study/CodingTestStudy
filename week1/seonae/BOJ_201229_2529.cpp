#include <iostream>
#include <cstring>
using namespace std;
char inequality[10];

void printMax(void) {
	int top = 9;
	int reserv = 0;
	for (int i = 0; i < strlen(inequality); i++) {
		if (inequality[i] == '>') {
			for (int j = top - reserv; j <= top; j++) {
				printf("%d", j);
			}
			top = top - reserv - 1;
			reserv = 0;
		}
		else {
			reserv++;
		}
	}
	for (int i = top - reserv; i <= top; i++) printf("%d", i);
}

void printMin(void) {
	int top = 0;
	int reserv = 0;
	for (int i = 0; i < strlen(inequality); i++) {
		if (inequality[i] == '<') {
			for (int j = top + reserv; j >= top; j--) {
				printf("%d", j);
			}
			top = top + reserv + 1;
			reserv = 0;
		}
		else {
			reserv++;
		}
	}
	for (int i = top + reserv; i >= top; i--) printf("%d", i);
}

int main(void) {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> inequality[i];
	}
	printMax();
	printf("\n");
	printMin();
	return 0;
}