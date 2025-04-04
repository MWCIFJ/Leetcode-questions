//闯关游戏需要破解一组密码，闯关组给出的有关密码的线索是： 
//
// 
// 一个拥有密码所有元素的非负整数数组 password 
// 密码是 password 中所有元素拼接后得到的最小的一个数 
// 
//
// 请编写一个程序返回这个密码。 
//
// 
//
// 示例 1： 
//
// 
//输入：password = [15, 8, 7]
//输出："1578" 
//
// 示例 2： 
//
// 
//输入：password = [0, 3, 30, 34, 5, 9]
//输出："03033459" 
//
// 
//
// 提示： 
//
// 
// 0 < password.length <= 100 
// 
//
// 说明: 
//
// 
// 输出结果可能非常大，所以你需要返回一个字符串而不是整数 
// 拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0 
// 
//
// 
//
// Related Topics 贪心 字符串 排序 👍 697 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string crackPassword(vector<int>& password) {
        vector <string> strs;
        string res;
        for(int i=0; i<password.size(); i++)
          strs.push_back(to_string(password[i]));//不断strcat
        sort(strs.begin(), strs.end(),[](string &x,string &y){return x+y<y+x;});
//x+y<y+x时进行排序，利用sort直接排序好
        for(int i=0; i<strs.size(); i++)
          res+=strs[i];
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)






