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
int t[4*N];
void pushup(int p){
    t[p]=t[pl]+t[pr];
}
void insert(int val,int s,int e,int p){
    if(s==e){
        t[p]++;
        return;
    }
    int mid=(s+e)>>1;
    if(mid>=val){
        insert(val,s,mid,pl);
    }else{
        insert(val,mid+1,e,pr);
    }
    pushup(p);
}
int querycnt(int l,int r,int s,int e,int p){
    if(l<=s&&r>=e)return t[p];
    int mid=(s+e)>>1;
    int res=0;
    if(std::max(s,l)<=std::min(mid,r))res+=querycnt(l,r,s,mid,pl);
    if(std::max(mid+1,l)<=std::min(e,r))res+=querycnt(l,r,mid+1,e,pr);
    return res;
}
int queryval(int k,int s,int e,int p){
    if(s==e)return s;
    int left_sum=t[pl],mid=(s+e)>>1;
    if(k<=left_sum)return queryval(k,s,mid,pl);
    return queryval(k-left_sum,mid+1,e,pr);
}
void dd(){
    int n;
    std::cin>>n;
    while(n--){
        int x;
        std::cin>>x;
        if(x==1){
            int y;
            std::cin>>y;
            insert(y,1,N,1);
        }
        if(x==2){
            int l,r;
            std::cin>>l>>r;
            std::cout<<querycnt(l,r,1,N,1)<<'\n';
        }
        if(x==3){
            int y;
            std::cin>>y;
            std::cout<<queryval(y,1,N,1)<<'\n';
        }
    }
}
signed main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int _=1;
/*    std::cin>>_;*/
    while(_--)dd();
    return 0;
}