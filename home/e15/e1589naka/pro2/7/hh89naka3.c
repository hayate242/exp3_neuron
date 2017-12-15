#include<stdio.h>



int main(){

  int num[10],*pt;
	int i;
  pt = &num[0]; //初期化
	double sumO = 0;
	double sumD = 0;
	double cntO = 0;
	double cntD = 0;

	double avgOdd = 0;
	double avgEven = 0;

	for( i = 0; i < 10; i++ ){
 	 scanf("%d",pt);
		if( *pt % 2 == 0){
				sumD += *pt;
				cntD++;
		}
		else {
			sumO += *pt;
			cntO++;
		}
		pt++;
	}
	avgOdd =  sumO/cntO;
	avgEven =  sumD/cntD;

	if( avgOdd > avgEven ){
  	printf("Odd %lf\n",avgOdd);		
	}
	else if( avgOdd < avgEven ){
		printf("Even %lf\n",avgEven);
	}else{
		printf("Same %lf\n",avgEven);
	}

  
  
  return 0;
}

