#include<bits/stdc++.h>
using namespace std;
int k,len,sum,ans;
char s[100005];
struct node{
	char id;
	int cnt;
}vis[30];
bool cmp(node a,node b){
	return a.cnt>b.cnt;
}
int main(){
	freopen("goof.in","r",stdin);
	freopen("goof. out","w",stdout);
	scanf("%s %d",s+1,&k);
	len=strlen(s+1);
	for(int i=1;i<=26;i++)
		vis[i].id=i+96;
	for(int i=1;i<=len;i++){
		if(vis[s[i]-96].cnt==0) sum++;
		vis[s[i]-96].cnt++;
 	}
 	sort(vis+1,vis+27,cmp);
 	for(int i=sum;i>=sum-k+1;i--){
 		printf("%c %d\n",vis[i].id,vis[i].cnt);
	 }
	printf("%c %d\n",vis[sum-k+1].id,vis[sum-k+1].cnt);
	for(int i=sum;i>=sum-k+1;i--){
		if(sum-vis[i].cnt>=0){
			sum--;
			vis[i].cnt=-1;
		}
		else break;
 	}
 	printf("%d\n",sum);
	for(int i=1;i<=len;i++)
		if(vis[i].cnt!=-1)
			printf("%c",s[i]);
	return 0;
}/*
abacaba
4
*/
