#include <stdio.h>

void rev_string( char s[]){
  // int i = 0;
  char tmp = '\0';
  char *first = s;
  char *last = s;

  while( *(last+1) != '\0' ){
    last++;
  }
  while( first < last ){
    tmp = *first;
    *first = *last;
    *last = tmp;

    last--;
    first++;
  }
  return;
}

int main(){

  char s[20] = "2gasgasdf";
  printf("%s\n", s);
  rev_string(s);

  printf("%s\n", s);
	return 0;
}
