#include <bits/stdc++.h>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    int maxRaznHeght;
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
    }
    else if (key > root->key) {
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
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
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
        outFile << root->key<< endl;
        lefttrav(root->left, outFile);
        lefttrav(root->right, outFile);
    }
}

void makeH(Node* root) {
    if (root == NULL) {
        return;
    }
    makeH(root->left);
    makeH(root->right);
    if ((root->left == NULL) && (root->right == NULL)) {
        root->height = 0;
        root->maxRaznHeght = 0;
    }
    else if (root->left == NULL) {
        root->height = root->right->height + 1;
        root->maxRaznHeght = root->right->height + 1;
    }
    else if (root->right == NULL) {
        root->height = root->left->height + 1;
        root->maxRaznHeght = root->left->height + 1;
    }
    else {
        if (root->left->height == root->right->height) {
            root->height = root->left->height + 1;
            root->maxRaznHeght = 0;
        }
        else if (root->left->height > root->right->height) {
            root->height = root->left->height + 1;
            root->maxRaznHeght = root->left->height- root->right->height;
        }
        else {
            root->height = root->right->height + 1;
            root->maxRaznHeght = root->right->height - root->left->height;
        }
    }
}

void findMax(Node* root,long long& max) {
    if (root == NULL) {
        return;
    }
    if (root->maxRaznHeght > max) {
        max = root->maxRaznHeght;
    }
    findMax(root->left, max);
    findMax(root->right,max);
}

void createVect(Node* root, long long max, vector<int>& vect) {
    if (root) {
        createVect(root->left, max, vect);
        if (root->maxRaznHeght==max) {
            vect.push_back(root->key);
        }
        createVect(root->right, max, vect);
    }
}


int main() {
    ifstream fileToRead("in.txt");
    ofstream fileToWrite("out.txt");
    Node* root = nullptr;
    int key;
    while (fileToRead >> key) {
        root = insert(root, key);
    }
    long long max = 0;
    makeH(root);
    findMax(root, max);
    vector<int> qwe;
    createVect(root,max,qwe);
    if (qwe.size()%2==0) {
        lefttrav(root, fileToWrite);
    }
    else {
        root = deleteNode(root, qwe[qwe.size()/2]);
        lefttrav(root, fileToWrite);
    }
    return 0;
}
