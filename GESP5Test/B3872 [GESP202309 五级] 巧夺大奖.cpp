#include<stdio.h>
#include<algorithm>
using namespace std;
struct a{
	int T,R;
}game[501];
int n,time[501],C;
bool cmp(a a1,a a2){
	return a1.R>a2.R;
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&game[i].T);
	for(int i=0;i<n;i++)scanf("%d",&game[i].R);
	sort(game,game+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=game[i].T;j;j--)if(time[j]==0){
			time[j]=1;
			C+=game[i].R;
			break;
		}
	}
	printf("%d",C);
}
