#include <stdio.h>
#include <stdlib.h>

// utility to calculate string length
int len(char* str){
    int count=0;

    while(str[count]!='\0'){
        ++count;
    }
    return count;
}

int patSearch(char* str, char* pat){
	int M, N, i, j, count = 0;

	// M - length of the pattern
	// N - length of the string
	if ((M = len(pat)) > (N = len(str))){
		printf("String length of Pattern > String.\n");
		exit(0);
	}

	// A loop to slide pat[] one by one
	for (i = 0; i <= N - M; i++)
	{
		// for current index i, check for pattern match
		for (j = 0; j < M; j++){
			if (str[i + j] != pat[j])
			{
				break;
			}
		}

		if (j == M){
			printf("Pattern found at index %d.\n", i);
			
			// count the number of occurences
			count++;
		}

	}
	return count;
}

int main(){
	int count;
	char str[20], pat[10];

	printf("Enter the text: ");
	scanf("%[^\n]s", str);
	getchar();
	printf("Enter the pattern to be searched in '%s': ", str);
	scanf("%[^\n]s", pat);
	getchar();

	// if the number of occurences is 0 then pattern is not present in the string
	if((count = patSearch(str, pat)) == 0){
		printf("Pattern '%s' not found in '%s'.\n", pat, str);
	}
	else{
		printf("Total occurences of '%s' in '%s' = %d.\n", pat, str, count);
	}
	return 0;
}



