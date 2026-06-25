# 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。 
# 
#  
# 
#  示例 1: 
# 
#  
# 输入: nums = [1,1,1,2,2,3], k = 2
# 输出: [1,2]
#  
# 
#  示例 2: 
# 
#  
# 输入: nums = [1], k = 1
# 输出: [1] 
# 
#  
# 
#  提示： 
# 
#  
#  1 <= nums.length <= 10⁵ 
#  k 的取值范围是 [1, 数组中不相同的元素的个数] 
#  题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的 
#  
# 
#  
# 
#  进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。 
# 
#  Related Topics 数组 哈希表 分治 桶排序 计数 快速选择 排序 堆（优先队列） 👍 2021 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = Counter(nums)  # 直接库函数，使用Counter高效统计元素出现次数，统计词频（O(n)时间）
        buckets = dict()  # buckets[i] 存储出现次数为i的元素列表，创建桶结构（O(n)空间）

        for num, count in counts.items():  # 填充桶结构   （O(n)时间）
            if count in buckets:
                buckets[count].append(num)  # 已有该次数，追加元素
            else:
                buckets[count] = [num]  # 新建次数桶

        top_k = []
        for count in range(len(nums), 0, -1):  # 倒序遍历桶（O(n)时间），从最大可能次数（数组长度）开始向下查找
            if count in buckets:  # 批量添加高频元素
                top_k.extend(buckets[count])  # 等效于 += 操作
                if len(top_k) >= k:  # 找到答案时
                    return top_k[:k]  # 返回前k个（处理可能有重复次数的情况）

        # 异常处理（理论上不会执行）
        # 当k=0或输入非法时需要补充边界处理
        return top_k[:k]
# leetcode submit region end(Prohibit modification and deletion)

