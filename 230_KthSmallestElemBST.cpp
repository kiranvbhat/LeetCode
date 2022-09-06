// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // In-order traversal, returns kth element of the traversal (i.e. the kth smallest)
    int kthSmallestHelper(TreeNode* root, int k, int& cur) {
        int ans = -1;
        if (root != nullptr) {
            ans = max(ans, kthSmallestHelper(root->left, k, cur));
            cur++;
            if (cur == k) {
                return root->val;
            }
            ans = max(ans, kthSmallestHelper(root->right, k, cur));
        }
        return ans;
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        int cur = 0;
        return kthSmallestHelper(root, k, cur);        
    }
};
