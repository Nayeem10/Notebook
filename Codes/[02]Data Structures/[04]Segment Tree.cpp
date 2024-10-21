class segmentTree{
  int *seg; int n;
  int merge(int a,int b){
      return max(a,b);
  }
  void build(int idx,int le, int ri,vector<int> &v){
    if(le==ri){
      seg[idx] = v[le]; return;
    }
    int mid=(le+ri)>>1;
    build(2*idx+1, le,mid,v);
    build(2*idx+2,mid+1,ri,v);
    seg[idx] = merge(seg[2*idx+1],seg[2*idx+2]);
  }
  void update(int idx, int le,int ri,int k,int val){
    if(le==ri){
      seg[idx] = val; return;
    }
    int mid = (le+ri) >> 1;
    if(k<=mid) update(2*idx+1,le,mid,k,val);
    else update(2*idx+2,mid+1,ri,k,val);
    seg[idx] = merge(seg[2*idx+1],seg[2*idx+2]);
  }
  int query(int idx,int le,int ri,int l,int r){
    if(l<=le && r>=ri) return seg[idx];
    if(r<le || l>ri) return 0;  ///////identity
    int mid = (le+ri) >> 1;
    return  merge(query(2*idx+1,le,mid,l,r) , query(2*idx+2,mid+1,ri,l,r));
  }
  public:
  segmentTree(int m,vector<int> &v){
    n = m;
    seg = new int [4*n];
    build(0,0,n-1,v);
  }
  void update(int k,int val){
    update(0,0,n-1,k,val);
  }
  int query(int l,int r){
    return query(0,0,n-1,l,r);
  }
};
//extra part: use of array compression with segment tree
void compressarray(){  //longest increasing and decreasing subsequence
  int n; cin>>n;
  int a[n],b[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    b[i] = a[i];
  }
  sort(b,b+n);
  int l[n], r[n]; //increasing and decreasing subsequence from each i[0,n-1]
  vector<int> v(n,0);
  segmentTree treel(n,v),treer(n,v);
  for(int i=0;i<n;i++){
    int pos = lower_bound(b,b+n,a[i])-b;
    int val = (treel.query(0,pos-1));
    l[i] = val;
    treel.update(pos,val+1);
  }
  for(int i=n-1;i>=0;i--){
    int pos = lower_bound(b,b+n,a[i])-b;
    int val = (treer.query(0,pos-1));
    r[i] = val;
    treer.update(pos,val+1);
  }
}
