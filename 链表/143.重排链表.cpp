/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (55.95%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    25K
 * Total Submissions: 44.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        int n = 0;
        for(ListNode *i = head; i ; i = i->next) ++n;
        if(n == 1) return;
        ListNode *mid = head, *p, *q;
        for(int i = 0; i < (n + 1) / 2 - 1; i++) mid = mid->next;
        p = mid->next, q= mid->next->next;
        mid->next = NULL, p->next = NULL; 
        while(q){
            ListNode *t = q->next;
            q->next = p;
            p = q, q = t;
        }
        q = head;
        while(p){
            ListNode *t1 = q->next, *t2 = p->next;
            q->next = p, p->next =t1;
            q = t1, p = t2;   
        }
        return;
    }
};
// @lc code=end

