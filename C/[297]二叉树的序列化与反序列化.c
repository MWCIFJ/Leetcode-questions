//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方
//式重构得到原数据。 
//
// 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串
//反序列化为原始的树结构。 
//
// 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的
//方法解决这个问题。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,3,null,null,4,5]
//输出：[1,2,3,null,null,4,5]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 示例 4： 
//
// 
//输入：root = [1,2]
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 树中结点数在范围 [0, 10⁴] 内 
// -1000 <= Node.val <= 1000 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 设计 字符串 二叉树 👍 1269 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */

//BFS模拟传统层序遍历进行反序列化，即序列化使用层序遍历将二叉树的节点按顺序转换为字符串，
//反序列化先将字符串的值先转换为节点值，再将节点值按层序遍历的顺序反向生成二叉树
#define queue_size 50000
#define data_size 80000    //这个如果根据示例不同调整大小的话会节省空间

//序列化函数，该函数时将二叉树转换为字符串，具体方法是层序遍历，利用队列先入先入先出的特点，
//将每一层的节点放入队列中，先将当前节点值拼接到字符中，再将数组中队列的下一层的左右子节点支
//放入队列中，不断轮询直到所有节点均写入字符中返回
char* serialize(struct TreeNode* root){
    char* data=(char*)malloc(data_size*sizeof(char)); // 分配内存以存储序列化后的字符串
    data[0]='\0';   // 初始化字符串，方便后续使用strcat
    if(root==NULL)
        return data; // 如果根节点为空，直接返回空字符串

    int head=0; // 队列头指针
    int tail=0; // 队列尾指针
    struct TreeNode* queue[queue_size]; // 定义队列，用于层序遍历
    queue[tail++]=root; // 根节点入队
    char temp[10]; // 临时字符串，用于存储节点值的字符串表示
    int flag=0; // 用来标记是否是第一个字符，避免在字符串开头添加逗号

    while(head!=tail){ // 当队列不为空时，进行层序遍历
        // 队首节点非空
        if(queue[head]!=NULL){
            // 除了第一个位置不需要补','外，其余字符之间需要补上','，将','写入到结果字符串
            if(flag==1)
                strcat(data,",");
            flag=1; // 标记已经处理过至少一个节点
            sprintf(temp,"%d",queue[head]->val); // 将节点值转换为字符串
            strcat(data,temp); // 将节点值字符串拼接到结果字符串
            // 当前节点的左右子节点入队
            queue[tail++]=queue[head]->left;
            queue[tail++]=queue[head]->right;
        }
        // 队首节点为空
        else{
            // 'null'字符输出到data
            strcat(data,",");
            strcat(data,"null"); // 用"null"表示空节点
        }
        // 队列头部指针后移
        head++;
    }

    return data; // 返回序列化后的字符串
}

/** Decodes your encoded data to tree. */
//反序列化函数，该函数时将字符串转换为二叉树，首先从字符串中提取所有节点值，再使用层序遍历，
//根据队列的情况，反向生成二叉树，思路是根据序列化函数判断，
//队列中的值是根据当前层序从左到右，不同层序从上到下的顺序放置，
//就将头指针定义为根节点，尾指针后移寻找左右子节点，根据头尾指针的情况，从上到下生成新的二叉树
struct TreeNode* deserialize(char* data) {
    if(data[0]=='\0'){ // 检查输入字符串是否为空
        return NULL; // 如果为空，返回NULL
    }

    //将字符串读入数组
    int nums[queue_size]={0}; // 定义一个数组来存储节点值，初始化为0
    int nums_pos=0; // 从第1位开始写，转换成树的时候比较方便
    int data_pos=0; // 字符串当前位置
    char temp[10]; // 临时字符串，用于存储单个节点值的字符串表示
    int temp_pos=0; // 临时字符串的当前位置
    while(data[data_pos]!='\0'){ // 遍历整个输入字符串
        temp_pos=0;
        //当遇到','时直接跳过
        if(data[data_pos]==','){
            data_pos++;
        }
        //将节点值从字符串中提取出来，放入中间字符串中用于转换数字
        while(data[data_pos]!=','&&data[data_pos]!='\0'){
            temp[temp_pos]=data[data_pos]; // 将当前字符复制到临时字符串
            temp_pos++;
            data_pos++;
        }
        temp[temp_pos]='\0'; // 结束临时字符串
        //如果为空节点
        if(strcmp("null",temp)==0){ // 检查是否为"null"，表示空节点
            nums[nums_pos]=INT_MIN; // 使用INT_MIN表示空节点
            nums_pos++;
        }
        //如果节点非空
        else{
            //sscanf()函数作用时提取字符串中数据
            sscanf(temp,"%d",&nums[nums_pos]); // 将字符串转换为整数并存储在数组中
            nums_pos++;
        }
    }


    //将数组输出成树
    struct TreeNode* queue[queue_size]; // 存储节点地址的队列
    //先生成根节点，以便返回结果
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode)); // 分配内存给根节点
    root->val=nums[0]; // 设置根节点的值
    root->left=NULL; // 初始化左子节点为NULL
    root->right=NULL; // 初始化右子节点为NULL
    queue[0]=root; // 将根节点地址放入队列
    int head=0; // 队列首指针
    int tail=1; // 队列尾指针
    int pos=1; // nums数组的位置指针
    struct TreeNode* ret=root; // 用于返回的根节点指针

    //模拟树的层序遍历进行反向建树
    while(head!=tail){ // 当队列不为空时
        //如果节点不为空，从nums数组中读取两个元素
        if(queue[head]!=NULL){
            //左孩子
            struct TreeNode* left_child;
            //左孩子非空
            if(nums[pos]!=INT_MIN){ // 检查左孩子是否为空
                left_child=(struct TreeNode*)malloc(sizeof(struct TreeNode)); // 分配内存给左孩子
                left_child->val=nums[pos]; // 设置左孩子的值
            }
            //左孩子为空
            else{
                left_child=NULL; // 左孩子为空
            }
            queue[head]->left=left_child; // 设置当前节点的左孩子
            queue[tail++]=left_child; // 将左孩子地址放入队列
            pos++;

            //右孩子
            struct TreeNode* right_child;
            //右孩子非空
            if(nums[pos]!=INT_MIN){ // 检查右孩子是否为空
                right_child=(struct TreeNode*)malloc(sizeof(struct TreeNode)); // 分配内存给右孩子
                right_child->val=nums[pos]; // 设置右孩子的值
            }
            //右孩子为空
            else{
                right_child=NULL; // 右孩子为空
            }
            queue[head]->right=right_child; // 设置当前节点的右孩子
            queue[tail++]=right_child; // 将右孩子地址放入队列
            pos++;
        }
        //空不空都弹出队列首节点
        head++; // 移动队列首指针
    }

    return ret; // 返回构建好的二叉树的根节点
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
//leetcode submit region end(Prohibit modification and deletion)