//给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。 
//
// 构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 
//指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。 
//
// 例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random 
//--> y 。 
//
// 返回复制链表的头节点。 
//
// 用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示： 
//
// 
// val：一个表示 Node.val 的整数。 
// random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为 null 。 
// 
//
// 你的代码 只 接受原链表的头节点 head 作为传入参数。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [[1,1],[2,1]]
//输出：[[1,1],[2,1]]
// 
//
// 示例 3： 
//
// 
//
// 
//输入：head = [[3,null],[3,0],[3,null]]
//输出：[[3,null],[3,0],[3,null]]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 1000
// 
// -10⁴ <= Node.val <= 10⁴ 
// Node.random 为 null 或指向链表中的节点。 
// 
//
// 
//
// Related Topics 哈希表 链表 👍 1504 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head)
            return NULL; // 如果原链表头节点为空，返回空

        // 使用next将整个链表构建起来

        struct Node *head1 = (struct Node *) malloc(sizeof(struct Node)); // 申请新链表的头节点
        head1->val = head->val; // 复制值
        head1->next = NULL; // 初始化next为NULL
        head1->random = NULL; // 初始化random为NULL

        struct Node *h = head, *h1 = head1; // h指向原链表头，h1指向新链表头
        /* 处理普通链表 */
        while (h->next) { // 复制next指针
            h = h->next; // 移动到原链表的下一个节点
            struct Node *temp = (struct Node *) malloc(sizeof(struct Node)); // 申请新节点
            temp->val = h->val; // 复制值
            temp->next = NULL; // 初始化next为NULL
            temp->random = NULL; // 初始化random为NULL
            h1->next = temp; // 将新节点链接到新链表
            h1 = h1->next; // 移动到新链表的下一个节点
        }

        /* 处理随机指针 */

        h = head;
        h1 = head1; // 重置h和h1指向头节点

        while (h) { // 处理random指针
            int cnt = 0;
            struct Node *cur = head, *cur1 = head1;//两个探测用链表

            if (h->random) { // 如果原节点的random不为空
                while (cur && cur != h->random) { // 找到指向random的，在原链表中的位置
                    cnt++;
                    cur = cur->next;
                }
                while (cnt) { // 在新链表中找到对应位置的节点
                    cnt--;
                    cur1 = cur1->next;
                }
                h1->random = cur1; // 设置新节点的random指针
            } else
                h1->random = NULL; // 如果原节点的random为空，新节点的random也为空

            h = h->next; // 移动到原链表的下一个节点
            h1 = h1->next; // 移动到新链表的下一个节点
        }

        return head1; // 返回新链表的头节点
    }
};
//leetcode submit region end(Prohibit modification and deletion)
