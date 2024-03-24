#include<bits/stdc++.h>
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define sst(n) setprecision(n)
#define INF 4e18
#define lowBit(n) ((n)&(-n))
#define pl (p*2)
#define pr (p*2+1)
const int N=3010;
std::vector<int>g[N];
int p[N];//表示女生i，所匹配的男生的编号
int vis[N],dfn;
bool dfs(int x){
    //枚举所有暧昧对象
    for(auto &y:g[x]){
        if(vis[y]==dfn)continue;
        vis[y]=dfn;
        if(!p[y]||dfs(p[y])){
            p[y]=x;
            return true;
        }
    }
    return false;
}
void dd(){
    int n,m,k;
    std::cin>>n>>m>>k;
    while(k--){
        int u,v;
        std::cin>>u>>v;
        g[u].emplace_back(v);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        dfn++;
        if(dfs(i))ans++;
    }
    std::cout<<ans<<'\n';
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
//    std::cin>>_;
    while(_--)dd();
    return 0;
}