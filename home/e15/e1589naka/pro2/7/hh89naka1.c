#include<stdio.h>

int evenAverage(int *pt){
  int i = 0;
  double sum = 0;
	double evenCnt = 0;

	for(i = 0; i < 10; i++){
		if(*pt%2 == 0){
			sum += *pt;
			evenCnt++;
		}
		pt++;
	}
	return sum/evenCnt;
}

int main(){

  int num[10],*pt;
	int i;
  pt = &num[0]; //初期化
	double sum = 0;
	double cnt = 0;

	for( i = 0; i < 10; i++ ){
 	 scanf("%d",pt);
	//	printf("%d\n",num[i]);
		if( *pt % 2 == 0){
				sum += *pt;
				cnt++;
		}
		pt++;
	}

  printf("ave = %lf\n",sum/cnt);
  
  
  return 0;
}

