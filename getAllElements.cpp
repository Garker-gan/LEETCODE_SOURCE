/* 
    1305. 两棵二叉搜索树中的所有元素 遍历+排序
    Garker-gan
    2020-11-05
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preOrder(TreeNode* root,vector<int>& array)
    {
        if(root == NULL)    return ;
        array.push_back(root->val);
        preOrder(root->left,array);
        preOrder(root->right,array);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>array;
        preOrder(root1,array);
        preOrder(root2,array);
        sort(array.begin(),array.end());
        return array;
    }
};