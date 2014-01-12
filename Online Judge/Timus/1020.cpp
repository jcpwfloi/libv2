#include<cstdio>
#include<algorithm>
#include<cmath>
#define maxn 101

using namespace std;

int n;
double r, ans;
double const pi = 3.1415926;
double x[maxn], y[maxn];

double dist(int a, int b) {
	return sqrt( (x[a]-x[b]) * 1.0 * (x[a]-x[b]) + (y[a]-y[b]) * 1.0 * (y[a]-y[b]) );
}

int main(){
	scanf("%d%lf",&n,&r);
	if (n == 1) {
		ans = 2 * pi * r;
	} else {
		ans += 2 * pi * r;
		for (int i = 1; i <= n; i++) {
			scanf("%lf%lf", &x[i], &y[i]);
		}
		ans += dist(1, n);
		for (int i = 2; i <= n; i++) ans += dist(i, i-1);
	}
			printf("%.2lf", ans);
	return 0;
}
