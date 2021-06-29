
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int ret = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // int ret = 0;
        leftsum(root);
        return ret;
    }

    int leftsum(TreeNode* root)
    {
        if(!root)return 0;
        ret+=leftsum(root->left);
        cout<<ret<<",";
        leftsum(root->right);
        return root->val; 
    }
};

int main()
{
    TreeNode* root = new TreeNode(1,new TreeNode(2,new TreeNode(4), new TreeNode(5)),new TreeNode(3,nullptr,nullptr));

    Solution slo;
    int ret = slo.sumOfLeftLeaves(root);
    cout<<"ret is:"<<ret;

}