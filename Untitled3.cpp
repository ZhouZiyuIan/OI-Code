#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int k=10,n=50000;
main(){
	freopen("cbs.in","w",stdout);
	srand(time(0));
	puts("10 50000");
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++)putchar(40+(rand()%2));
		putchar(10);
	}
}
