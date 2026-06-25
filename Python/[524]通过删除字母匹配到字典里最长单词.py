# 给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。
#  
# 
#  如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
# 输出："apple"
#  
# 
#  示例 2： 
# 
#  
# 输入：s = "abpcplea", dictionary = ["a","b","c"]
# 输出："a"
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= s.length <= 1000 
#  1 <= dictionary.length <= 1000 
#  1 <= dictionary[i].length <= 1000 
#  s 和 dictionary[i] 仅由小写英文字母组成 
#  
# 
#  Related Topics 数组 双指针 字符串 排序 👍 384 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
# 对字典中的单词进行排序，首先按照长度降序排序，如果长度相同，则按照字母升序排序,以便直接快速筛选
        dictionary.sort(key=lambda x: (-len(x), x))
        for t in dictionary:# 遍历排序后的字典中的每个单词
            i = j = 0   #i用于遍历单词t，j用于遍历字符串s
            while i < len(t) and j < len(s):
                if t[i] == s[j]:# 如果t中的字符和s中的字符匹配，移动指针i到下一个字符
                    i += 1
                j += 1# 无论是否匹配，都移动指针j到下一个字符
            if i == len(t):# 如果i等于t的长度，说明t是s的子序列
                return t# 返回找到的最长且字母序最小的单词
        return ""# 如果没有找到任何子序列，返回空字符串
# leetcode submit region end(Prohibit modification and deletion)