#include <bits/stdc++.h>
using namespace std;
int m, add;
int cnt[30];
bool del[30];
char s[100005];
int main()
{
	freopen("goof.in", "r", stdin);
	freopen("goof.out", "w", stdout);
	for(int i = 0; i <= 26; ++i) cnt[i] = INT_MAX;
	scanf("%s", s+1);
	int n = strlen(s+1);
	scanf("%d", &m);
	for(int i = 1; i <= n; ++i)
	{
		if(cnt[s[i] - 96] == INT_MAX) cnt[s[i] - 96] = 1, ++add;
		else ++cnt[s[i] - 96];
	}
	for(int i = 1; i <= 26; ++i)
	{
		int id = 0;
		for(int j = 1; j <= 26; ++j)
		{
			if(del[j]) continue;
			if(cnt[id] > cnt[j]) id = j;
		}
		if(m >= cnt[id])
		{
			--add;
			m -= cnt[id];
			del[id] = true;
		}
		else break;
	}
	printf("%d\n", add);
	for(int i = 1; i <= n; ++i)
	{
		if(del[s[i] - 96]) continue;
		putchar(s[i]);
	}
	return 0;
}
