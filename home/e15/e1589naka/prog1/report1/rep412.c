#include <stdio.h>

int main(){
  int no;
  int cnt = 0;
  do {
    printf("正の整数を入力してください：");
    scanf("%d", &no);
    if ( no <= 0){
      printf("正の数でないかずを入力しないでください\n");
    }
  }while(no <= 0);

  printf("%dは", no);
  while(no > 0){
    cnt++;
    no /= 10;
  }
  printf("%d桁です\n",cnt);
}
