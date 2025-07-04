#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,y;
int a[10000000];
int m[10000000];
double f=0;
int p=0;
bool aa=true;
int main(){
	freopen("picnic.in","w",stdin);
	freopen("picnic.out","r",stdout);
	scanf("%lld%lld",&n,&y);
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=1){
		cout<<0;
		return 0;
	}
	int k=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			k++;
			aa=true;
			f=(a[j]-a[i]);
			
			for(int v=1;v<=k;v++){
				if(f==m[v])
				{
					aa=false;
					break;
				}
			}
			
			if(aa==true){
				m[k]=f;
				p++;
			}
			
		}
	}
	printf("%d",p);




}
