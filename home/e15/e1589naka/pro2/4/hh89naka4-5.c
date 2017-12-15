#include<stdio.h>
#include <string.h>

int main(){
  char x[256];
  
  int j = 0;

  

  while(scanf("%s",x) != EOF){

 // printf("sizeof(x) = %d",strlen(x));
  printf("moji = ");
  for(j = 0;j<strlen(x);j++){

     printf("%c",x[j]);

     if(x[j] == 'a' || x[j] == 'i' || x[j] == 'u' || x[j] == 'e' || x[j] == 'o' ){
        printf("%c",x[j]);
      }
  }
  printf("\n");

  }

 // printf("cntO = %d: cntX = %d\n",cntO,cntX);


  
  return 0;
}

