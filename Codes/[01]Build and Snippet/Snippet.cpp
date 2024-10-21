int main()
{
  mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
  auto begin = std::chrono::high_resolution_clock::now();
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int T = 1; // cin >> T;
  // cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for(int testCase=1;testCase<=T;testCase++) {
    // cout << fixed << setprecision(1);
    // cout << "Case " << testCase << ": ";
    solve(testCase);
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}