//你在与一位习惯从右往左阅读的朋友发消息，他发出的文字顺序都与正常相反但单词内容正确，为了和他顺利交流你决定写一个转换程序，把他所发的消息 message 转
//换为正常语序。 
//
// 注意：输入字符串 message 中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空
//格。 
//
// 
//
// 示例 1： 
//
// 
//输入: message = "the sky is blue"
//输出: "blue is sky the"
// 
//
// 示例 2： 
//
// 
//输入: message = "  hello world!  "
//输出: "world! hello"
//解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
// 
//
// 示例 3： 
//
// 
//输入: message = "a good   example"
//输出: "example good a"
//解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= message.length <= 10⁴ 
// message 中包含英文大小写字母、空格和数字 
// message 中至少有一个单词 
// 
// 
//
// 注意： 
//
// 
// 本题与主站 151 题相同：https://leetcode-cn.com/problems/reverse-words-in-a-string/ 
// 
//
// 
//
// Related Topics 双指针 字符串 👍 334 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseMessage(string message) {
        string str;
        auto it2 = message.crbegin();
        for(auto it1 = message.crbegin();it1!=message.crend();++it1){
          if(*it1 == ' ')
            {
                continue;
            }else{
                it2 = it1; // 标记当前单词的起始位置
                while (it1 != message.crend() && *it1 != ' ') {
                    ++it1;
                    // 从该单词的末尾，向前移动迭代器，直到遇到空格或字符串的起始位置
                    }
                str.append(it1.base(), it2.base()); // 将当前单词添加到结果字符串中
                //str.append(it1.base(), it2.base()) 将 it1.base()
                // 和 it2.base() 之间的字符添加到 str 的末尾。也就是一个单词
                str.push_back(' '); // 在单词后添加一个空格
                --it1; // 将迭代器回退一个位置，以便下一次循环从正确的位置开始
                }
            }
           if(!str.empty())
             str.erase(str.end()-1);
    return str;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
