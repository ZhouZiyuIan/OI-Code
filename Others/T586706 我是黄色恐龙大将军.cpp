#include<stdio.h>
#include<math.h>
main(){
	for(int i=1;i<=21;i++){
		printf("%d %lld\n",(1<<i),(long long)pow(5,i));
	}
}
