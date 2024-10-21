void coin(){  //given different types of coin how many way number x can be formed?
    int n,x,mod=1e9+7; cin>>n>>x;
    int a[n], dp[x+1]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<=x) dp[a[i]]=1;
    }
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i>= a[j]){
                dp[i] += dp[i-a[j]];
                dp[i] %= mod;
            }
        }
    }
    cout<<dp[x]<<ln;
}