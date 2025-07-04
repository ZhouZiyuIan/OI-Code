#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	int total_size = 1 << n;
	vector<long long> a(total_size);
	for (int i = 0; i < total_size; i++) {
		cin >> a[i];
	}
	
	vector<int> ans(total_size, 0);
	vector<bool> alive(total_size, true);
	int total_alive = total_size;
	
	for (int round = 1; round <= n; round++) {
		int size = 1 << round;
		int groups = total_size / size;
		vector<int> eliminate_this_round;
		
		for (int j = 0; j < groups; j++) {
			int low = j * size;
			int high = (j + 1) * size - 1;
			vector<int> group_list;
			for (int id = low; id <= high; id++) {
				if (alive[id]) {
					group_list.push_back(id);
				}
			}
			int m = group_list.size();
			int keep = min(m, k);
			
			if (keep < m) {
				nth_element(group_list.begin(), group_list.begin() + keep, group_list.end(), [&](int x, int y) {
					return a[x] > a[y];
				});
				for (int idx = keep; idx < m; idx++) {
					int id = group_list[idx];
					alive[id] = false;
					eliminate_this_round.push_back(id);
				}
			}
		}
		
		int cnt_eliminate = eliminate_this_round.size();
		total_alive -= cnt_eliminate;
		for (int id : eliminate_this_round) {
			ans[id] = total_alive + 1;
		}
	}
	
	vector<int> last_group;
	for (int i = 0; i < total_size; i++) {
		if (alive[i]) {
			last_group.push_back(i);
		}
	}
	sort(last_group.begin(), last_group.end(), [&](int x, int y) {
		return a[x] > a[y];
	});
	for (int i = 0; i < last_group.size(); i++) {
		ans[last_group[i]] = i + 1;
	}
	
	for (int i = 0; i < total_size; i++) {
		cout << ans[i];
		if (i < total_size - 1) {
			cout << " ";
		}
	}
	cout << endl;
	
	return 0;
}
