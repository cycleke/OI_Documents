#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;

int r(int n){
	return n * (double)rand() / RAND_MAX; 
}

int f[100];

int find(int x){
	return f[x] ==x?x:f[x] = find(f[x]);
}

int main(){
	freopen("A.in","w",stdout);
	srand(time(NULL));
	int n = r(10) + 1;
	printf("%d \n",n);
	for(int i = 0;i < n;++i) printf("%d ",r(10) + 1);
	puts("");
	for(int i = 1;i <= n;++i) f[i] = i;
	for(int i = 1;i < n;){
		int x = rand() % n + 1,y = rand() % n + 1;
		int fx = find(x),fy = find(y);
		if(fx==fy) continue;
		++i;
		printf("%d %d\n",x,y);
		f[fx] = fy;
	}
	int m = r(5) + 1;
	printf("%d\n",m);
	while(m--)
	{
		int x = rand() % n + 1,y = rand() % n + 1;
		printf("%d %d\n",x,y);
	}
	return 0;
}
