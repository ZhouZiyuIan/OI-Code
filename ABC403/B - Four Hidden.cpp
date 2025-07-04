#include<stdio.h>
#include<string.h>
char t[11],u[11];
int lent,lenu,f;
main(){
	scanf("%s%s",t,u);
	lent=strlen(t);
	lenu=strlen(u);
	for(int i=0;i<=lent-lenu;i++){
		f=1;
		for(int j=0;j<lenu;j++){
			if(t[j+i]=='?')continue;
			if(t[j+i]!=u[j]){
				f=0;
				break;
			}
		}
		if(f){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
}