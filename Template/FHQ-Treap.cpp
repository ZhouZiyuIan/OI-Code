#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Node{
	int ls,rs,key,pri,siz;
}treap[100001];
int n,opt,x,tSize=0,root=0;
void Pushup(int u){treap[u].siz=treap[treap[u].ls].siz+treap[treap[u].rs].siz+1;}
void Split(int u,int x,int &L,int &R){
	if(u==0){
		L=R=0;
		return;
	}
	if(treap[u].key<=x){
		L=u;
		Split(treap[u].rs,x,treap[u].rs,R);
	}
	else{
		R=u;
		Split(treap[u].ls,x,L,treap[u].ls);
	}
	Pushup(u);
}
int Merge(int L,int R){
	if(L==0||R==0)return L+R;
	if(treap[L].pri>treap[R].pri){
		treap[L].rs=Merge(treap[L].rs,R);
		Pushup(L);
		return L;
	}
	else{
		treap[R].ls=Merge(L,treap[R].ls);
		Pushup(R);
		return R;
	}
}
int Insert(int u,int x){
	// tSize++;
	treap[tSize].siz=1;
	treap[tSize].key=x;
	treap[tSize].pri=rand();
	int L,R;
	Split(u,x,L,R);
	return Merge(Merge(L,tSize++),R);
}
int Delete(int u,int x){
	int L,M,R;
	Split(u,x,L,R);
	Split(L,x-1,L,M);
	M=Merge(treap[M].ls,treap[M].rs);
	return Merge(Merge(L,M),R);
}
int GetMin(int u){
	while(treap[u].ls)u=treap[u].ls;
	return u;
}
int GetMax(int u){
	while(treap[u].rs)u=treap[u].rs;
	return u;
}
int GetRank(int u,int x){
	int L,R,res;
	Split(u,x-1,L,R);
	res=treap[L].siz+1;
	u=Merge(L,R);
	return res;
}
int GetKth(int u,int k){
	// printf("siz of %d is %d\n",u,treap[u].siz);
	if(treap[u].siz<k)return 0;
	while(k!=treap[treap[u].ls].siz+1){
		if(k<=treap[treap[u].ls].siz)u=treap[u].ls;
		else{
			u=treap[u].rs;
			k-=treap[treap[u].ls].siz+1;
		}
	}
	return u;
}
int GetPre(int u,int x){
	int L,R,res;
	Split(u,x-1,L,R);
	res=GetMax(L);
	u=Merge(L,R);
	return res;
}
int GetSuc(int u,int x){
	int L,R,res;
	Split(u,x,L,R);
	res=GetMin(R);
	u=Merge(L,R);
	return res;
}
main(){
	// srand(time(0));
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&opt,&x);
		switch(opt){
			case 1:{
				Insert(root,x);
				break;
			}
			case 2:{
				Delete(root,x);
				break;
			}
			case 3:{
				printf("%d\n",GetRank(root,x));
				break;
			}
			case 4:{
				printf("%d\n",GetKth(root+1,x));
				break;
			}
			case 5:{
				printf("%d\n",GetPre(root,x));
				break;
			}
			case 6:{
				printf("%d\n",GetSuc(root,x));
				break;
			}
		}
	}
}