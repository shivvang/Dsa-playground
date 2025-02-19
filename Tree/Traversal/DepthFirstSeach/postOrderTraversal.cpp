#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = nullptr;  
        this->right = nullptr; 
    }
};

void postOrder(Node* root){
    if(root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << endl;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    postOrder(root);

    // Time Complexity	O(N)	

    // Space Complexity O(N) 
    
    return 0;
}