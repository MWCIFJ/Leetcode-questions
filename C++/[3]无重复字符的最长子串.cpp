//给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s 由英文字母、数字、符号和空格组成 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 10663 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //滑动窗口，确保窗口内所有字符都是唯一的
        vector<int> m(128, 0);    //m来记录一个字母如果后面出现重复时，i 应该调整到的新位置
        int ans = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            i = max(i, m[s[j]]);    //这不是二维数组，而是双重映射。类似于存储这个数组的所有索引。而且以此的话，必定后i代替前i。
//Ex:j:0 1 2 3。s[j]:d v d f。m[s[j]]:1 2 3 4
            m[s[j]] = j + 1;        //m窗口的新一位(就是s[j]的后一位)，j+1来给m进行每一次的边界扩张
            ans = max(ans, j - i + 1);//不断比较窗口大小，以更新最大的窗口值
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)