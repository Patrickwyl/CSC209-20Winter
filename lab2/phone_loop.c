#include <stdio.h>
#include <stdlib.h>

/*
* this program reads a 10-character string as the first input value 
* but then it repeatedly reads integers until standard input is closed.
*/

int main(){
	//Initialize the str and int.
	char phone[11];
	int num;
	int result = 0;

	scanf("%s", phone);

	while (scanf("%d", &num) != EOF){

		if (num == -1){
			printf("%s\n", phone);
		} else if (num>=0 && num <= 9){
			printf("%c\n", phone[num]);
		} else {
			printf("ERROR\n");
			result = 1;
		}
		
	}

	return result;

}