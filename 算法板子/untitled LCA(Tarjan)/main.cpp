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
int fa[N],ans[N],pre[N],deep[N];
std::vector<int>g[N];
std::vector<std::pair<int,int> >Q[N];
std::map<int,int>vis;
int find(int x){
    return pre[x]=(pre[x]==x?x:find(pre[x]));
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    pre[fx]=fy;
}
void dfs(int x){
    vis[x]++;
    deep[x]=deep[fa[x]]+1;
    for(auto &i:g[x]){//处理儿子所在子树
        dfs(i);
    }
    for(auto [y,id]:Q[x]){
        if(!vis[y])continue;
        ans[id]=find(y);
    }
    merge(x,fa[x]);
}
void dd(){//dfs与并查集维护
    int n;
    std::cin>>n;
    pre[1]=1;
    for(int i=2;i<=n;i++){
        std::cin>>fa[i];
        g[fa[i]].emplace_back(i);
        pre[i]=i;
    }
    int q,i=1;
    std::cin>>q;
    while(i<=q){
        int u,v;
        std::cin>>u>>v;
        Q[u].emplace_back(v,i);
        Q[v].emplace_back(u,i);
        i++;
    }
    dfs(1);
    for(int j=1;j<=q;j++)std::cout<<ans[j]<<'\n';
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
//    std::cin>>_;
    while(_--)dd();
    return 0;
}