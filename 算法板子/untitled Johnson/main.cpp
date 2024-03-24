#include<bits/stdc++.h>
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define sst(n) setprecision(n)
#define INF (int)4e18
#define lowBit(n) ((n)&(-n))
#define pl (p*2)
#define pr (p*2+1)
#define mod 998244353
int ABS(int x) {return (x<0?-x:x);}
const int N=3e3+10;
int n,m,h[N],d[N][N];
std::vector<std::pair<int,int> >g[N];
bool spfa(int st){//spfa算法
    for(int i=1;i<=n;i++)h[i]=INF;
    h[st]=0;
    std::queue<int>queue;
    std::map<int,int>map;
    std::vector<int>cnt(n+1,0);
    queue.emplace(st);
    map[st]=1;
    while(!queue.empty()){
        auto x=queue.front();
        queue.pop();
        map[x]=0;
        for(auto [y,w]:g[x]){
            if(h[y]>h[x]+w){
                if(++cnt[y]>=n)return true;
                h[y]=h[x]+w;
                if(map[y]==0){
                    queue.emplace(y);
                    map[y]=1;
                }
            }
        }
    }
    return false;
}
void dijkstra(int x,int d[]){
    for(int i=1;i<=n;i++)d[i]=INF;
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<> >queue;
    queue.emplace(d[x]=0,x);
    std::map<int,int>map;
    while(!queue.empty()){
        auto [u,w]=queue.top();
        queue.pop();
        if(map[w])continue;
        map[w]=1;
        for(auto &[i,j]:g[w]){
            if(d[i]>j+u){
                d[i]=j+u;
                queue.emplace(d[i],i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        d[i]=d[i]-h[x]+h[i];
    }
}
void dd(){
    std::cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,w;
        std::cin>>x>>y>>w;
        g[x].emplace_back(y,w);
    }
    for(int i=1;i<=n;i++)g[0].emplace_back(i,0),h[i]=INF;
    if(spfa(0)){
        std::cout<<"starrycoding\n";
        return;
    }
    for(int x=1;x<=n;x++){
        for(auto &[y,w]:g[x])w=w+h[x]-h[y];
    }
    for(int i=1;i<=n;i++){
        dijkstra(i,d[i]);
    }
    int q;
    std::cin>>q;
    while(q--){
        int l,r;
        std::cin>>l>>r;
        if(d[l][r]>=INF/2){
            std::cout<<"noway"<<'\n';
        }else std::cout<<d[l][r]<<'\n';
    }
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
//    std::cin>>_;
    while(_--)dd();
    return 0;
}