#include<bits/stdc++.h>
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define sst(n) setprecision(n)
#define INF 4e18
#define lowBit(n) ((n)&(-n))
#define pl (p*2)
#define pr (p*2+1)
const int N=5010;
std::vector<std::pair<int,int>>g[N];
int n,m,d[N];
bool spfa(){
    for(int i=1;i<=n;i++)d[i]=INF;
    std::bitset<N>vis;
    std::queue<int>queue;
    queue.emplace(0);
    vis[0]=true;
    std::vector<int>cnt(n+1,0);
    while(!queue.empty()){
        int x=queue.front();queue.pop();
        vis[x]=false;
        for(auto &[y,w]:g[x]){
            if(d[x]+w<d[y]){
                d[y]=d[x]+w;
                if(++cnt[y]>=n){
                    return false;
                }
                if(!vis[y]){
                    queue.emplace(y);
                    vis[y]=true;
                }
            }
        }
    }
    return true;
}
void dd(){//x1+w<=x2,x3+w<=x2:::::::::::作图
    std::cin>>n>>m;
    for(int i=0;i<=n;i++)g[i].clear();
    while(m--){
        int op,x,y,w;
        std::cin>>op;
        if(op==1){
            std::cin>>x>>y>>w;
            g[y].emplace_back(x,w);
        }
        if(op==2){
            std::cin>>x>>y>>w;
            g[x].emplace_back(y,-w);
        }
        if(op==3){
            std::cin>>x>>y;
            g[x].emplace_back(y,0);
            g[y].emplace_back(x,0);
        }
    }
    for(int i=1;i<=n;i++)g[0].emplace_back(i,0);
    if(spfa()){
        std::cout<<"YES\n";
    }else{
        std::cout<<"NO\n";
    }
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
    std::cin>>_;
    while(_--)dd();
    return 0;
}