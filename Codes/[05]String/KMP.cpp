template<typename T>
class calckmp {
  void computelps(vector<int> &lps,T &b,int m){
    int len=0,i=1;
    lps[0]=0;
    while(i<m){
      if(b[i]==b[len]){
          len++; lps[i]=len; i++;
      }else{
        if(len) len = lps[len-1];
        else lps[i]=0, i++;
      }
    }
  }
public:
  int match(T &a,T &b){
    int n=a.size();
    int m=b.size();
    vector<int> lps(m);
    int cnt=0;
    computelps(lps,b,m);
    int i=0, j=0;
    while(n-i >= m-j){
      if(a[i]==b[j]) i++, j++;
      if(j==m){
        cnt++;
        j=lps[j-1];
      }else if(i<n && a[i] != b[j]){
        if(j) j=lps[j-1];
        else i++;
      }
    }
    return cnt;
  }
};
