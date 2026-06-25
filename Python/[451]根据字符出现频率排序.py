# 给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的 频率 是它出现在字符串中的次数。 
# 
#  返回 已排序的字符串 。如果有多个答案，返回其中任何一个。 
# 
#  
# 
#  示例 1: 
# 
#  
# 输入: s = "tree"
# 输出: "eert"
# 解释: 'e'出现两次，'r'和't'都只出现一次。
# 因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
#  
# 
#  示例 2: 
# 
#  
# 输入: s = "cccaaa"
# 输出: "cccaaa"
# 解释: 'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
# 注意"cacaca"是不正确的，因为相同的字母必须放在一起。
#  
# 
#  示例 3: 
# 
#  
# 输入: s = "Aabb"
# 输出: "bbAa"
# 解释: 此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
# 注意'A'和'a'被认为是两种不同的字符。
#  
# 
#  
# 
#  提示: 
# 
#  
#  1 <= s.length <= 5 * 10⁵ 
#  s 由大小写英文字母和数字组成 
#  
# 
#  Related Topics 哈希表 字符串 桶排序 计数 排序 堆（优先队列） 👍 550 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def frequencySort(self, s: str) -> str:
        count = defaultdict(int)
        for i in s:
            count[i] += 1   # 遍历字符串 s，统计每个字符的出现次数，也就是++count[i]
        lst = []    # 创建一个空列表，用于构建堆
        heapq.heapify(lst)  # 将列表 lst 转换为堆，用大顶堆法

        for i in count:
            for j in range(count[i]):
#j 的作用是确保每个字符 i 被推入堆中的次数等于它在字符串 s 中出现的次数
# 将lst中字符及负频率序号推入堆中，以实现大顶堆的效果，这样pop就是从大到小了
                heapq.heappush(lst,(i,-count[i]))
        return "".join([heapq.heappop(lst)[0] for _ in range(len(s))])
""" ''是字符形式，.join是输出，从堆中依次弹出字符，并按频率从高到低拼接成字符串
return时先进行循环，_是一个常用的占位符变量名，表示我们不需要在循环体中使用循环变量，相当于省下1个变量
heapq.heappop(lst)[0]：再在每次循环中，从堆 lst 中弹出一个元素，并获取该元素的第一个元素，即字符本身"""
# leetcode submit region end(Prohibit modification and deletion)