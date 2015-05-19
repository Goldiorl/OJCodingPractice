#include<iostream>
using namespace std;
#include<vector>
#include<stk>


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode * cur=root;
        vector<int> result;
        stack<TreeNode*> stk;
        while(!stk.empty() ||cur!=nullptr){
            if(cur->left!=nullptr){
                stk.push(cur);
                cur=cur->left;
                
            }else{
                if(!stk.empty()){
                    result.push_back(stk.top()->val);
                    cur=stk.top()->right;
                    stk.pop();
                }else {
                    cur=cur->right;
                }
                    
                
            }
        }
   
        return result;
    }
};

int main(){
	Solution sol=Solution();
	TreeNode * root=new TreeNode(1);
	vector<int> result;
	result=sol.inorderTraversal(root);
	cout<<result.size()<<endl;
}
	