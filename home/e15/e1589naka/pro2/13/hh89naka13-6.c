#include<stdio.h>

int main(){
  int input;
  int i;
  int a[2];
  int sum = 0;
  a[0] = 0;
  a[1] = 1;

  scanf("%d", &input);

  printf("%d ", a[0]);
  printf("%d ", a[1]);
  sum += a[1];

  for( i = 0; i < input-2; i++){
    if( i % 2 == 0 ){
      a[0] += a[1];
      sum += a[0];
      printf("%d ", a[0]);
    }
    else{
      a[1] += a[0];
      sum += a[1];
      printf("%d ", a[1]);
    }
  }

  printf("\nsum = %d\n", sum);

  return 0;
}
