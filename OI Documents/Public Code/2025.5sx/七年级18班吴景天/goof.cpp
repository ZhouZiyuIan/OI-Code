#include<bits/stdc++.h>
using namespace std;
int len,k,box[26],zl; 
char s[100010],ch;
bool vis[100010];
int main(){
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s",s);
	scanf("%d",&k);
	len=strlen(s);
	for(int i=0;i<len;i++){
		box[s[i]-97]++;
	}
	while(k>0){
		int mn=200005,f=0;
		for(int i=0;i<26;i++){
			if(box[i]<mn&&box[i]>0) mn=box[i],f=i;
		}
		ch=f+97;
		for(int i=0;i<len&&k>0;i++){
			if(s[i]==ch){
				vis[i]=1;
				k--;
				box[f]--;
			}
		}
	}
	for(int i=0;i<26;i++){
		if(box[i]>0) zl++;
	}
	printf("%d\n",zl);
	for(int i=0;i<len;i++){
		if(!vis[i]) printf("%c",s[i]);
	}
	return 0;
}
