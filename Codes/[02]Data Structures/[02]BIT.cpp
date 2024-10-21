int a[N],bin[N];

void update(int idx, int val, int n){
  while(idx<=n){
    bin[idx]+=val;
    idx += idx&-idx;
  }
}
int helper(int idx){
    int sum = 0;
    while(idx>0){
        sum+=bin[idx];
        idx -= idx&-idx;
    }
    return sum;
}
int query(int l,int r){
    return helper(r)-helper(l-1);
}
