#include <stdio.h>

void del_digit(char s[]){
  int i = 0;
  int cntWord = 0;
  while( s[i] != '\0'){
    if( s[i] < '0' || s[i] > '9' ){
      s[cntWord] = s[i];
      cntWord++;
    }
    i++;
  }
  s[cntWord] = '\0';
  // printf("%s\n", s);
}


int main(){

  char str[100];


	printf("文字列を入力してください : ");
	scanf("%s",str);

  del_digit( str );

  printf("数字文字を削除しました\nstr = %s\n", str);
	return 0;
}
