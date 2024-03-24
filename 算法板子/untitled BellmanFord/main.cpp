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
    const int N=1e4+10;
    std::vector<std::pair<int,int>>g[N];
    std::vector<int>d;
    int n,m;
    bool spfa(int st){//spfa算法
        for(int i=1;i<=n;i++)d[i]=INF;
        d[st]=0;
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
                if(d[y]>d[x]+w){
                    if(++cnt[y]>=n)return true;
                    d[y]=d[x]+w;
                    if(map[y]==0){
                        queue.emplace(y);
                        map[y]=1;
                    }
                }
            }
        }
        return false;
    }
    void dd(){
        std::cin>>n>>m;
        for(int i=1;i<=m;i++){
            int u,v,w;
            std::cin>>u>>v>>w;
            g[u].emplace_back(v,w);
        }
        d.resize(n+1,INF);
    //    bool cis=false;//BellmanFord算法
    //    d[1]=0;
    //    for(int i=1;i<=n;i++){
    //        cis=false;
    //        for(int x=1;x<=n;x++){
    //            for(auto [y,w]:g[x]){
    //                if(d[y]>d[x]+w){
    //                    d[y]=d[x]+w;
    //                    cis=true;
    //                }
    //            }
    //        }
    //    }
        if(spfa(1)){
            std::cout<<"-1\n";
        }else{
            for(int i=1;i<=n;i++)std::cout<<d[i]<<" ";
        }
    }
    signed main(){
        std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
        int _=1;
    //    std::cin>>_;
        while(_--)dd();
        return 0;
    }