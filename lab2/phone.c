#include <stdio.h>
#include <stdlib.h>

/*
* Write a small c program called phone.c and use scanf to 
* read a string and an integer from standard input.
*/

int main(){
	//Initialize the str and int.
	char phone[11];
	int num;

	scanf("%s", phone);
	scanf("%d", &num);

	if (num == -1){
		printf("%s\n", phone);
		return 0;
	} else if (num>=0 && num <= 9){
		printf("%c\n", phone[num]);
		return 0;
	} else {
		printf("ERROR\n");
		return 1;
	}

}
