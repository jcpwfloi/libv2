//
//  Lib version v2.0 alpha
//  Date: 2014/1/11
//  topological algorithm

#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 100001
#define SIZE(x) (int)x.size()

using namespace std;

vector<int> G[maxn];
queue<int> Q;
int D[maxn],n,m;
bool Del[maxn];

void Topology() {
	for (int i = 1; i <= n; i++) {
		if (D[i] < 2) Q.push(i);
		Del[i] = false;
	}
	while (!Q.empty()) {
		int u = Q.front(); Q.pop(); Del[u] = true;
		for (int i = 0; i < SIZE(G[u]); i++) if (!Del[G[u][i]]){
			int v = G[u][i];
			D[v] --;
			if (D[v] < 2) Q.push(v);
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u,v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
		D[u]++; D[v]++;
	}
	//for (int i = 1; i <= n; i++) printf("%d%c", D[i], i == n ? '\n' : ' ');
	Topology();
	for (int i = 1; i <= n; i++) if (!Del[i]) printf("%d%c", i, i == n ? '\n' : ' ');
	return 0;
}
