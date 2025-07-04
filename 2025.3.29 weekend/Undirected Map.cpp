#include<stdio.h>
#include<vector>
#include<utility>
using namespace std;
vector<pair<int,int> >edg[100001];
int n,m,q,cl[100001],x,y,w;
long long stat[3];
char op[6];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&cl[i]);
	while(m--){
		scanf("%d%d%d",&x,&y,&w);
		edg[x].emplace_back(y,w);
		edg[y].emplace_back(x,w);
		if(cl[x]&&cl[y])stat[0]+=w;
		else if(cl[x]||cl[y])stat[1]+=w;
		else stat[2]+=w;
	}
	scanf("%d",&q);
	while(q--){
		scanf("%s%d",op,&x);
		if(*op=='C'){
			m=cl[x]?0:1;
			for(unsigned i=0;i<edg[x].size();i++){
				y=edg[x][i].first;
				w=edg[x][i].second;
				if(cl[x]&&cl[y])stat[0]-=w;
				else if(cl[x]||cl[y])stat[1]-=w;
				else stat[2]-=w;
				if(m&&cl[y])stat[0]+=w;
				else if(m||cl[y])stat[1]+=w;
				else stat[2]+=w;
			}
			cl[x]=m;
		}
		else{
			scanf("%d",&y);
			if(x&&y)printf("%lld\n",stat[0]);
			else if(x||y)printf("%lld\n",stat[1]);
			else printf("%lld\n",stat[2]);
		}
	}
}
