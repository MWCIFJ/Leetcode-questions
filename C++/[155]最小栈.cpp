//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。 
//
// 实现 MinStack 类: 
//
// 
// MinStack() 初始化堆栈对象。 
// void push(int val) 将元素val推入堆栈。 
// void pop() 删除堆栈顶部的元素。 
// int top() 获取堆栈顶部的元素。 
// int getMin() 获取堆栈中的最小元素。 
// 
//
// 
//
// 示例 1: 
//
// 
//输入：
//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]
//
//输出：
//[null,null,null,null,-3,null,0,-2]
//
//解释：
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 -2.
// 
//
// 
//
// 提示： 
//
// 
// -2³¹ <= val <= 2³¹ - 1 
// pop、top 和 getMin 操作总是在 非空栈 上调用 
// push, pop, top, and getMin最多被调用 3 * 10⁴ 次 
// 
//
// Related Topics 栈 设计 👍 1860 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
#include <memory> // 包含智能指针等内存管理工具
using namespace std; // 使用标准命名空间
//#define INT_MAX 2147483647

class MinStack {
  struct ListNode{
    int val;
    ListNode *prev;
    ListNode *next;
    int min;
  };

public:
    ListNode *peak;
    ListNode *base;
    MinStack() {
       base = (ListNode *)malloc(sizeof(ListNode));
       base->next = NULL;
       base->min = INT_MAX;
       peak = base;
    }

    void prev_push(ListNode *tail,int val) {
     ListNode *curr = (ListNode *)malloc(sizeof(ListNode));
     curr->prev = tail;
     tail->next = curr;
     curr->val = val;
     curr->next = NULL;
    }

    void push(int val) {
        prev_push(peak,val);
        val = min(val,peak->min);
        peak = peak->next;
        peak->min = val;
    }
    
    void pop() {
        if(peak == base)
          return;
        peak = peak->prev;
        peak->next = NULL;
        free(peak->next);

    }
    
    int top() {
        if(peak == base)
            return INT_MAX;
        return peak->val;
    }
    
    int getMin() {
        if(peak == base)
            return INT_MAX;
        return peak->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//leetcode submit region end(Prohibit modification and deletion)

// 定义最小栈类
class MinStack {
    // 定义链表节点结构体
    struct ListNode {
        ListNode *next; // 指向下一个节点的指针
        ListNode *prev; // 指向上一个节点的指针
        int val;        // 节点存储的值
        int min;        // 当前节点及其之前节点的最小值
    };

public:
    /** 初始化数据结构 */
    ListNode *base; // 指向栈底的指针
    ListNode *peek; // 指向栈顶的指针

    // 构造函数，初始化栈
    MinStack() {
        base = (ListNode *) malloc(sizeof(ListNode)); // 分配内存创建栈底节点
        base -> min = INT_MAX; // 初始化栈底节点的最小值为 INT_MAX
        base -> next = NULL;   // 栈底节点的下一个节点为空
        peek = base;           // 栈顶指针初始指向栈底
    }

    // 向栈中压入元素
    void push(int val) {
        v_push(peek, val); // 调用辅助函数将元素压入栈
        val = min(val, peek -> min); // 更新当前最小值
        peek = peek -> next; // 移动栈顶指针到新节点
        peek -> min = val;   // 设置新节点的最小值
    }

    // 辅助函数：将元素压入栈
    void v_push(ListNode *tail, int val) {
        ListNode *curr = (ListNode *) malloc(sizeof(ListNode)); // 分配内存创建新节点
        curr -> val = val; // 设置新节点的值
        curr -> next = NULL; // 新节点的下一个节点为空
        curr -> prev = tail; // 新节点的上一个节点为当前栈顶
        tail -> next = curr; // 当前栈顶的下一个节点为新节点
    }

    // 弹出栈顶元素
    void pop() {
        if(peek == base) return; // 如果栈为空，直接返回
        peek = peek -> prev; // 移动栈顶指针到上一个节点
        v_pop(peek); // 调用辅助函数释放栈顶节点
    }

    // 辅助函数：释放栈顶节点
    void v_pop(ListNode *tail) {
        free(tail -> next); // 释放栈顶节点的内存
        tail -> next = NULL; // 将上一个节点的下一个指针置为空
    }

    // 获取栈顶元素
    int top() {
        if(base == peek) return INT_MAX; // 如果栈为空，返回 INT_MAX
        return peek -> val; // 返回栈顶节点的值
    }

    // 获取栈中的最小值
    int getMin() {
        if(base == peek) return INT_MAX; // 如果栈为空，返回 INT_MAX
        return peek -> min; // 返回栈顶节点的最小值
    }
};