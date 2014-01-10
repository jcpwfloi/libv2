//
//  Lib version v2.0 alpha
//  Date: 2014/1/10
//  Segmentational Tree
#include<cstdio>
#include<algorithm>
#define lson (u << 1)
#define rson ((u << 1) | 1)
#define T_MAX 300001

using namespace std;

int A[T_MAX/3];

namespace sgt {
	struct Node {
		int L, R, min, tag;
	} T[T_MAX];
	inline void Cover(int u, int C) {
		T[u].min += C;
		T[u].tag += C;
	}
	inline void Update(int u) {
		T[u].min = min (T[lson].min, T[rson].min);
	}
	inline void Push(int u) {
		if (T[u].tag) {
			Cover(lson, T[u].tag);
			Cover(rson, T[u].tag);
			T[u].tag = 0;
		}
	}
	int Query(int u, int L, int R) {
		if (L <= T[u].L && T[u].R <= R) {
			return T[u].min;
		}
		Push(u);
		int ans = INT_MAX;
		if (L <= T[lson].R) ans = min (ans, Query(lson, L, R));
		if (R >= T[rson].L) ans = min (ans, Query(rson, L, R));
		return ans;
	}
	void Edit(int u, int L, int R, int C) {
		if (L <= T[u].L && T[u].R <= R) {
			Cover(u, C);
			return;
		}
		Push(u);
		if (L <= T[lson].R) Edit(lson, L, R, C);
		if (R >= T[rson].L) Edit(rson, L, R, C);
		Update(u);
	}
	void Build(int u, int L, int R) {
		T[u].L = L;
		T[u].R = R;
		if (L == R) {
			T[u].min = A[L];
			return;
		}
		int M = (L + R) >> 1;
		Build(lson, L, M);
		Build(rson, M+1, R);
		Update(u);
		return;
	}
}

int main(){
	return 0;
}
