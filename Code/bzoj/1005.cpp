#include <cstdio>
#define SIZE 169
const int prime[SIZE] = {
	0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,  
	79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,  
	193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,  
	313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,  
	443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,  
	587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,  
	719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,
	859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997
};
int cnt[SIZE], ans[10001];

void Cal(int n, int m) {
	for (int i = m + 1; i <= n; ++i) 
	  for (int t = i, j = 1; t > 1; ++j)
		while (!(t % prime[j])) t /= prime[j], ++cnt[j];
	for (int i = n - m; i; --i)
	  for (int t = i, j = 1; t > 1; ++j)
		while (!(t % prime[j])) t /= prime[j], --cnt[j];
}

int main() {
	int n, len, a, sum = 0, i, j, t;
	scanf("%d", &n); len = n - 2;
	for (i = 0; i < n; ++i) {
		scanf("%d", &a);
		if (!a || len + 1 < a) return printf("0"), 0;
		if (a == -1) { ++sum; continue; } --a;
		Cal(len, a); len -= a;
	}
	if (len) {
		for (t = sum, j = 1; t > 1; ++j)
		  while (!(t % prime[j])) t /= prime[j], cnt[j] += len;
	}
	ans[1] = len = 1;
	for (j = 1; j < SIZE; ++j)
	  while (cnt[j]--) {
		for (i = 1; i <= len; ++i) ans[i] *= prime[j];
		for (i = 1; i <= len; ++i) if (ans[i] > 9) ans[i+1] += ans[i] / 10, ans[i] %= 10;
		while (ans[len+1]) {
			++len;
			ans[len+1] += ans[len] / 10;
			ans[len] %= 10;
		}
	  }
	for (i = len; i; --i) printf("%d", ans[i]);
	return 0;
}

