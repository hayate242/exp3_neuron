#include<stdio.h>

int main(){
  int a[10];
  int i = 0;
  int sum = 0;
  for(i=0;i<10;i++){
    scanf("%d",&a[i]);
    if(a[i]>=100){
       printf("Error!Input data again.\n");
        i--;
     }
    else{
	sum += a[i];
     }
  }
  printf("Sum=%d\n",sum);
  return 0;
}
