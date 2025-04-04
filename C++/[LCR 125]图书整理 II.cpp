//读者来到图书馆排队借还书，图书管理员使用两个书车来完成整理借还书的任务。书车中的书从下往上叠加存放，图书管理员每次只能拿取书车顶部的书。排队的读者会有两种操
//作： 
//
// 
// push(bookID)：把借阅的书籍还到图书馆。 
// pop()：从图书馆中借出书籍。 
// 
//
// 为了保持图书的顺序，图书管理员每次取出供读者借阅的书籍是 最早 归还到图书馆的书籍。你需要返回 每次读者借出书的值 。 
//
// 如果没有归还的书可以取出，返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//输入：
//["BookQueue", "push", "push", "pop"]
//[[], [1], [2], []]
//输出：[null,null,null,1]
//解释：
//MyQueue myQueue = new MyQueue();
//myQueue.push(1); // queue is: [1]
//myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//myQueue.pop(); // return 1, queue is [2] 
//
// 
//
// 提示： 
//
// 
// 1 <= bookID <= 10000 
// 最多会对 push、pop 进行 10000 次调用 
// 
//
// 
//
// Related Topics 栈 设计 队列 👍 801 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class CQueue {
public:
  stack<int> a,b;
  int res,tmp;
    CQueue() {}
    
    void appendTail(int value) {    //追加尾部
        a.push(value);
    }
    
    int deleteHead() {
        int res; // 用于存储删除的元素
        int tmp; // 用于临时存储栈顶元素

        if (b.size()) { // 如果栈 b 不为空
            res = b.top(); // 获取栈 b 的栈顶元素
            b.pop(); // 删除栈 b 的栈顶元素
            return res; // 返回删除的元素
        } else { // 如果栈 b 为空
            if (a.empty()) { // 如果栈 a 也为空
                return -1; // 返回 -1，表示没有元素可删除
            } else { // 如果栈 a 不为空
                while (a.size()) { // 将栈 a 的所有元素转移到栈 b
                    tmp = a.top(); // 获取栈 a 的栈顶元素
                    b.push(tmp); // 将元素压入栈 b
                    a.pop(); // 删除栈 a 的栈顶元素
                }
                res = b.top(); // 获取栈 b 的栈顶元素
                b.pop(); // 删除栈 b 的栈顶元素
                return res; // 返回删除的元素
            }
        }
    }
};


/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 */
//leetcode submit region end(Prohibit modification and deletion)

