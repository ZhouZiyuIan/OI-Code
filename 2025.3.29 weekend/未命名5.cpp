#include<stdlib.h>
#include<time.h>
#include<stdio.h>
main(){
	srand(time(0));
	int rd=rand()%10;
	while(rd--){
		printf("%d %d\n",rand(),rand());
	}
} 
