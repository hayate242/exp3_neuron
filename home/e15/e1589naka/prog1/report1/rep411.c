#include <stdio.h>

int main(){
  int no;
  do {
    printf("正の整数を入力してください：");
    scanf("%d", &no);
    if ( no <= 0){
      printf("正の数でないかずを入力しないでください\n");
    }
  }while(no <= 0);

  printf("%dを逆から読むと", no);
  while(no > 0){
    printf("%d", no % 10);
    no /= 10;
  }
  printf("です\n");
}
