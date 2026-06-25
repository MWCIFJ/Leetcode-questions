# 给你一个链表数组，每个链表都已经按升序排列。 
# 
#  请你将所有链表合并到一个升序链表中，返回合并后的链表。 
# 
#  
# 
#  示例 1： 
# 
#  输入：lists = [[1,4,5],[1,3,4],[2,6]]
# 输出：[1,1,2,3,4,4,5,6]
# 解释：链表数组如下：
# [
#   1->4->5,
#   1->3->4,
#   2->6
# ]
# 将它们合并到一个有序链表中得到。
# 1->1->2->3->4->4->5->6
#  
# 
#  示例 2： 
# 
#  输入：lists = []
# 输出：[]
#  
# 
#  示例 3： 
# 
#  输入：lists = [[]]
# 输出：[]
#  
# 
#  
# 
#  提示： 
# 
#  
#  k == lists.length 
#  0 <= k <= 10^4 
#  0 <= lists[i].length <= 500 
#  -10^4 <= lists[i][j] <= 10^4 
#  lists[i] 按 升序 排列 
#  lists[i].length 的总和不超过 10^4 
#  
# 
#  Related Topics 链表 分治 堆（优先队列） 归并排序 👍 3033 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        pq = []  # 初始化一个优先队列（最小堆），用于存储链表节点及其索引
        for idx, l in enumerate(lists):  # 遍历所有链表，idx 是链表在 lists 中的索引，l 是链表的头节点
            if l is not None:  # 如果当前链表的头节点不是 None
                # 这里我们用链表索引 idx 来间接引用链表中的节点，因为 ListNode 对象本身不可哈希，不能直接放入堆中。
                pq.append((l.val, idx))  # 将所有链表的(节点值, 链表索引)的元组添加到堆中。
        heapq.heapify(pq)  # 将列表 pq 转换为一个最小堆。堆顶元素将是 val 最小的那个元组。

        # 使用哑节点可以简化头节点的处理逻辑。不用考虑删除的是不是头节点的情况
        dummy = ListNode()  # 创建一个哑节点（dummy node），它的 next 指针将指向合并后的链表的头节点。
        cur = dummy  # 创建一个指针 cur，初始指向 dummy，用于在构建新链表时进行移动。

        # 当堆不为空时，循环处理
        while len(pq) > 0:
            # 从堆顶弹出 val 最小的元素。_ 表示我们暂时不关心这个元素的数值，l_idx 是链表在 lists 中的索引。
            _, l_idx = heapq.heappop(pq)
            cur.next = lists[l_idx]  # 将当前链表（lists[l_idx]）的最小节点（即它的头节点）连接到新链表的当前末尾。
            cur = cur.next  # 将 cur 指针移动到新链表的末尾（即刚刚连接的节点）。
            if cur.next is not None:  # 检查刚刚连接的节点后面是否还有节点。
                lists[l_idx] = lists[l_idx].next  # 如果有，将该链表的头节点更新为其下一个节点。
                heapq.heappush(pq, (cur.next.val, l_idx))  # 将新头节点的值和链表索引 (cur.next.val, l_idx) 再次推入堆中，以便在后续的循环中考虑这个新节点。
        return dummy.next  # dummy.next 指向合并后的链表的头节点
# leetcode submit region end(Prohibit modification and deletion)

