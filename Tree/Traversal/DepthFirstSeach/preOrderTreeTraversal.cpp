#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = nullptr;  // FIXED
        this->right = nullptr; // FIXED
    }
};

void preorder(Node* root){
    if(root == nullptr) return;
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    preorder(root);

   
// Time Complexity	O(N)	

// Space Complexity O(N) 
                    
    return 0;
}