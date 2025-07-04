#include<stdio.h>
#include<string.h>
int m,t,l;
char n[200100];
main(){
	scanf("%d",&m);
	while(m--){
		t=0;
		scanf("%s",n);
		l=strlen(n);
		for(int i=0;i<l;i++)t+=n[i]-'0';
		puts(t%9?"No":"Yes");
	}
}
