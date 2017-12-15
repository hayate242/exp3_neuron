#include <stdio.h>

int main(){
  int i,num = 0;

  do {
    printf("データ数：");
    scanf("%d", &num);
    if ( num <= 0 ){
      printf("自然数でよろしく\n");
    }
  }while( num <= 0 );


  int a[num];
  for( i = 0; i < num; i++ ){
    printf("%d番：", i+1 );
    scanf("%d", &a[i]);
  }
  printf("{");
  for ( i = 0; i < num-1; i++ ){
    printf("%d, ", a[i]);
  }
  printf("%d}\n",a[num-1]);

}
