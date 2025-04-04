//现有一串神秘的密文 ciphertext，经调查，密文的特点和规则如下： 
//
// 
// 密文由非负整数组成 
// 数字 0-25 分别对应字母 a-z 
// 
//
// 请根据上述规则将密文 ciphertext 解密为字母，并返回共有多少种解密结果。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：ciphertext = 216612
//输出：6
//解释：216612 解密后有 6 种不同的形式，分别是 "cbggbc"，"vggbc"，"vggm"，"cbggm"，"cqgbc" 和 "cqgm" 
//
// 
//
// 提示： 
//
// 
// 0 <= ciphertext < 2³¹ 
//
//
// 
//
// Related Topics 字符串 动态规划 👍 621 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int crackNumber(int ciphertext) {
    string src = to_string(ciphertext);
//f(i) = f(i-1) + f(i-2)×bool(i-1>=0 && 10<x<25)，整套算法就是为了实现这个函数而已
    int p = 0, q = 0, r = 1;//p是f(i-2)，q是f(i-1)，r是f(i)，以此作滚动数组
    for(int i = 0;i<src.size();i++)
      {
          p = q;
          q = r;//构造好f(i)、f(i-1)与f(i-2)
          r = q;//f(i) = f(i-1)，后判断f(i-2)是否可以再加
          if(i == 0)
            continue;
          if(src.substr(i-1,2) >= "10" && src.substr(i-1,2) <= "25")
//substr 是C++中的一个函数，用于从字符串中提取子字符串。它从指定位置开始，并具有指定的长度。
            r+=p;
      }
      return r;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
