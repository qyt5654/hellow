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
int a[N],fa[N][30],deep[N];
std::vector<int>g[N];
void dfs(int x){
    for(int i=1;i<=20;i++){
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    for(auto &i:g[x]){
        deep[i]=deep[x]+1;
        dfs(i);
    }
}
int lca(int x,int y){
    if(deep[x]<deep[y])std::swap(x,y);
    //使得deep[x]>=deep[y]
    for(int i=20;i>=0;i--){
        if(deep[fa[x][i]]>=deep[y])x=fa[x][i];
    }
    if(x==y)return y;
    for(int i=20;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[y][0];
}
void dd(){
    int n;
    std::cin>>n;
    for(int i=2;i<=n;i++){
        std::cin>>fa[i][0];
        g[fa[i][0]].emplace_back(i);
    }
    deep[1]=1;
    dfs(1);
    int q;
    std::cin>>q;
    while(q--){
        int u,v;
        std::cin>>u>>v;
        std::cout<<lca(u,v)<<'\n';
    }
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
//    std::cin>>_;
    while(_--)dd();
    return 0;
}