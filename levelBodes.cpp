#include <bits/stdc++.h>
using namespace std;
int mx_level=0;
 int x;
class Node
{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;

    }
};
Node *input()
{
    int val;
    cin>>val;
    Node* root;
    if(val==-1) root=NULL;
    else root=new Node(val);
    queue<Node*>q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node* pr=q.front();
        q.pop();
        int l,r;
        cin>>l>>r;
        Node* myLeft;
        Node* myRight;
        if(l==-1) myLeft=NULL;
        else myLeft=new Node(l);
        if(r==-1) myRight=NULL;
        else myRight=new Node(r);
         pr->left=myLeft;
         pr->right=myRight;
        if(pr->left) q.push(pr->left);
        if(pr->right) q.push(pr->right);
    }
    return root;
}
void make_pair(Node* root,vector<int>&v){
 queue<pair<Node*,int>>q;
   if(root) q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int>pr=q.front();

        Node* node=pr.first;
        int level=pr.second;
         q.pop();
         if(node->left)
        {
            q.push({node->left,level+1});
            mx_level=max(mx_level,level+1);
            if(level+1==x) v.push_back(node->left->val);
        }
        if(node->right)
        {
            q.push({node->right,level+1});
            mx_level=max(mx_level,level+1);
             if(level+1==x) v.push_back(node->right->val);
        }
    }
}
int main()
{
    Node* root=input();
    vector<int>v;
    cin>>x;
    make_pair(root,v);
    if(x>mx_level) cout<<"Invalid"<<endl;
    else{
       if(x==0) cout<<root->val<<endl;
       else
       {
        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
       }
    }
}