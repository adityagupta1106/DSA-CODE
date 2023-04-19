#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void value(TreeNode<int> *root,vector<int>&ans)
{
    if(root==NULL)
    return;
    value(root->left,ans);
    ans.push_back(root->data);
    value(root->right,ans);
}
TreeNode<int> *inordertoBst(vector<int> &ans,int s,int e)
{
    if(s>e)
    return NULL;
    int mid=(s+e)/2;
    TreeNode<int> *root=new TreeNode<int>(ans[mid]);
    root->left=inordertoBst(ans,s,mid-1);
    root->right=inordertoBst(ans,mid+1,e);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int>ans;
    vector<int>ans1;
    value(root1,ans);
    value(root2,ans1);
    vector<int>ans2;
    int i=0,j=0;
    while(i<ans.size() && j<ans1.size())
    {
        if(ans[i]>=ans1[j])
        ans2.push_back(ans1[j++]);
        else
        ans2.push_back(ans[i++]);

    }
    while(i<ans.size())
    ans2.push_back(ans[i++]);
    while(j<ans1.size())
    ans2.push_back(ans1[j++]);
    int s=0,e=ans2.size()-1;
    return inordertoBst(ans2,s,e);

}
