/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (69.05%)
 * Likes:    967
 * Dislikes: 0
 * Total Accepted:    240.1K
 * Total Submissions: 347.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
    ListNode* reverseList(ListNode* head) {
        // 迭代
        if(!head || !head->next) return head;
        ListNode *i = head, *j = head->next;
        while(j){
            ListNode *t = j->next;
            j->next = i;
            i = j, j = t;
        }
        head->next = NULL;
        return i; 

       /* 递归
        if(!head || !head->next) return head;
        ListNode *end = reverseList(head->next);
        head->next->next = head; //令下个节点指向自己
        head->next = NULL;//自己的下个节点清空
        return end; */
    }
};
// @lc code=end

