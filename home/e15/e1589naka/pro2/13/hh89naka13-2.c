#include <stdio.h>

int main(){
	int i, j, x[10], temp, minVal, minIndex;
	for (i=0; i<10; i++) {
		scanf("%d", &x[i]);
	}


	// 0番目と1番目の２つが対象
	for (i=0; i<=10; i++){
		// 交換対象のデータで初期化
		minVal= x[i];
		minIndex= i;
		// i+1番目から9番目までのデータから最小値を見つける
		for (j=i+1; j<10; j++){
			if (x[j] < minVal) {
				minVal= x[j];
				minIndex= j;
			}
		}
		// i番目と一番小さいminIndex番目のデータを交換
		temp = x[i];
		x[i] = x[minIndex];
		x[minIndex] = temp;
	}
	for (i=0; i<10; i++) {
		printf("x[%d]=%d, ", i, x[i]);
	}
	printf("\n");
	return 0;
}
