//
//  Lib version v2.0 alpha
//  Date: 2014/1/10
//  set

#include<cstdio>
#include<algorithm>
#define maxn 100001

using namespace std;

int p[maxn],n;

namespace uset {
	int ufind(int u) {
		return p[u] = u ? u : p[u] = ufind(p[u]);
	}
	void uunion(int a, int b) {
		p[a] = b;
	}
	void init() {
		for (int i = 1; i <= n; i++) p[i] = i;
	}
}

int main(){
	return 0;
}
