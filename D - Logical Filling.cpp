#include<stdio.h>
int n,k,m,tmp;
char s[2000010],t[2000010];
main(){
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++){
		t[i]=s[i];
		if(s[i]=='o'){
			m++;
			if(s[i-1]!='o')s[i-1]='.';
			if(s[i+1]!='o')s[i+1]='.';
		}
	}
	if(m==k){
		for(int i=1;i<=n;i++)putchar(s[i]=='?'?'.':s[i]);
		return 0;
	}
	for(int i=1;i<=n;i++)if(t[i]=='?'&&t[i-1]!='o'&&t[i+1]!='o')t[i]='o',m++;
	if(m>k)puts(s+1);
//	else{
//		for(int i=1;i<=n;i++){
//			if(s[i]!='?')putchar(s[i]);
//			else{
//				tmp=0;
//				while(s[i++]=='?')tmp++;
//				i-=2;
//				if(tmp%2)for(int j=1;j<=tmp;j++)putchar(j%2?'o':'.');
//				else for(int j=1;j<=tmp;j++)putchar('?');
//			}
//		}
	}
}
