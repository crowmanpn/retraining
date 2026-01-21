
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    return isEqual(root->left,root->right);
    
    }
    bool isEqual(TreeNode* leftRoot, TreeNode* RightRoot) {
        if (leftRoot==nullptr&&RightRoot==nullptr) return true;
        if (leftRoot == nullptr || RightRoot == nullptr) return false;

        return (leftRoot->val == RightRoot->val) && isEqual(leftRoot->left, RightRoot->right) && isEqual(leftRoot->right, RightRoot->left);
   }
  
};



int  main() {


    return 0;
}