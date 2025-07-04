#include<bits/stdc++.h>
using namespace std;
void dfs(int x,int y){
	if(s[x][y]=='X'){
		return;
	} 
}
int main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
    cin>>t;
    for(int i=1;i<=n;i++){
    	cin>>n>>m;
    	for(int j=1;j<=n;j++){
    		for(int k=1;k<=m;k++){
    			cin>>s[j][k];
    			if(s[j][k]=='s'){
    				dfs(j,k);
				}
			}
		}
		cout<<"YES\n";
	}
	
	return 0;
}

