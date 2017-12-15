#include <stdio.h>
#include <string.h>

// 文字列を逆順にする
void strrev(char s[]){
    char temp = '\0';
    char *first = s;
    char *last = s;

    // 長さ0の文字列なら操作せず返す
    if(*first == '\0'){ return; }

    // 文字列の最後の文字のポインタを取得する
    while( *(last+1) != '\0'){ last++; }

    // 外側から逆にする
    while(first < last){
        temp = *first;
        *first = *last;
        *last = temp;

        // 一つずつ範囲を小さくする
        first++;
        last--;
    }
    return;
}

int main()
{
 char s[20],t[10];
 int i,j,k;
 char *u;
	int l,m;

 scanf("%s",s);
 scanf("%s",t);
 i=j=0;

	strrev(s);
	strrev(t);
	strcat( s, t );

 printf(" Kekka = %s\n",s );
 return 0;
}
