#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n,maxn = 1e9 + 10,a,b,minn = 0;
  cin >> n;
  for(int i = 0;i < n;i++){
      cin >> a >> b;
      maxn = min(maxn,a / b);
      minn = max(minn,(int)ceil(a * 1.0 / (b + 1)));
  }
  cout << minn << " " << maxn;
  return 0;
}