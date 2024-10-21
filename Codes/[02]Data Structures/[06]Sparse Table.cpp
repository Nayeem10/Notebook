LL sparseTable[MAXN][(LL)log2(MAXN) + 5];
void build(LL n, vector<LL> &v){
  for(LL i = 0; i < n; i++) sparseTable[i][0] = v[i];
  for(LL j = 1; (1 << j) <= n; j++) {
    for(LL i = 0; (i + (1 << j) - 1) < n; i++)
      sparseTable[i][j] = min(sparseTable[i][j - 1], sparseTable[i + (1 << (j - 1))][j - 1]);
  }
}
LL query(LL L, LL R){
  LL j = (LL)log2(R - L + 1);
  return min(sparseTable[L][j], sparseTable[R - (1 << j) + 1][j]);
}

// 2-DIMENTIONAL SPARSE TABLE FOR A MATRIX/GRID
ll grid[MAXN][MAXN];
ll sparseTable[MAXN][MAXN][10];
void build(ll n){
  for(ll k=0;(1 << k)<=n;k++) {
    for(ll i=0;i+(1 << k)-1 < n;i++) {
      for(ll j=0;j+(1 << k)-1 < n;j++) {
        if(!k) sparseTable[i][j][k] = grid[i][j];
        else {
          ll power = 1 << (k - 1);
          sparseTable[i][j][k] = max({sparseTable[i][j][k - 1], sparseTable[i + power][j][k - 1], sparseTable[i][j + power][k - 1], sparseTable[i + power][j + power][k - 1]});
        }
      }
    }
  }
}
ll query(ll i, ll j, ll s){
  ll k = log2(s);
  ll power = 1 << k;
  return max({sparseTable[i][j][k], sparseTable[i + s - power][j][k], sparseTable[i][j + s - power][k], sparseTable[i + s - power][j + s - power][k]});
}
void SPARSE_TABLE(){
  build(n);
  while(q--) {
    ll R, C, S; cin >> R >> C >> S;
    R--; C--;
    cout << query(R, C, S) << endl;
  }
}
