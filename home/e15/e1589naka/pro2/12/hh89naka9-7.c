#include <stdio.h>

int str_chnum( const char s[], int c ){
  int cnt = 0;
  int i;
  // printf("str_chnum\n");
  // printf("%s\n", s);
  for( i = 0; s[i] != '\0'; i++){
    // printf("%d: %d == %d\n", i, s[i], c);
    if( s[i] == c ){
      // printf("%d: %d == %d\n", i, s[i], c);
      cnt++;
    }
  }
  return cnt;
}

int main(){

	char s[10];
	int cnt;

	printf("英文字を入力してください : ");
	scanf("%s",s);

  cnt = str_chnum( "abcdeeeefghijklmnopqrstuvwxyz", s[0]);

  printf("%dの個数 = %d\n", s[0], cnt);
	return 0;
}
