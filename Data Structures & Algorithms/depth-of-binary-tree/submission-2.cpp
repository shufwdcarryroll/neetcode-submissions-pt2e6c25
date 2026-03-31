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
        if(root == nullptr) return 0;
        TreeNode* leftpr = root->left;
        TreeNode* rightpr = root->right;

        int leftH = 1 + maxDepth(leftpr);
        int rightH = 1 + maxDepth(rightpr);

        return max(leftH,rightH);


    }
};
