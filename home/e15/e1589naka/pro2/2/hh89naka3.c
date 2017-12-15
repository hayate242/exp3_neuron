#include<stdio.h>

int main(){
  float a[10];
  int i = 0;
  float sum = 0.0f;
  for(i=0;i<10;i++){
    scanf("%f",&a[i]);
    sum += a[i];
  }
  printf("Sum=%f\n",sum);
  return 0;
}
