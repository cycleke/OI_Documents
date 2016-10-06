#include <bits/stdc++.h>
using namespace std;
#define N 100005
bool mark[N];
vector<int>g[N];
int Stack[N], top;

inline void adde(int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}

bool dfs(int u) {
	if (mark[u^1]) return false;
	if (mark[u]) return true;
	mark[u] = true; Stack[++top] = u;
	for (int i = 0; i < g[u].size(); ++i) 
	  if (!dfs(g[u][i])) return false;
	return true;
}

bool Try(int n) {
	for (int i = 2, t = n << 2; i <= t; i += 2)
	  if (!mark[i] && !mark[i^1]) {
		  top = 0;
		  if (!dfs(i)) {
			  while(top) mark[Stack[top--]]=false;
			  if(!dfs(i^1)) return false;
		  }
	  }
	return true;
}


int main() {
	int n, m, a, b, s;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &a, &b, &s);
		if (s) {
			adde(a<<1,b<<1|1);
			adde(b<<1,a<<1|1);
		} else {
			adde(a<<1,b<<1);
			adde(a<<1|1,b<<1|1);
		}
	}
	if (Try(n)) {
		int cnt1, cnt2;
		for (int i = 2, t = n << 1; i <= t; i += 2)
		  cnt1 += mark[i], cnt2 += mark[i^1];
		printf("%d\n", min(cnt1,cnt2));
	} else puts("Pan must forget something.");
	return 0;
}
