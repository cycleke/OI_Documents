#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define pii pair<int,int>
int card[1005][1005],*f[1005],p[1005];
bool cmp(int *a, int *b) {
	for (int i=1;i<=*a && i<=*b;++i)
	  if(a[i]^b[i]) return a[i]<b[i];
	return *a < *b;
}
priority_queue< pii, vector< pii >, greater < pii > >heap;
int main() {
	int n,i,j,k; scanf("%d",&n);
	for(i=1;i<=n;++i) {
		scanf("%d",card[i]);
		for(j=1;j<=*card[i];++j) scanf("%d",card[i]+j);
		f[i]=card[i];
	}
	sort(f+1,f+n+1,cmp);
	for(i=1;i<=n;++i) heap.push(make_pair(f[i][1],i)),p[i]=1;
	pii q;
	while (!heap.empty()) {
		q=heap.top(); heap.pop();
		printf("%d ",q.first);
		k=q.second;
		if(p[k]<*f[k]) heap.push(make_pair(f[k][++p[k]],k));
	}return 0;
}
