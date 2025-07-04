#include<stdio.h>
#include<string.h>
const int base=131;
int lens;
long long h2[500001],p[500001],h1[500001];
char s[500001];
main(){
	scanf("%s",s+1);
	lens=strlen(s+1);
	p[0]=1;
	printf("%s",s+1);
	for(int i=1;i<=lens;i++){
		h1[i]=(h1[i-1]*base+s[i]-97);
		p[i]=p[i-1]*base;
	}
	for(int i=lens;i;i--)h2[i]=(h2[i+1]*base+s[i]-97);
	for(int i=1;i<=lens;i++)if(h1[lens]-h1[i-1]*p[lens-i+1]==h2[i]){
		for(int j=i-1;j;j--)printf("%c",s[j]);
		return 0;
	}
}
