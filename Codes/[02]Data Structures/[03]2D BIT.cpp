//forest query problem
int a[10001][10001],bin[10001][10001];
void update(int x,int y, int val, int n){
    for(int i=x; i<=n; i += i&-i){
        for(int j=y; j<=n; j += j&-j){
            bin[i][j]+=val;
        }
    }
}
int query(int x,int y){
  int sum = 0;
  for(int i=x; i>0; i -= i&-i){
    for(int j=y; j>0; j -= j&-j){
      sum += bin[i][j];
    }
  }
  return sum;
// check --> query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1)
}
