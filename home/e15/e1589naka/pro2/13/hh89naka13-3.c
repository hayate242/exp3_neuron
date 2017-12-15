#include <stdio.h>
#include <time.h>

int main(){
	int i, j, x[100000], temp, minVal, minIndex;
	int cntArray = 0;

	for (i=0; i<100000; i++) {
		scanf("%d", &x[i]);
	}

	clock_t start,end;
	start = clock();

	while( x[cntArray] != 0){
		cntArray++;
	}
	//printf("cntArray = %d\n", cntArray);



	// 0番目と1番目の２つが対象
	for (i=0; i<=cntArray; i++){
		// 交換対象のデータで初期化
		minVal= x[i];
		minIndex= i;
		// i+1番目から9番目までのデータから最小値を見つける
		for (j=i+1; j<cntArray; j++){
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
	  end = clock();


	for (i=0; i<10000; i+=1000) {
		printf("x[%d]=%d, ", i, x[i]);
	}
	printf("\n");

	  printf("%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}
