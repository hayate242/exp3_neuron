#include <stdio.h>

int main(){

	char s[] = "ABC";
	char str[48];

	printf("文字列str : ");
	scanf("%s",str);

	printf("文字列s  は\"%s\"です\n", s);
	printf("文字列strは\"%s\"です\n", str);

	s[0] = '\0';
	str[0] = '\0';

	printf("文字列s  を空文字列にしました\"%s\"です\n", s);
	printf("文字列strを空文字列にしました\"%s\"です\n", str);


	return 0;
}
