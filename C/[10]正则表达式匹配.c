//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。 
//
// 
// '.' 匹配任意单个字符 
// '*' 匹配零个或多个前面的那一个元素 
// 
//
// 所谓匹配，是要涵盖 整个 字符串 s 的，而不是部分字符串。 
//
// 示例 1： 
//
// 
//输入：s = "aa", p = "a"
//输出：false
//解释："a" 无法匹配 "aa" 整个字符串。
// 
//
// 示例 2: 
//
// 
//输入：s = "aa", p = "a*"
//输出：true
//解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
// 
//
// 示例 3： 
//
// 
//输入：s = "ab", p = ".*"
//输出：true
//解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 20 
// 1 <= p.length <= 20 
// s 只包含从 a-z 的小写字母。 
// p 只包含从 a-z 的小写字母，以及字符 . 和 *。 
// 保证每次出现字符 * 时，前面都匹配到有效的字符 
// 
//
// Related Topics 递归 字符串 动态规划 👍 4025 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
bool isMatch(char* s, char* p){
    if (!*p) // 如果模式字符串p为空（即指向的字符为'\0'）
        return !*s; // 则返回s是否也为空（即s和p同时为空时返回true，否则返回false），是匹配完成的标志
    bool first_match = (*s && (*s == *p || *p == '.')); // 判断第一个字符是否匹配
//s不为空（*s不为'\0'）且s和p指向的字符相同，或者p指向的字符是'.'
    if (*(p+1) == '*')  // 如果模式字符串p的下一个字符是'*'
        // 不使用'*'，即跳过模式中的'*'和当前的字符(即共2个字符)，所以递归调用isMatch(s, p+2)
        // 使用'*'，即匹配字符，移动字符串指针s，递归调用isMatch(++s, p)
        return isMatch(s, p+2) || (first_match && isMatch(++s, p));
    else  // 如果模式字符串p的下一个字符不是'*'，匹配当前字符，同时移动字符串指针s和模式指针p
        return first_match && isMatch(++s, ++p);
}
//leetcode submit region end(Prohibit modification and deletion)
