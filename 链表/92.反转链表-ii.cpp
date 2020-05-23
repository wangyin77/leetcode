/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (50.02%)
 * Likes:    368
 * Dislikes: 0
 * Total Accepted:    50.6K
 * Total Submissions: 101.3K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *first = dummy;
        for(int i = 0; i < m - 1; i++) first = first->next;
        ListNode *l = first->next, *j = first->next->next, *t;
        for(int i = m; i < n; i++){
            t = j->next;
            j->next = l;
            l = j, j = t;
        }        
        first->next->next = j;
        first->next = l;

        return dummy->next;
    }
};
// @lc code=end

