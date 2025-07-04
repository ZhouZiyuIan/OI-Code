#include<bits/stdc++.h>
using namespace std;

int T;

int n, m;

bool f[10707];

char s[15][10007];

signed main()
{
	freopen("parkour.in", "r", stdin);
	freopen("parkour.out", "w", stdout);

	cin >> T;
	
	while(T--)
	{
		cin >> m >> n;
		memset(f, 0, sizeof f);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin >> s[i][j];
				if(s[i][j] == 's')
					f[i] = true;
			}
		}
		int j = 1;
		bool flg = 0;
		while(j <= m)
		{
			if(flg)
			{
				puts("NO");
				break;
			}
			++j;
			for(int i = 1; i <= n; i++)
			{
				if(f[i] and s[i][j] != 'X')
					f[i + 1] = f[i] = f[i - 1] = 1;
				else
				f[i] = 0;
			}
			for(int i = 1; i <= n; i++)
			{
				int l, r;
				if(m <= j)
					l = m;
				else
					l = j;
				if(m <= j + 2)
					r = m;
				else
					r = j + 2;
				for(int p = l; p <= r; p++)
				{
					if(!f[i])
						break;
					if(s[i][p] == 'X')
					{
						f[i] = false;
						break;
					}
				}
			}
			for(int i = 1; i <= n; i++)
			{
				for(int p = 3; p <= m; p++)
					s[i][p - 2] = s[i][p];
				s[i][m] = '.';
				s[i][m - 1] = '.';
			}
			for(int i = 1; i <= n; i++)
			{
				if(f[i])
					break;
				if(i == n)
				{
					flg = true;
					break;
				}
			}
			m -= 2;
		}
		if(!flg)
			puts("YES");
	}

	return 0;
}
