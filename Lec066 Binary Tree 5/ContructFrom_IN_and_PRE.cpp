//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    vector<int>vis;
    int findPosition( int in[], int element, int n){
        for(int i=0; i<n; i++){
            if( in[i] == element ){
                if(vis[i] == 0){
                    vis[i] = 1;
                    return i;
                }
            }
        }
        return -1;
    }
    Node* solve ( int in[], int pre[], int &preindex, int inOrderstart, int inOrderend, int n ){
        if( preindex >= n || inOrderstart > inOrderend ){
            return NULL;
        }
        int element = pre[preindex++];
        Node* root = new Node( element );
        int position = findPosition( in, element, n);
        root->left = solve( in, pre, preindex, inOrderstart, position -1, n);
        root->right = solve( in, pre, preindex, position +1 , inOrderend , n );
        return root;
    }
    Node* buildTree(int in[],int pre[], int n){
        int preindex = 0;
        vis.resize(n,0);
        Node* ans = solve(in, pre, preindex, 0, n-1, n);
        return ans;
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends