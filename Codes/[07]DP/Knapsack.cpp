/*
for 1 ---->
    1<=N<=100
    1<=W<=105
    1<=wi<=W
    1<=vi<=1e9
for 2 ---->
    1<=N<=100
    1<=W<=1e9
    1<=wi<=W
    1<=vi<=1e3
*/
int n,W,v[101],w[101],dp[101][N];

int ks(int i,int W){
    if(i>=n) return 0;
    if(dp[i][W]!=-1) return dp[i][W];
    if(W<w[i]) return dp[i][W]=ks(i+1,W);
    else return dp[i][W]=max(ks(i+1,W),ks(i+1,W-w[i])+v[i]);
}
void solve(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    cout<<ks(0,W)<<ln;
}

int knpsk2(int i,int val){
    if(val==0) return 0;
    if(i>=n) return INT_MAX;
    if(dp[i][val]!=-1) return dp[i][val];
    int b = ks(i+1,val);
    if(val-v[i]>=0) b = min(b,ks(i+1,val-v[i]) + w[i]);
    return  dp[i][val] = b;
}
void solve(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    int ans=0, sm=accumulate(v,v+n,0LL);; 
    for(int j=sm;j>=0;j--){
        if(ks(0,j)<=W){
            cout<<j<<ln;
            break;
        }
    }
}
