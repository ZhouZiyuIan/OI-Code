#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node{
	int b;
	int c;
}node[30];
ll k,len,ans;
char s[100010];
bool cmp(Node x,Node y){
	return x.b<y.b;
}
int main(){
	memset(node,0,sizeof(node));
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s>>k;
	len=strlen(s);
	if(k>=len){
		cout<<0<<"\n";
		cout<<"";
	}
	for(int i=0;i<len;i++){
		node[s[i]-'a'+1].b++;
		node[s[i]-'a'+1].c++;
	}
	sort(node+1,node+27,cmp);
	ll num=k;
	for(int i=1;i<=26;i++){
		if(num>=node[i].b){
			num-=node[i].b;
			node[i].b=0;
		}else{
			node[i].b-=num;
			break;
		}
	}
	for(int i=1;i<=26;i++){
		if(node[i].b!=0){
			ans++;
		}
	}
	cout<<ans<<"\n";
	cout<<1;
	for(int i=0;i<len;i++){
		if(node[s[i]-'a'+1].b!=0){
			cout<<s[i];
		}
	}
	return 0;
}
