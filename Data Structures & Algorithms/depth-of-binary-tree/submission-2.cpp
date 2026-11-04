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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return findMaxDepth(root, 1);
    }

    int findMaxDepth(TreeNode* node, int max){
        int depth1 = 0;
        int depth2 = 0;
        if(node->left != nullptr) {
            depth1 = findMaxDepth(node->left, max+1);
        }
        if(node->right != nullptr){
            depth2 = findMaxDepth(node->right, max+1);
        }
        if (depth1 > max) max = depth1;
        if (depth2 > max) max = depth2;
        return max;
    }
};