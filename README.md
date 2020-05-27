# leetcode
## 专题清单
- [ ] 贪心
- [ ] 模拟
- [ ] 指针
- [ ] 二分
- [ ] 排序
- [ ] 搜索
- [ ] DP
- [ ] 分治
- [ ] 数学
- [ ] 位运算
- [ ] STL
- [ ] 字符串
- [x] 链表
- [ ] 树
- [ ] 图
- [ ] 并查集

## 笔记
1. 贪心
2. 模拟
3. 指针
4. 二分
5. 排序
6. 搜索
7. DP
8. 分治
9. 数学
10. 位运算
11. STL
12. 字符串
13. 链表
    - Leetcode中单链表的定义
    ```c++
    Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ```
    - 创建虚拟头节点`dummy`
    ```c++
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    return dummy->next;
    ```
    - 反转节点,经常用到
    ```c++
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *next;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ```
    - 各种特殊技巧
        1. 快慢指针判环，第二次相交为入口
        2. 链表插入排序要注意结尾
        3. 相交链表两个指针遍历一圈
        4. 判断是否到结尾的另一种写法
        ```c++
        node->next = l1? l1: l2;
        ```
14. 树
15. 图
16. 并查集