#include<stdio.h>
struct node{
	int ls,rs,fa;
	double lzt;
}dot[1000001];
int n,m,x,y,op,tmp;
double res=1;
inline void searchup(int cur){
	if(!dot[cur].fa){
		tmp+=dot[cur].lzt;
		return;
	}
	searchup(dot[cur].fa);
	if(tmp)res*=(double)tmp/(double)(tmp+1);
	tmp+=dot[cur].lzt;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		dot[x].fa=dot[y].fa=i;
		dot[i].ls=x;
		dot[i].rs=y;
	}
	while(m--){
		scanf("%d%d",&op,&x);
		if(op==1){
			scanf("%d",&y);
			dot[x].lzt+=y;
		}
		if(op==2){
			if(dot[x].ls)dot[dot[x].ls].lzt+=dot[x].lzt;
			if(dot[x].rs)dot[dot[x].rs].lzt+=dot[x].lzt;
			dot[x].lzt=0;
		}
		if(op==3){
			res=1.0;
			tmp=0;
			searchup(x);
			printf("%.6lf\n",res);
		}
	}
}
