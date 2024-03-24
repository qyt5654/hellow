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
int n,q,a[N],rt[N];
std::vector<int>x;
int bin(int p){
    return std::lower_bound(x.begin(),x.end(),p)-x.begin()+1;
}

struct node{
    int ls,rs,val;
}t[N<<5];
int idx;

void insert(int &o,int pre,int val,int s=1,int e=n){
    //分配节点
    o=++idx;
    //复刻上一个版本
    t[o]=t[pre];
    //修改自身权值
    t[o].val++;
    //决策下一步
    if(s==e)return;
    int mid=(s+e)>>1;
    if(val<=mid){
        insert(t[o].ls,t[pre].ls,val,s,mid);
    }else{
        insert(t[o].rs,t[pre].rs,val,mid+1,e);
    }
}
int queryval(int lo,int ro,int k,int s=1,int e=n){
    if(s==e)return s;
    int left_sum=t[t[ro].ls].val-t[t[lo].ls].val;
    int mid=(s+e)>>1;
    if(k<=left_sum){
        return queryval(t[lo].ls,t[ro].ls,k,s,mid);
    }else{
        return queryval(t[lo].rs,t[ro].rs,k-left_sum,mid+1,e);
    }
}
void dd(){
    std::cin>>n>>q;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        x.emplace_back(a[i]);
    }
    //离散化，去重
    std::sort(x.begin(),x.end());
    x.erase(std::unique(x.begin(),x.end()),x.end());

    for(int i=1;i<=n;i++)insert(rt[i],rt[i-1],bin(a[i]));

    while(q--){
        int l,r,k;
        std::cin>>l>>r>>k;
        std::cout<<x[queryval(rt[l-1],rt[r],k)-1]<<'\n';
    }
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
/*    std::cin>>_;*/
    while(_--)dd();
    return 0;
}