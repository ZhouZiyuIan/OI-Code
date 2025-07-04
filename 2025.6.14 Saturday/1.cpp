#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n,m,T;
int main(){
	freopen("car123123.in","w",stdout);
	srand(time(0));
	T=10;
	n=100000;
	m=100000000;
	printf("%d\n",T);
	while(T--){
		printf("%d %d\n",n,m);
		for(int i=0;i<n;i++)printf("%d ",rand()%m);
		putchar(10);
	}
}
