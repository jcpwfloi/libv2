#include<cstdio>
#include<algorithm>
#define maxn 100001

using namespace std;

int n, t[maxn];

namespace bit {
	inline int lowbit(int x) {
		return x&(-x);
	}
	int ___sum(int x) {
		int _temp = 0;
		for (int i = x; i > 0; i -= lowbit(i)) _temp += t[i];
		return _temp;
	}
	void add(int pos, int delta) {
		for (int i = pos; i <=n; i += lowbit(i)) t[i] += delta;
	}
	int Query(int l, int r) {
		return ___sum(r)-___sum(l-1);
	}
}

int main(){
	return 0;
}
