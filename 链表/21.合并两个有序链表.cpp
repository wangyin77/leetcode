/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (62.48%)
 * Likes:    1056
 * Dislikes: 0
 * Total Accepted:    271.7K
 * Total Submissions: 434.9K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *p, *q,*ans;
        if(l1->val <= l2->val) p = l1, q = l2, ans = p;
        else p = l2, q = l1, ans = p;
        while(p->next){
            if(p->next->val <= q->val) p = p->next;
            else{                
                ListNode *t1 = p->next, *t2 = q->next;
                p->next = q, q->next = t1;
                p = q, q = t2;
            }
            if(!q) break;
        }
        if(q) p->next = q;     
        
        return ans;
    }
};
// @lc code=end

