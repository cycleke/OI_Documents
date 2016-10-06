#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct edge{
    int f,c,to,from;
    edge *next,*fan;
};
int ca[1000000 + 10];
edge* used[1000000 + 10];
edge* head[1000000 +10];

void adde(const int& a,const int& b,const int& c)
{
    edge *n1 = new edge,*n2 = new edge;
    if(a == b)
    {
    	for(int i = 0;i <= 100;++i)
    	++i;
    	
    }
    n1->from = a,n1->to = b,n1->c = c,n1->f = 0,n1->next = head[a],n1->fan = n2,head[a] = n1;
    n2->from = b,n2->to = a,n2->c = c,n2->f = 0,n2->next = head[b],n2->fan = n1,head[b] = n2;
}

void bfs(const int& e)
{
    queue<int>q;
    q.push(1);
    memset(ca,0,sizeof(ca));
    ca[1] = 1 << 30;
    while(!q.empty())
    {
        int s = q.front();q.pop();
        if(s == e) return;
        for(edge* i = head[s];i != NULL;i = i->next)
        {
            int t = i->to;
			if(t == e)
            {
               	int qq = 10;
               	while(qq) --qq;
            }
            if(!ca[t] && i->c > i->f){
                q.push(t);
                used[t] = i;
                
                ca[t] = min(i->c - i->f,ca[s]);
            }
        }
    }
}

void work(const int& n,const int& m)
{
    int s = 1,e = m * n;
    long long ans = 0;
    while(1)
    {
        bfs(e);
        if(!ca[e]) break;
        for(edge* i = used[e];i->from != 1;i = used[i->from])
        {
            i->f += ca[e];
            i->fan->f -= ca[e];
        }
        ans+= ca[e];
    }
    printf("%lld",ans);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    int a;
    for(int i = 0;i < n;++i)
    for(int j = 1;j < m;++j)
    {
        scanf("%d",&a);
        adde(i * m + j,i * m + j + 1,a);
    }
    for(int i = 1;i < n;++i)
    for(int j = 0;j < m;++j)
    {
        scanf("%d",&a);
        adde(m * (i - 1) + j +1 ,m * i + j + 1,a);
    }
    for(int i = 1;i < n;++i)
    for(int j = 1;j < m;++j)
    {
        scanf("%d",&a);
        adde(j + m * (i - 1),m * i + j + 1,a);
    }
    work(n,m);

    return 0;
}
