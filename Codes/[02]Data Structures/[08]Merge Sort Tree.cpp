const int inf = 1e9 + 7;
const int N = 5e4 + 7;
int n, m;
int a[N];
vector<int> tree[N * 4];
vector<int> merge(vector<int> a,vector<int> b){
  int i=0, j=0, sza=a.size(), szb=b.size();
  vector<int> ret;
  while (i < sza or j < szb){
    if (i == sza) ret.emplace_back(b[j++]);
    else if (j == szb) ret.emplace_back(a[i++]);
    else{
      if (a[i] < b[j]) ret.emplace_back(a[i++]);
      else ret.emplace_back(b[j++]);
    }
  }
  return ret;
}
void build(int v, int l, int r){
  if (l == r) return void(tree[v] = {a[l]});
  int m = l + (r - l) / 2;
  build(v * 2, l, m);
  build(v * 2 + 1, m + 1, r);
  tree[v] = merge(tree[v * 2], tree[v*2+1]);
}
int query(int v, int l, int r, int ql,int qr, int k){
  if (r < ql or qr < l) return 0;
  if (l >= ql and r <= qr){
    int lo = 0, hi = (int)tree[v].size() - 1, pos = -1;
    while (lo <= hi){
      int mid = lo + (hi - lo) / 2;
      if (tree[v][mid] > k) hi = mid - 1;
      else pos = mid, lo = mid + 1;
    }
    return pos + 1;
  }
  else{
      int m = l + (r - l) / 2;
      return query(v * 2, l, m, ql, qr, k) + query(v * 2 + 1, m + 1, r, ql, qr, k);
  }
}
void update(int v, int b, int e, int i,int x){
  if (b == e) return void(tree[v] = {x});
  int mid = b + (e - b) / 2;
  if (mid < i) update(v * 2 + 1, mid + 1, e, i, x);
  else update(v * 2, b, mid, i, x);
  tree[v] = merge(tree[v * 2], tree[v*2+1]);
}
//build(1, 0, n - 1),query(1, 0, n - 1, l - 1, r - 1, k)
