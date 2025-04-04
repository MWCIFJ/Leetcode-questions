//给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。例如，字符串 "ababcc" 能够被分为 ["abab", 
//"cc"]，但类似 ["aba", "bcc"] 或 ["ab", "ab", "cc"] 的划分是非法的。 
//
// 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。 
//
// 返回一个表示每个字符串片段的长度的列表。 
//
// 
//示例 1：
//
// 
//输入：s = "ababcbacadefegdehijhklij"
//输出：[9,7,8]
//解释：
//划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
//每个字母最多出现在一个片段中。
//像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。 
//
// 示例 2： 
//
// 
//输入：s = "eccbbbbdec"
//输出：[10]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 500 
// s 仅由小写英文字母组成 
// 
//
// Related Topics 贪心 哈希表 双指针 字符串 👍 1257 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> partitionLabels(string s) {
		int hash[27] = {0};
// 创建一个哈希数组，用于存储每个字符最后一次出现的索引位置，数组大小为27，因为英文字母有26个，索引从0到25对应'a'到'z'
        for (int i = 0; i < s.size(); i++) // 遍历字符串S
            hash[s[i] - 'a'] = i; // 更新每个字符最后一次出现的索引位置，S[i] - 'a'将字符转换为0到25的索引
        vector<int> result; // 创建一个结果向量，用于存储每个分区的长度
        int left = 0; // 初始化左指针，表示当前分区的起始位置
        int right = 0; // 初始化右指针，表示当前分区的结束位置
        for (int i = 0; i < s.size(); i++) { // 再次遍历字符串S
            right = max(right, hash[s[i] - 'a']);
// 更新右指针为当前字符最后一次出现的位置和右指针当前值的最大值，确保右指针覆盖所有遇到字符的最远位置
            if (i == right) { // 如果当前索引i等于右指针，说明当前分区已经可以确定，因为已经覆盖了所有遇到字符的最远位置
                result.push_back(right - left + 1); // 计算当前分区的长度并添加到结果向量中
                left = i + 1; // 更新左指针为下一个分区的起始位置
            }
        }
        return result; // 返回结果向量，包含每个分区的长度
    }
};
//leetcode submit region end(Prohibit modification and deletion)
