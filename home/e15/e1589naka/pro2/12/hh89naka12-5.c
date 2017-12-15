#include <stdio.h>

struct numbers{ 
	char number[5];
} tel[3];

int main()
{
	struct numbers{ 
		char number[5];
	} tel[3];
		
  char s[20],*pt_s;
	int i = 0;
	int j = 0;

  scanf("%s",s);
  pt_s=s; 

  while(*pt_s!='\0'){
		
    if(*pt_s!='-'){

      tel[i].number[j] = *pt_s;
			//	printf( "%d %d %s\n", i, j, tel[i].number[j] );
	 		 j++;
			
     
    }
		if( *pt_s == '-' ){
			tel[i].number[j] = '\0';
			i++;
			j = 0;
		}

    pt_s++;

  }

  printf(" Signal\t Shinai\t Bango\t \n");
  printf("  %s\t  %s\t  %s\t \n", tel[0].number, tel[1].number, tel[2].number );

	

  return 0;
}
