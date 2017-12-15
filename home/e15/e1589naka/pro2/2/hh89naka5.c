#include<stdio.h>

int main(){
  int a[10];
  int i = 0;
  int j = 0;
  int k = 0;
  int tmpsum = 0;
  float avg[1024];
  for(;;){
    scanf("%d",&a[i]);
    if(a[i]>=100){
       printf("Error!Input data again.\n");
        i--;
     }
    else if(a[i] != 0){
	tmpsum += a[i];
     }
    if(i == 9){
       avg[j] = (float)tmpsum/(float)(i);
        //printf("i=%d\n",i);
       j++;
       i=0;
     }
     if(a[i]==0){
        avg[j] = (float)tmpsum/(float)(i);
 //printf("i=%d\n",i);
        break;
      }
  i++;
  }

  for(k=0;k<=j*10;k+=10){
	printf("Average[%d-%d]=%f\n",k,(k+9),avg[k/10]);

   }

  return 0;
}
