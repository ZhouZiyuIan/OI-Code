#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100010],b[100010],ans;
bool T=1;
void fun(int x,ll used[]){
	if(x!=-1)fun(x+1,used);
	if(x>n){
		ans++;
		return;
	}else{
		for(int i=1;i<=n;i++){
			if(!used[i] and i!=x){
				used[i]=1;
				fun(x+1,used);
				used[i]=0;
			}
		}
	}
}
int main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	cin>>n;
	memset(b,1,sizeof(b));
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==-1)b[i]=0; 
		else k++;
		if(a[i]==i)T=0;
	}
	if(T){
		fun(0,b);
		cout<<ans%1000000007;	
	}else{
		cout<<0;
	}
	return 0;
}
