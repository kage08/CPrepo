#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

long long f[N][2];
int c[N], p[N];
vector<int> G[N];

void dfs(int x, int p = 0) {

	for (int u : G[x]) if (u != p) dfs(u, x);

	for (int fat = 0; fat <= 1; ++ fat) {
		vector<long long> sub;
		long long all = 0, all2 = c[x];

		for (int u : G[x]) if (u != p) {
			all2 += f[u][1];
			all += f[u][1];
			sub.push_back(f[u][0] - f[u][1]);
		}

		f[x][fat] = all2;
		int should = ::p[x] - fat;

		if ((int) sub.size() >= should) {
			sort(sub.begin(), sub.end());

			for (int i = 0; i < should; ++ i) 
				all += sub[i];

			f[x][fat] = min(f[x][fat], all);
		}
	}
	
}
int main() {
	int T;
	scanf("%d", &T);
	while (T --) {
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; ++ i) 
			G[i].clear();

		for (int i = 1; i < n; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}

		for (int i = 1; i <= n; ++ i) scanf("%d", &c[i]);
		for (int i = 1; i <= n; ++ i) scanf("%d", &p[i]);

		dfs(1);
		cout << f[1][0] << endl;
	}
}