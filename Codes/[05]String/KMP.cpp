int KMP(vector<int> &a, vector<int> &b) { // number of occurance of a in b
  vector<int> pi(n);
  for (int i = 1, j = 0; i < n; i++) {
    while (j && a[i] != a[j]) j = pi[j - 1];
    if (a[i] == a[j]) j++;
    pi[i] = j;
  }
  int ans = 0;
  for (int i = 0, j = 0; i < m; i++) {
    while (j && b[i] != a[j]) j = pi[j - 1];
    if (a[j] == b[i]) j++;
    if (j == n) ans++, j = pi[j - 1];
  }
  return ans;
}
