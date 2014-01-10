#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 100001
#define INF 0x7FFFFFFF
#define SIZE(x) (int)x.size()

using namespace std;

vector<int> G[maxn],W[maxn];
queue<int> Q;
int D[maxn],n,m;
bool B[maxn];

inline void SPFA(int S) {
	for (int i = 1; i <= n; i++) D[i] = INF, B[i] = false;
	D[S] = 0; Q.push(S); B[S] = true;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop(); B[u] = false;
		for (int i = 0; i < SIZE(G[u]); i++) {
			int v = G[u][i];
			if (D[v] > D[u] + W[u][i]) {
				D[v] = D[u] + W[u][i];
				if (!B[v]) {
					B[v] = true;
					Q.push(v);
				}
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back(v), G[v].push_back(u);
		W[u].push_back(w), W[v].push_back(w);
	}
	SPFA(1);
	printf("%d\n", D[n]);
	return 0;
}
