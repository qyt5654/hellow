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
int dfn[N],low[N],cut,es,idx;
std::vector<int>g[N];
void tarjan1(int x,int fa){//本质是dfs
    //初始化dfn和low
    dfn[x]=low[x]=++idx;
    int child=0;
    for(auto &i:g[x]){
        //不走父亲
        if(i==fa)continue;
        //判断是否为搜索树的儿子
        if(!dfn[i]){
            tarjan1(i,x);
            low[x]=std::min(low[x],low[i]);
            child+=(low[i]>=dfn[x]);
        }else{
            low[x]=std::min(low[x],dfn[i]);
        }
    }
    if((fa==0&&child>=2)||(fa!=0&&child>=1))cut++;
}
void tarjan2(int x,int fa){
    dfn[x]=low[x]=++idx;
    for(auto &i:g[x]){
        if(i==fa)continue;
        if(!dfn[i]){
            tarjan2(i,x);
            low[x]=std::min(low[x],low[i]);
            es+=(low[i]>dfn[x]);
        }else{
            low[x]=std::min(low[x],low[i]);
        }
    }
}
void dd(){
    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan1(i,0);
    for(int i=1;i<=n;i++)dfn[i]=low[i]=0;
    idx=0;
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan2(i,0);
    std::cout<<cut<<" "<<es<<'\n';
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
//    std::cin>>_;
    while(_--)dd();
    return 0;
}