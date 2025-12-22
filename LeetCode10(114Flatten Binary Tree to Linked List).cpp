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

    void pil_stack(TreeNode*root , std::vector<TreeNode*>& pil){
        if(!root){
            return;
        }
        pil.push_back(root);
        pil_stack(root->left, pil);
        pil_stack(root->right,pil);

    }

    void flatten(TreeNode* root) {
          std::vector<TreeNode*> pil;
        pil_stack(root ,pil );
        while (!pil.empty())
        {
            TreeNode* fr = pil.front();
            pil.erase(pil.begin());
            if (pil.empty())
            {
                fr->right = nullptr;
                break;
            }
            fr->right = pil.front();
            fr->left = nullptr;


        }

    }
};
