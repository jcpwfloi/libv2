#include<cstdio>
#include<algorithm>
#include<vector>
#define maxn 100001

using namespace std;

struct Edge {
	int u, v, w;
	bool operator < (const Edge& x) const {
		return this -> w < x.w;
	}
};

int n, m, e, cost = 0, sel = 0;
Edge Edges[maxn];
int p[maxn];

int ufind(int x) {
	return p[x] == x ? x : p[x] = ufind(p[x]);
}

void uunion(int a, int b) {
	p[a] = b;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) p[i] = i;
	e = 0;
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		Edges[e++] = (Edge) {u, v, w};
		Edges[e++] = (Edge) {v, u, w};
	}
	sort(Edges, Edges+e);
	for (int i = 0; i < e && sel < n-1; i++) {
		int u = Edges[i].u, v = Edges[i].v, w = Edges[i].w;
		if (ufind(u) != ufind(v)) {
			uunion(u, v);
			cost += w;
			sel ++;
		}
	}
	if (sel == n-1) printf("%d\n", cost); else printf("-1\n");
}
