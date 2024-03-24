#include<bits/stdc++.h>
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define sst(n) setprecision(n)
#define INF 4e18
#define lowBit(n) ((n)&(-n))
#define pl (p*2)
#define pr (p*2+1)
const int N=200010;
std::vector<int>g[N];
int col[N];
bool dfs(int x){
    for(const auto &y:g[x]){
        if(col[y]==-1){
            col[y]=1^col[x];
            if(!dfs(y))return false;
        }
        if(col[y]==col[x])return false;
    }
    return true;
}
void dd(){
    int n,m;
    std::cin>>n>>m;
    while(m--){
        int u,v;
        std::cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i=1;i<=n;i++)col[i]=-1;
    int ans=1;
    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            col[i]=0;
            if(!dfs(i))ans=0;
        }
    }
    std::cout<<(ans?"YES\n":"NO\n");
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
//    std::cin>>_;
    while(_--)dd();
    return 0;
}