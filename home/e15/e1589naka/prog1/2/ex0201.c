#include <stdio.h>

int main(void){
    int x, y;

  printf("x を入力してください：");
  scanf("%d", &x);
  printf("y を入力してください：");
  scanf("%d", &y);
  
  printf("x + y = %d \n", x + y);
  printf("10 の位 = %d\n", ( x + y )/10);
  printf("1 の位 = %d\n", ( x + y )%10);

  return 0;
}
