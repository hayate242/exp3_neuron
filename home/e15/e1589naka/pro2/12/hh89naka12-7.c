#include<stdio.h>

int check_includes(char s[], char t[]){
  int i = 0;
  int j = 0;
  int flag = 0;
  int cnt = 0;

  for(i = 0; s[i] != '\0'; i++){
    if(s[i] == t[0]){
      flag = 1;

      for(j = 0; t[j] != '\0'; j++){
        if(s[i+j] != t[j]){
          flag = 0;
        }
      }
      if(flag == 1){
        cnt++;
      }
    }
  }
  return cnt;
}

int main(){
  char s[200],t[200];
  int result = 0;

  scanf("%s %s", s, t);

  result = check_includes( s, t );

  printf( "kekka = %d\n", result );
  return 0;
}
