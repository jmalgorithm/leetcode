#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int main() {
	int a = 0;
	while (1) {
		int i = 0, max, result;
		int mat[250000] = { 0 };
		cin >> a;
		if (a == 0)
			break;
		for (i = 0; i < a; i++)
			cin >> mat[i];
		max = mat[0];
		result = mat[0];
		for (i = 1; i < a; i++) {
			int result_now = 0;
			//printf("now: %d\n", mat[i]);
			//printf("now result: %d\n", result);
			if (max<0 & mat[i]>max) {
				max = mat[i];
				result = mat[i];
				//printf("if max<0: %d\n", max);
			}
			else if (result >= 0) {
				result_now = result + mat[i];
				if (result_now > max) {
					max = result_now;
					result = result_now;
					//printf("result_now is new max: %d\n", max);
				}
				else if (result_now < 0) {
					//printf("reuslt_now < 0!!\n");
					result = 0;
				}
				else {
					result = result_now;
				}
			}
		}
		printf("%d\n", max);
	}
}