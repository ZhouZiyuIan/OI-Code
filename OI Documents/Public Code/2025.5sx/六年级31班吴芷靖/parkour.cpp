#include<bits/stdc++.h>
using namespace std;
int t,k=0;
int n,m,dx[3]= {1,-1,0};
char a[10][10000];
void find(int x,int y) {
	if(y==m-1) {
		k=1;
		return;
	}
	y++;
	if(a[x][y]=='X') {
		return;
	}
	for(int s=0; s<3; s++) {
		a[x][y]='.';
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(j+m>2) {
					a[i][j]='.';
				} else {
					a[i][j]=a[i][j+2];
					if(a[x][y]=='X') {
						return;
					}
				}
			}
		}
		find(x+dx[s],y);
	}
}
int main() {
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	cin>>t;
	for(int w=0; w<t; w++) {
		cin>>n>>m;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin>>a[i][j];
			}
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(a[i][j]=='s') {
					find(i,j);
				}
			}
		}
		if(k==1) {
			cout<<"YES";
		} else {
			cout<<"NO";
		}
	}
	return 0;
}
/*ÑùÀý1
2
16 3
...XXXXX........
s.XXX......XXXXX
........XXXXX...
16 3
...XXXXX........
s.XXX....XXXXX..
.......XXXXX....
*/

