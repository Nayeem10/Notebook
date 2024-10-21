void generate_hash(const string &s){
  LL n = s.size(), p = 31, m = 1e9 + 9;
  vector<LL> p_pow(n), h(n + 1, 0);
  p_pow[0] = 1;
  for(LL i = 1; i < n; i++) p_pow[i] = (p_pow[i - 1] * p) % m;
  // generate
  for(int i = 0; i < n; i++) h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
}
LL get_substring_hash(LL l, LL r) {
  LL cur_h = (h[r] + m - h[l - 1]) % m;
  cur_h = (cur_h * p_pow[n - l - 1]) % m;
  return cur_h;
}