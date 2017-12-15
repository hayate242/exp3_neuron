#include<stdio.h>

int main(){
  char x[256];
  char tmp;
  int i = 0;
  while((tmp=getchar())!= '\n'){
    x[i] = tmp;
    printf("x[%d] = %c\n",i,x[i]);
    i++;
  }
  
  return 0;
}

