#include<iostream>
using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int data;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* root, int val) {
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data) {
        root->left = insertNode(root->left, val);
    }
    else if(val > root->data) {
        root->right = insertNode(root->right, val);
    }
    return root;
}

void min(Node* root) {
    Node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    cout << "Minimum data value is :" << temp->data << endl;
}

void mirror(Node* root) {
    if(root == NULL) {
        return;
    }
    else {
        Node* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    mirror(root->left);
    mirror(root->right);
}

void inorder(Node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->data << " | ";
        inorder(root->right);
    }
}

void search(Node* root, int value) {
    if (root->data == value) {
        cout << "Search is successful for value :" << value;
    }
    else if (value < root->data) {
        search(root->left, value);
    }
    else if(value > root->data) {
        search(root->right, value);
    }
    else {
        cout << "Search is not successful for value :" << value;
    }
}

int findLongestPath(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = findLongestPath(root->left);
    int rightDepth = findLongestPath(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int main() {
    int ch, val, dd, rootv;
    cout << "Insert root node of the tree :";
    cin >> rootv;
    Node* root = insertNode(NULL, rootv);
    cout << "1)Insert nodes into the tree :";
    while(true) {
        cout << "\nEnter the data to insert :(-1 to exit) :";
        cin >> val;
        if(val == -1) {
            break;
        }
        else {
            insertNode(root, val);
            cout << val << " is inserted";
        }
    }
    cout << endl << "\n2)Find number of nodes in longest path from root\n3)Minimum data value found in the tree\n4)Change a tree so that the roles of the left and right pointers are swapped at every node";
    cout << "Enter your choice :";
    cin >> ch;
    switch(ch) {
        case 2:
            cout << "Number of Nodes is longest path are :";
            cout << findLongestPath(root);
            break;
        case 3:
            min(root);
            break;
        case 4:
            cout << "\nInorder tree is :";
            inorder(root);
            cout << "\nMirror tree is :";
            mirror(root);
            inorder(root);
            cout << "\nThe roles of the left and right pointers are swapped at every node(mirror)\n";
            break;
        case 5:
            cout << "\nEnter the data to search :";
            cin >> dd;
            search(root, dd);
            break;
    }
    return 0;
}
