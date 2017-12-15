#include<stdio.h>



int main(){

  int num[10],*pt;
	int i;
  pt = &num[0]; //初期化
	double sum = 0;
	double cnt = 0;

	double avg = 0;
//	int flag = 1;
	double max = 0;

  while( scanf("%d",pt) != EOF ){
		pt++;
		for( i = 0; i < 9 ; i++ ){
			
		 	 scanf("%d",pt);
				sum += *pt;
				cnt += 1.0;
			
				pt++;
			
		}
		avg =  sum/cnt;
		if(max < avg){
			max = avg;
		}

  	printf("AVG %lf\n",avg);		
		pt = &num[0];
		sum = 0;
		cnt = 0;
	}

	printf("MAX = %f\n", max);  
  
  return 0;
}

