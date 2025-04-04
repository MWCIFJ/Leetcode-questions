//实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xⁿ ）。 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 2.00000, n = 10
//输出：1024.00000
// 
//
// 示例 2： 
//
// 
//输入：x = 2.10000, n = 3
//输出：9.26100
// 
//
// 示例 3： 
//
// 
//输入：x = 2.00000, n = -2
//输出：0.25000
//解释：2-2 = 1/22 = 1/4 = 0.25
// 
//
// 
//
// 提示： 
//
// 
// -100.0 < x < 100.0 
// -231 <= n <= 231-1 
// n 是一个整数 
// 要么 x 不为零，要么 n > 0 。 
// -104 <= xⁿ <= 104 
// 
//
// Related Topics 递归 数学 👍 1431 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
double quickMul(double x, long long N) {
  double res = 1.0;
  double sacrifice = x;    // 贡献的初始值为 x
  while (N > 0) {
  if(N%2==1)
    res *= sacrifice;    // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
  sacrifice *= sacrifice;    // 将贡献不断地平方
  N/=2;    // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
  }
  return res;
}
double myPow(double x, int n) {
  long long N =n;
  return N>=0?quickMul(x,N):1.0/quickMul(x,-N);
}

//leetcode submit region end(Prohibit modification and deletion)
