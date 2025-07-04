#include<bits/stdc++.h>
using namespace std;
int n, m;
char c[1001][1001];
bool k;
void dfs(int x, int y)
{ 
	if(!k || c[x][y] == 'X')
		return;
	if(y >= m - 1)
	{
		printf("Yes\n");
		k = 0;
		return;
	}
	y++;
	if(c[x][y] == 'X')
		return;
	if(x - 1 >= 0 && c[x - 1][y + 2] != 'X' && c[x - 1][y + 1] != 'X' && c[x - 1][y] != 'X')
		dfs(x - 1, y + 2);
	if(x + 1 < n && c[x + 1][y + 2] != 'X' && c[x + 1][y + 1] != 'X' && c[x + 1][y] !='X')
		dfs(x + 1, y + 2);
	if(c[x][y + 2] != 'X' && c[x][y + 1] != 'X')
		dfs(x, y + 2);
}
int main()
{
	freopen("parkour.in", "r", stdin);
	freopen("parkour.out", "w", stdout);
	int t, cx, cy;
	scanf("%d", &t);
	while(t--)
	{
		bool l = 1;
		k = 1;
		scanf("%d %d", &m, &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%s", c[i]);
			if(c[i][0] == 's')
			{
				cx = i;
				cy = 0;
			}
		}
		dfs(cx, cy);
		if(k)
			printf("No\n");
	}
	return 0;
}
