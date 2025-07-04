#include <cstdio>
#include <algorithm>
using namespace std;
int n, a, b, line[800001], cur[800001], ans, pos;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		if(a > b) {
			swap(a, b);
		}
		line[a] = b;
		line[b] = a + (n << 1);
	}
	for(int i = (n << 2); i >= 0; --i) {
		pos = lower_bound(cur, cur + 1 + ans, line[i]) - cur;
		ans = max(ans, pos);
		cur[pos] = line[i];
	}
	printf("%d", ans);
}
