#include<stdio.h>

int main(){
  char s[256],*pt;
  int i = 0;
  scanf("%s",s);
  pt = &s[0]; //初期化

  for(i=0;i<10;i++){
    printf("s[%d] Address %d %d Content %c\n",i,pt,&s[i],*pt);
    pt++;

  }


 // printf("sizeof(void*)= %d sizeof(int*)= %d\n",sizeof(void*),sizeof(int*));
  
  return 0;
}

