/*
 * @Description: 构建二叉树
 * @Author: YuanJiang
 * @Date: 2024-07-22 16:11:06
 */
#include <iostream>
#include <vector>
using namespace std;

//定义二叉树节点
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

TreeNode* buildBinaryTree(const vector<int>& nums){
    vector<TreeNode*> vectorTreeNode(nums.size(), nullptr);
    TreeNode* root = nullptr;
    for(int i = 0; i < nums.size(); i++){
        TreeNode* node = nullptr;
        if(nums[i] != -1){
            node = new TreeNode(nums[i]);
        }
        vectorTreeNode[i] = node;
    }
   
    root = vectorTreeNode[0];
    for(int i = 0; 2*i + 2 < vectorTreeNode.size(); i++){
        if(vectorTreeNode[i] != nullptr){
            vectorTreeNode[i]->left = vectorTreeNode[2*i + 1];
            vectorTreeNode[i]->right = vectorTreeNode[2*i + 2];
        }
    }

    return root;

}
// 遍历二叉树
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        traversal(root, res);
        return res;
    }
private:
    void traversal(TreeNode* root, vector<int>& res){
        if(root == nullptr) return;
        res.push_back(root->val);
        traversal(root->left, res);
        traversal(root->right, res);
    }
};
int main(int argc, char* argv[]){
    vector<int> nums;
    int num;
    while(cin >> num){
        nums.push_back(num);
    }
    // 构建二叉树
    TreeNode* root = buildBinaryTree(nums);
    // 遍历二叉树
    Solution s;
    vector<int> res = s.preorderTraversal(root);
    // 打印二叉树
    for(auto item: res){
        cout << item << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
