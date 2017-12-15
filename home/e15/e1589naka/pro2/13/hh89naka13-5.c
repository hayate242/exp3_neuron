#include <stdio.h>

void sort_by_dec(int y[100000], int cntArray){
	int i, j, temp, minVal, minIndex;
	// 0番目と1番目の２つが対象
	for (i=0; i<=cntArray; i++){
		// 交換対象のデータで初期化
		minVal= y[i];
		minIndex= i;
		// i+1番目から9番目までのデータから最小値を見つける
		for (j=i+1; j<cntArray; j++){
			if (y[j] < minVal) {
				minVal= y[j];
				minIndex= j;
			}
		}
		// i番目と一番小さいminIndex番目のデータを交換
		temp = y[i];
		y[i] = y[minIndex];
		y[minIndex] = temp;
	}
/*	for (i=0; i<cntArray; i++) {
		printf("y[%d]=%d, ", i, y[i]);
	}
	printf("\n");*/
}

int main(){
	int i, j, x[100000], temp, minVal, minIndex;
	int cntArray = 0;
	int y[10][100000];
	int cnty[10];
	int a = 0;

	//cnty　初期化
	for(i = 0; i < 10; i++){
			cnty[i] = 0;
	}

	//while (EOFで書き直す)
	for (i=0; i<100000; i++) {
		scanf("%d", &x[i]);
		// printf("%d = %d\n", i, x[i]);
	}
	// while( scanf("%d", &x[i]) != EOF){
	// 	printf("%d\n", x[i]);
	// }

	while( x[cntArray] != 0){
		cntArray++;
	}
	// printf("cntArray = %d\n", cntArray);

	for( i = 0; i < cntArray; i++){
		if( x[i] < 1000){
				y[0][cnty[0]] = x[i];
				cnty[0]++;
		}
		else if( x[i] < 2000){
				y[1][cnty[1]] = x[i];
				cnty[1]++;
		}
		else if( x[i] < 3000){
				y[2][cnty[2]] = x[i];
				cnty[2]++;
		}
		else if( x[i] < 4000){
				y[3][cnty[3]] = x[i];
				cnty[3]++;
		}
		else if( x[i] < 5000){
				y[4][cnty[4]] = x[i];
				cnty[4]++;
		}
		else if( x[i] < 6000){
				y[5][cnty[5]] = x[i];
				cnty[5]++;
		}
		else if( x[i] < 7000){
				y[6][cnty[6]] = x[i];
				cnty[6]++;
		}
		else if( x[i] < 8000){
				y[7][cnty[7]] = x[i];
				cnty[7]++;
		}
		else if( x[i] < 9000){
				y[8][cnty[8]] = x[i];
				cnty[8]++;
		}
		else if( x[i] < 10000){
				y[9][cnty[9]] = x[i];
				// printf("%d\n", y[9][cnty[9]]);
				cnty[9]++;
		}
	}
	// printf("ok\n" );
	for( i = 0; i < 10; i++){
		sort_by_dec(y[i],cnty[i]);
		// for (j=0; j<cnty[i]; j++) {
		// 	printf("y[%d][%d]=%d, ",i, j, y[i][j]);
		// }
		// printf("\n");
	}

	for(i = 0; i < 10; i++){
		for (j=0; j<cnty[i]; j++) {
			x[a] = y[i][j];
			// printf("a = %d\n", a);
			a++;
		}
	}

	for (i=0; i<cntArray; i+=1000) {
		printf("x[%d]=%d, ", i, x[i]);
	}
	printf("\n");




	return 0;
}
