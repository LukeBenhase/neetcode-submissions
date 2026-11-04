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
    int goodNodes(TreeNode* root) {
        int goodNodes = 0;
        dfs(root, -101, goodNodes);
        return goodNodes;
    }
    void dfs(TreeNode* node, int largestNode, int& goodNodes){
        if (node->val >= largestNode) {
            largestNode = node->val;
            goodNodes++;
        }
        if(node->left) dfs(node->left, largestNode, goodNodes);
        if(node->right) dfs(node->right, largestNode, goodNodes);

    }
};
