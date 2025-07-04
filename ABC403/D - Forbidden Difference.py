#include <bits/stdc++.h>
using namespace std;

const int MAX_A = 1e6 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (D == 0) {
        unordered_map<int, int> freq;
        for (int num : A) {
            freq[num]++;
        }
        int max_freq = 0;
        for (auto& p : freq) {
            max_freq = max(max_freq, p.second);
        }
        cout << N - max_freq << '\n';
        return 0;
    }

    unordered_map<int, int> freq;
    for (int num : A) {
        freq[num]++;
    }

    vector<int> sorted_unique;
    for (auto& p : freq) {
        sorted_unique.push_back(p.first);
    }
    sort(sorted_unique.begin(), sorted_unique.end());

    vector<int> dp(MAX_A, 0);
    for (int x : sorted_unique) {
        if (x - D >= 0) {
            dp[x] = dp[x - D] + freq[x];
        } else {
            dp[x] = freq[x];
        }
    }

    int max_len = *max_element(dp.begin(), dp.end());
    cout << N - max_len << '\n';

    return 0;
}
