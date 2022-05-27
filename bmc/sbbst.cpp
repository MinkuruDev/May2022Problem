#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

struct SelfBalacingBST
{
    Node *root;

    SelfBalacingBST()
    {
        root = NULL;
    }

    void insert(int data)
    {
        root = insert(root, data);
    }

    Node *insert(Node *root, int data)
    {
        if(root == NULL)
        {
            root = new Node(data);
            return root;
        }
        if(data < root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
        return root;
    }
        
    void balance(Node *root)
    {
        if(root == NULL)
            return;
        balance(root->left);
        balance(root->right);
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh - rh) > 1)
        {
            if(lh > rh)
            {
                if(root->left->left != NULL)
                    root = rightRotate(root);
                else
                    root = leftRightRotate(root);
            }
            else
            {
                if(root->right->right != NULL)
                    root = leftRotate(root);
                else
                    root = rightLeftRotate(root);
            }
        }
    }

    int height(Node *root)
    {
        if(root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    Node *rightRotate(Node *root)
    {
        Node *temp = root->left;
        root->left = temp->right;
        temp->right = root;
        return temp;
    }

    Node *leftRotate(Node *root)
    {
        Node *temp = root->right;
        root->right = temp->left;
        temp->left = root;
        return temp;
    }

    Node *leftRightRotate(Node *root)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    Node *rightLeftRotate(Node *root)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    void inorder(Node *root)
    {
        if(root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

};