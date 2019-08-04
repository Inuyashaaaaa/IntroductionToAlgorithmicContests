#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<long long> vec;
queue<long long> q;

int main() {
	long long n, k;
	cin >> n >> k;
	for (long long i = 0; i < n; i++) {
		long long x;
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	long long mid = (n - 1) / 2;
	for (long long i = mid; i < n - 1; i++) {
		q.push(vec[i + 1] - vec[i]);
	}
	long long weight = 1;
	long long ans = vec[mid];
	while (!q.empty()) {
		long long dis = q.front();
		q.pop();
		k -= dis * weight++;
		if (k < 0)
		{
            weight --;
            k += dis * weight;
			break;
		}
		ans += dis;
	}
	ans += k / weight;

	cout << ans << endl;
	//system("pause");
	return 0;
}