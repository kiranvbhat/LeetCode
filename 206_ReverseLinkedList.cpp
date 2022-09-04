// https://leetcode.com/problems/reverse-linked-list/

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
    // RECURSIVE SOLUTION
    ListNode* reverseListHelper(ListNode* head, ListNode *prev) {
        if (head == nullptr) return nullptr;    //prevent errors
        
        if (head->next == nullptr) {
            head->next = prev;
            return head;
        }
        ListNode* newHead = reverseListHelper(head->next, head);
        head->next = prev;
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverseListHelper(head, nullptr);
    }
    
// ------------------------------------------------------------------------------------------

    // ITERATIVE SOLUTION
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;    //prevent errors
        ListNode* prev = nullptr;
        while (head->next != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head->next = prev;
        return head;
    }

// ------------------------------------------------------------------------------------------
    
    // BEST RECURSIVE SOLUTION
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    } 
};
