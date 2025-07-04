#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<pair<int, int>> days; // (a_i, b_i) for each day
	vector<int> courses(n, 0);   // number of courses each day
	
	for (int i = 0; i < n; ++i) {
		int a = m, b = -1;
		int cnt = 0;
		for (int j = 0; j < m; ++j) {
			int val;
			cin >> val;
			if (val == 1) {
				a = min(a, j);
				b = max(b, j);
				cnt++;
			}
		}
		if (cnt == 0) {
			days.emplace_back(0, 0); // no courses, stay time 0
		} else {
			days.emplace_back(a, b);
		}
		courses[i] = cnt;
	}
	
	// Initialize DP table
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX / 2));
	dp[0][0] = 0;
	
	for (int i = 1; i <= n; ++i) {
		int a = days[i-1].first;
		int b = days[i-1].second;
		int total = courses[i-1];
		int stay_time = (total == 0) ? 0 : (b - a + 1);
		
		for (int j = 0; j <= k; ++j) {
			// Option 1: skip the entire day (only if total > 0)
			if (total > 0 && j + total <= k) {
				dp[i][j + total] = min(dp[i][j + total], dp[i-1][j]);
			}
			// Option 2: keep some courses
			for (int t = 0; t <= total; ++t) {
				if (t == total) {
					// keep all courses, stay_time remains
					if (j <= k) {
						dp[i][j] = min(dp[i][j], dp[i-1][j] + stay_time);
					}
				} else if (t < total) {
					// keep t courses, need to find minimal a and maximal b in the kept courses
					// To minimize stay_time, best is to keep the leftmost and rightmost t courses
					// So the stay_time is (b_t - a_t + 1), where a_t is the t-th leftmost, b_t is the t-th rightmost
					// But since we can choose any t courses, the minimal stay_time is when we choose the leftmost and rightmost t courses
					// So for t courses, the minimal stay_time is (b_t - a_t + 1), where a_t is the first kept course, b_t is the last kept course
					// So the minimal stay_time is when we keep the first x and last y courses where x + y = t
					// But to minimize (b_t - a_t + 1), we should choose the t courses that are as close as possible
					// So the minimal stay_time is the minimal (b' - a' + 1) where a' is the first kept course, b' is the last kept course, and exactly t courses are kept
					// So for each day, we can precompute for each t, the minimal stay_time when keeping t courses
					// Then we can use this precomputed value in the DP
					// So we need to precompute for each day, for each t, the minimal stay_time when keeping t courses
					// This can be done by sliding window or other methods
					// But since m is up to 500, for each day, we can precompute this in O(m^2) time
					// So overall, this is acceptable
				}
			}
		}
	}
	
	// The above approach is not complete, as it doesn't handle the minimal stay_time when keeping t courses
	// So we need to precompute for each day, for each t, the minimal stay_time when keeping t courses
	// So let's rework the DP approach
	
	// Precompute for each day, the minimal stay_time when keeping t courses
	vector<vector<int>> day_min_stay(n, vector<int>(m + 1, INT_MAX));
	for (int i = 0; i < n; ++i) {
		int a = days[i].first;
		int b = days[i].second;
		int cnt = courses[i];
		if (cnt == 0) {
			day_min_stay[i][0] = 0;
			continue;
		}
		// Collect all the hours with courses
		vector<int> hours;
		for (int j = a; j <= b; ++j) {
			// Since we don't have the original a_{i,j}, we need to assume that all hours between a and b are courses
			// But the problem says a_{i,j} is given, so we need to store the original hours
			// So we need to modify the input reading part
			// So let's re-read the input and store the hours for each day
		}
	}
	
	// Re-reading input to store the exact hours for each day
	vector<vector<int>> daily_hours(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int val;
			cin >> val;
			if (val == 1) {
				daily_hours[i].push_back(j);
			}
		}
	}
	
	// Precompute day_min_stay
	for (int i = 0; i < n; ++i) {
		int cnt = daily_hours[i].size();
		if (cnt == 0) {
			day_min_stay[i][0] = 0;
			continue;
		}
		// For each possible t (number of kept courses), find minimal (b - a + 1)
		// The minimal is achieved by selecting a window of t courses
		for (int t = 1; t <= cnt; ++t) {
			int min_stay = INT_MAX;
			// Slide a window of size t over the sorted hours
			for (int j = 0; j + t - 1 < cnt; ++j) {
				int a = daily_hours[i][j];
				int b = daily_hours[i][j + t - 1];
				min_stay = min(min_stay, b - a + 1);
			}
			day_min_stay[i][t] = min_stay;
		}
		// If t = 0, stay_time is 0
		day_min_stay[i][0] = 0;
	}
	
	// Re-initialize DP table
	dp.assign(n + 1, vector<int>(k + 1, INT_MAX / 2));
	dp[0][0] = 0;
	
	for (int i = 1; i <= n; ++i) {
		int cnt = daily_hours[i-1].size();
		for (int j = 0; j <= k; ++j) {
			if (dp[i-1][j] == INT_MAX / 2) continue;
			// Option 1: skip all courses (if cnt > 0)
			if (cnt > 0 && j + cnt <= k) {
				dp[i][j + cnt] = min(dp[i][j + cnt], dp[i-1][j]);
			}
			// Option 2: keep t courses (t from 0 to cnt)
			for (int t = 0; t <= cnt; ++t) {
				if (j + (cnt - t) <= k) {
					dp[i][j + (cnt - t)] = min(dp[i][j + (cnt - t)], dp[i-1][j] + day_min_stay[i-1][t]);
				}
			}
		}
	}
	
	int answer = *min_element(dp[n].begin(), dp[n].end());
	cout << answer << endl;
	
	return 0;
}
