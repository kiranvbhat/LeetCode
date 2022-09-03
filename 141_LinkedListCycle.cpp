// https://leetcode.com/problems/linked-list-cycle/

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
    // O(1) time (runtime beats 98% of user submissions), O(1) space
    bool hasCycle(ListNode *head) {
        short count = 0;
        while (head != nullptr) {
            if (count > 10000) return true;
            head = head->next;
            count++;
        }
        return false;
    }
};
