#include <bits/stdc++.h>

#define endl '\n'
#define int long long

const int MAX_ARRAY_SIZE = 1e5 + 7;

int A[MAX_ARRAY_SIZE];

signed main (void) {
	
	freopen ("sleep.in", "r", stdin);
	freopen ("sleep.out", "w", stdout);
	
	std :: ios :: sync_with_stdio (false);
	std :: cin.tie (nullptr);
	std :: cout.tie (nullptr);
	
	int N, K, Sum = 0;
	std :: cin >> N >> K;
	
	for (int i = 1; i <= N; ++ i) {
		
		std :: cin >> A[i];
		
		Sum += A[i];
	}
	
	K %= Sum;
	
	for (int i = 1; i <= N; ++ i) {
		
		if (K >= A[i]) {
			
			K -= A[i];
		} else if (K) {
			
			std :: cout << i << endl << A[i] - K << endl;
			
			return 0;
		}
		
		if (K == 0) {
			
			std :: cout << i << "\n0";
			
			return 0;
		}
	}
	
	return 0;
}
