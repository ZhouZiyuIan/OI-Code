#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,k;
int const maxn=100000;
int s[maxn+1];
pair<int,int>h[31];
int p[31];
signed main(){
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	while(1){
		char in=getchar();
		while(in<'a'||in>'z'){
			if(in=='\n'){
				break;
			}
			in=getchar();
		}
		if(in=='\n'){
			break;
		}
		n++;
		s[n]=in-'a'+1;
		h[s[n]].first++;
	}
	scanf("%d",&k);
	for(int i=1;i<=26;i++){
		h[i].second=i;
	}
	sort(h+1,h+26+1);
	int j=1;
	while(k>=h[j].first&&j<=26){
		k-=h[j].first;
		p[h[j].second]=1;
		j++;
	}
	printf("%d\n",26-j+1);
	for(int i=1;i<=n;i++){
		if(p[s[i]]==0){
			printf("%c",s[i]+'a'-1);
		}
	}
	
	return 0;
}
