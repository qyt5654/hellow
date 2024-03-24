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
int dfn[N],low[N],stk[N],top,idx;
int tot,cnt[N];
std::vector<int>g[N];
std::map<int,int>ins;
void tarjan(int x){//本质是dfs
    //初始化dfn和low
    dfn[x]=low[x]=++idx;
    //入栈并标记
    stk[++top]=x;
    ins[x]=1;
    //遍历儿子
    for(auto &i:g[x]){
        //判断是否是回点
        if(!dfn[i]){
            tarjan(i);
            low[x]=std::min(low[x],low[i]);
        }else if(ins[i]) low[x]=std::min(low[x],dfn[i]);
    }

    //收拢
    if(low[x]==dfn[x]){
        //新开一个颜色
        tot++;
        while(stk[top+1]!=x){
            //染色
            cnt[tot]++;
            //取消标记
            ins[stk[top--]]=0;
        }
    }
}
void dd(){
    int n,m,k=0;
    std::cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        g[u].emplace_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    std::vector<int>v;
    for(int i=1;i<=tot;i++){
        v.emplace_back(cnt[i]);
    }
    std::sort(v.begin(),v.end());
    for(auto &i:v){
        if(i>1){
            std::cout<<i<<" ";
            k=1;
        }
    }
    if(!k){
        std::cout<<"-1";
    }
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
//    std::cin>>_;
    while(_--)dd();
    return 0;
}