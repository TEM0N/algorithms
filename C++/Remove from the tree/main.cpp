#include <bits/stdtr1c++.h>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* newNode = new Node();
    if (newNode) {
        newNode->key = key;
        newNode->left = newNode->right = nullptr;
    }
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* findMinNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMinNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void lefttrav(Node* root, ofstream& outFile) {
    if (root) {
        outFile << root->key << endl;
        lefttrav(root->left, outFile);
        lefttrav(root->right, outFile);
    }
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");
    int keyToDelete;
    inFile >> keyToDelete;
    Node* root = nullptr;
    int key;
    while (inFile >> key) {
        root = insert(root, key);
    }
    root = deleteNode(root, keyToDelete);
    lefttrav(root, outFile);
    inFile.close();
    outFile.close();
    return 0;
}
