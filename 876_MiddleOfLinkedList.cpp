// https://leetcode.com/problems/middle-of-the-linked-list/

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
    // solution 1: find length, then iterate over half of length
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            length++;
            cur = cur->next;
        }
        for (int i = 0; i < (length / 2); i++) {
            head = head->next;
        }
        return head;
    }
    
// ------------------------------------------------------------------------------------------
    
    // solution 2: slow and fast pointers
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            head = head->next;
        }
        return head;
    }

};
