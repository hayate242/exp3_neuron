#include <stdio.h>
#include <string.h>

int main()
{
 char s[20],t[10];
 int i,j;
 // char *str;
 scanf("%s",s);
 scanf("%s",t);
 i=j=0;
 while(s[i]!='\0'){
  //  str[i] = s[i];
   i++;

 } /* '\0'は文字列の最後を表す */



 while(t[j]!='\0'){
 /* この部分の処理を考える */
  s[i] = t[j];
  i++;
  j++;
  // printf("%d\n");
 }
 s[i]='\0';
 printf(" Kekka = %s\n",s);
	return 0;
}
