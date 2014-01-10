//
//  Lib version v2.0 alpha
//  Date: 2014/1/10
//  Eratosthenes algorithm
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define maxn 1000001
#define SIZE(x) (int)x.size()

using namespace std;

vector<int> Prime;
bool isnotprime [maxn];

inline void Eratosthenes (int n) {
	memset(isnotprime, 0, sizeof(isnotprime));
	for (int i = 2; i <= sqrt(n); i++) {
		if (!isnotprime [i])
			for (int j = i*i; j <= n; j += i) {
				isnotprime[j] = true;
			}
		}
	for (int i = 2; i <= n; i++) if (!isnotprime [i]) Prime.push_back(i);
}

int main(){
	int n;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	Eratosthenes(n);
	for (vector<int>::iterator i = Prime.begin(); i != Prime.end(); i++) {
		printf("%d ",*i);
	}
	printf("\n");
	fclose(stdin);
	fclose(stdout);
    return 0;
}
