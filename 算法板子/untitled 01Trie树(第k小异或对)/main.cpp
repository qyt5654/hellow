#include<bits/stdc++.h>
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define sst(n) setprecision(n)
#define INF 4e18
#define lowBit(n) ((n)&(-n))
#define pl (p*2)
#define pr (p*2+1)
#define mod 998244353
int ABS(int x) {return (x<0?-x:x);}
const int N=2e5+10;
int a[N];
struct Q{
    int id,t,x,k;
};
std::vector<Q>que;
struct node{
    int val;
    int son[2];
}t[N*32];
int idx,ans[N];
void insert(int x){
    int o=0;
    t[0].val++;
    for(int i=30;i>=0;i--){
        int y=x>>i&1;
        int &u=t[o].son[y];
        if(!u)u=++idx;
        o=u;
        t[o].val++;
    }
}
int getval(int x,int k){
    int o=0,res=0;
    for(int i=30;i>=0;i--){
        int y=x>>i&1;
        //u点是小点，v点是大点
        int u=t[o].son[y],v=t[o].son[!y];
        if(u&&t[u].val>=k)o=u;
        else o=v,k-=u?t[u].val:0,res|=(1<<i);
    }
    return res;
}
void dd(){
    int n,q;
    std::cin>>n>>q;
    for(int i=1;i<=n;i++)std::cin>>a[i];
    for(int i=0;i<q;i++){
        int tt,x,k;
        std::cin>>tt>>x>>k;
        que.push_back({i,tt,x,k});
    }
    std::sort(que.begin(),que.end(),[](Q u,Q v){
        return u.t!=v.t?u.t<v.t:u.id<v.id;
    });

    int now=0;
    for(auto qe:que){
        while(now<qe.t)insert(a[++now]);
        ans[qe.id]=getval(qe.x,qe.k);
    }
    for(int i=0;i<q;i++){
        std::cout<<ans[i]<<'\n';
    }
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
//    std::cin>>_;
    while(_--)dd();
    return 0;
}