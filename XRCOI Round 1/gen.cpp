#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a;
main(){
	srand(time(0));
//	for(;;){
		freopen("test.in","w",stdout);
		printf("%d\n",a=rand()%101);
		while(a--){
			printf("%d %d\n",rand()%100+1,rand()%101);
		}
//	}
}
