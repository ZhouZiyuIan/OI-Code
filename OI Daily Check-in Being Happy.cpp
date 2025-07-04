#include<stdio.h>
int a,b,c;
char s[10000];
main(){
	gets(s);
	c=0;
	while(scanf("%d",&a)!=EOF){
		if(a==1)c++;
		else if(c>=1)c--;
	} 
	printf("%d",c);
}
