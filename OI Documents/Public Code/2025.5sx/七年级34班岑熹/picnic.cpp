#include <bits/stdc++.h>

#define endl '\n'
#define int long long

const int MAX_ARRAY_SIZE = 1e5 + 7;

std :: unordered_map <int, bool> F;

int A[MAX_ARRAY_SIZE];

signed main (void) {
	
	freopen ("picnic.in", "r", stdin);
	freopen ("picnic.out", "w", stdout);
	
	std :: ios :: sync_with_stdio (false);
	std :: cin.tie (nullptr);
	std :: cout.tie (nullptr);
	
	int N, K;
	std :: cin >> N >> K;
	
	for (int i = 1; i <= N; ++ i) {
		
		std :: cin >> A[i];
	}
	
	std :: sort (A + 1, A + 1 + N);
	
	for (int i = 1; i <= N; ++ i) {
		
		for (int j = i + 1; j <= N; ++ j) {
			
			F[A[j] - A[i]] = true;
		}
	}
	
	std :: cout << F.size () << endl;
	
	return 0;
}
