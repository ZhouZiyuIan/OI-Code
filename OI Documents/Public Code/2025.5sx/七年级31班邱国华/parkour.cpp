#include<bits/stdc++.h>
//#include<windows.h>
using namespace std;
bool xx[105][10005];
/*void test(int y,int x,int f){
	system("cls");
	for(int i=0;i<3;i++){
		for(int ii=0;ii<16;ii++){
			if(i==y&&ii==x){
				cout<<"s";
				continue;
			}
			if(xx[i][ii]==1){
				cout<<"#";
			}else if(!xx[i][ii]){
				cout<<".";
			}
		}
		cout<<endl;
	}
	cout<<y<<" "<<x<<" "<<f;
	Sleep(500);
}*/
bool dfs(int x,int y,int f,int z,bool p){
	//test(y,x,f);
	if(x>f){
		cout<<x<<" "<<y;
		return 1;
	}
	if(p){
		if(!xx[y][x+2]){
			if(dfs(x+2,y,f,z,0)){
				return 1;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
		
	}
	for(int i=0;i<3;i++){
		if(i==0&&y-1>=0){
			if(!xx[y-1][x+1]&&!xx[y][x+1]){
				if(dfs(x+1,y-1,f,z,1)){
					return 1;
				}
			}
		}
		if(i==1&&y+1<z){
			if(!xx[y+1][x+1]&&!xx[y][x+1]){
				if(dfs(x+1,y+1,f,z,1)){
					return 1;
				}
			}
		}
		if(i==2&&!xx[y][x+1]){
			if(dfs(x+1,y,f,z,1)){
				return 1;
			}
		}
	}
}
int main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	int a,b,c,x,y;
	char d;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>c>>b;
		for(int ii=0;ii<b;ii++){
			for(int iii=0;iii<c;iii++){
				cin>>d;
				if(d=='.'){
					xx[ii][iii]=0;
				}else if(d=='X'){
					xx[ii][iii]=1;
				}else{
					y=ii;
					x=iii;
				}
			}
		}
		//cout<<c;
		//Sleep(5000);
		if(dfs(x,y,c,b,0)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}
