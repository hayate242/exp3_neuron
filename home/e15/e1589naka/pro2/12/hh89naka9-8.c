#include <stdio.h>

void str_chnum( const char s[], int n ){
  int i = 0;
  for( i = 0; i < n; i++ ){
    printf("%s", s);
  }
  printf("\n");
}

int main(){



  str_chnum( "abcd", 4);


	return 0;
}
