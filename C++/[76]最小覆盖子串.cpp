//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。 
//
// 
//
// 注意： 
//
// 
// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。 
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
//解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
// 
//
// 示例 2： 
//
// 
//输入：s = "a", t = "a"
//输出："a"
//解释：整个字符串 s 是最小覆盖子串。
// 
//
// 示例 3: 
//
// 
//输入: s = "a", t = "aa"
//输出: ""
//解释: t 中两个字符 'a' 均应包含在 s 的子串中，
//因此没有符合条件的子字符串，返回空字符串。 
//
// 
//
// 提示： 
//
// 
// m == s.length 
// n == t.length 
// 1 <= m, n <= 10⁵ 
// s 和 t 由英文字母组成 
// 
//
// 
//进阶：你能设计一个在 
//o(m+n) 时间内解决此问题的算法吗？
//
// Related Topics 哈希表 字符串 滑动窗口 👍 3193 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
  vector<bool> valid(128, false); // 用于标记字符是否在t中出现
  vector<int> freq(128, 0);       // 用于记录t中字符的频率

  // 统计t中的字符情况。
  for (int i = 0; i < t.length(); ++i) {
    valid[t[i]] = true; // 标记字符t[i]中所有有的都出现
    ++freq[t[i]]; 		// 增加字符t[i]的频率
  }
  // 移动滑动窗口，不断更改统计数据。
  // cnt用于记录窗口中包含t的字符的数量,windows_Left用于记录最小窗口的起始位置,minLen记录长度
    int minLen = -1,window_Left = -1,cnt = 0;
    for(int l=0,r=0;r<s.length();r++){
      if(!valid[s[r]])
        continue;// 如果s[r]不在t中，开始下一次循环
      if(--freq[s[r]]>=0){// 跳到了第r位置，把字符加入频率统计，并检查是否补充了t中缺失的字符。
		cnt++;// 如果 freq[s[r]] 是正数，说明s[r]是t中需要的字符，增加count，不全满者跳到下一循环中
      }
      while(cnt == t.length()){// 滑动窗口包含t中全部字符时，尝试右移l，在不影响结果的情况下寻找最短串。
        if(minLen == -1 || r-l+1 < minLen){
          window_Left = l;
          minLen = r-l+1;
        }
        if(valid[s[l]] && ++freq[s[l]]>0)// 把l位置的字符移除频率统计，并[检查]t中对应字符是否重新缺失。
          cnt--;// 如果 freq[s[l]] 变为正数，说明移除了t中需要的字符，减少count
      ++l;// 右移左边界
      }
    }
    return minLen == -1 ? "" : s.substr(window_Left,minLen);
  }
};
//leetcode submit region end(Prohibit modification and deletion)
