array<LL, 3> maxSubArraySum(std::vector<LL> &v, LL n) {
  LL max_so_far = -INF, max_ending_here = 0, start = 0, end = 0, s = 0;
  for(int i = 0; i < n; i++) {
    max_ending_here += v[i];
    if(max_so_far < max_ending_here) {
      max_so_far = max_ending_here;
      start = s, end = i;
    }
    if(max_ending_here < 0) {
      max_ending_here = 0;
      s = i + 1;
    }
  }
  return {max_so_far, start, end};
}