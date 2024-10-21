template<typename T1,typename T2>
//T1 is main array and T2 is the data type of segment tree
class segtree{
  private:
  int n;
  T2 (*seg);
  T2 identity;
  int *lazy;
  T2 merge(T2 a,T2 b){
    return max(a,b);
  }
  void propagate(int idx,int val,int le,int ri){//change propagate function accordingly
    seg[idx] += (ri-le+1)*val;
    if(le != ri){
      lazy[2*idx+1] += val;
      lazy[2*idx+2] += val;
    }
    lazy[idx] = 0;
  }
  void build(int idx,int le, int ri,T1 a[]){
    if(le==ri){
      seg[idx] = a[le];       //how the main array will affect the segment tree
      return;
    }
    int mid=(le+ri)/2;
    build(idx*2+1,le,mid,a);
    build(idx*2+2,mid+1,ri,a);
    seg[idx] = merge(seg[2*idx+1],seg[2*idx+2]);
  }
  void update(int idx,int le,int ri,int l,int r,int val){
    if(lazy[idx]) propagate(idx,lazy[idx],le,ri);
    if(r<le || l>ri) return;
    if(le>=l && ri<=r){
      propagate(idx,val,le,ri); return;
    }
    int mid=(le+ri)/2;
    update(idx*2+1,le,mid,l,r,val);
    update(idx*2+2,mid+1,ri,l,r,val);
    seg[idx] = merge(seg[2*idx+1],seg[2*idx+2]);
  }

  T2 query(int idx,int le,int ri,int l,int r){
    if(lazy[idx]){
        propagate(idx,lazy[idx],le,ri);
    }
    if(l<=le && r>=ri) return seg[idx];
    if(r<le || l>ri) return identity;
    int mid=(le+ri)/2;
    return merge(query(idx*2+1,le,mid,l,r) , query(idx*2+2,mid+1,ri,l,r));
  }
  public:
  segtree(T1 arr[],int m,,T2 Identity){
    n=m;
    identity = Identity;
    seg = new T2[n*4];
    lazy = new int[n*4];
    memset(lazy,0,sizeof(lazy));
    build(0,0,n-1,arr);
  }
  void update(int l,int r,int val){
    update(0,0,n-1,l,r,val);
  }
  T2 query(int l,int r){
    return query(0,0,n-1,l,r);
  }
};
