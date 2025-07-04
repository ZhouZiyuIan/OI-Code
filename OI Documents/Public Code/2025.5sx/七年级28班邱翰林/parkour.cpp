#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

const int dx[] = {0, -1, 1};

int T;

int n, m;

char ch;

int vis[15][N];

int sum[15][N];

struct node
{
	int x, y;
};

string res[2] = {"NO", "YES"};

signed main()
{
	freopen("parkour.in", "r", stdin);
	freopen("parkour.out", "w", stdout);
	
	cin.tie(0) -> sync_with_stdio(0);
	
	cin >> T;
	
	while (T--)
	{	
		int flag = 0;
		
		cin >> n >> m;
		
		swap(n, m);
		
		queue<node> q;
		
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
			{
				cin >> ch;
				
				if (ch == 'X')
					vis[i][j] = 1;
				else
					vis[i][j] = 0;
				
				if (ch == 's')
					q.push({i, j});
			}
			
			for (int j=m+1; j<m+3; j++)
				vis[i][j] = 0;
		}
		
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m+2; j++)
			{
				sum[i][j] = sum[i][j-1] + vis[i][j];
			}
		}
		
		while (!q.empty())
		{
			int x = q.front().x, y = q.front().y;
			
			if (sum[x][m] - sum[x][y-1] <= 0)
			{
				flag = 1;
				
				break;
			}
			
			if (y >= m)
			{
				flag = 1;
				
				break;
			}
			
			q.pop();
			
			for (int i=0; i<3; i++)
			{
				int xx = x + dx[i], yy = y + 3;
				
				if (vis[xx][y+1])
					continue;
				
				if (vis[x][y+1])
					continue;
				
				if (xx < 1 || xx > n || vis[xx][yy])
					continue;
				
				vis[xx][yy] = 1;
				
				q.push({xx, yy});
			}
		}
		
		cout << res[flag] << '\n';
	}
	
	return 0;
}
