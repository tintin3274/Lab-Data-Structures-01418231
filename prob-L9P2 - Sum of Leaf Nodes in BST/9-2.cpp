#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

typedef struct node{
    int key;
    struct node* parent;
    struct node* left;
    struct node* right;
}Node;

Node* createRoot(int key){
    // Allocate memory for new node
    Node* node = new Node;
    // Assign key to this node
    node->key = key;
    // Initialize parent
    node->parent = NULL;
    // Initialize left child, and right child as NULL
    node->left = NULL;
    node->right = NULL;
    return node;
}

void addNode(int key, Node* root){
    Node *y = NULL;
    Node *x = root; 
    while (x != NULL)
    {
        y = x;
        if (key <= x->key) x = x->left;
        else x = x->right;
    }

    // Allocate memory for new node
    Node* node = new Node;
    // Assign key to this node
    node->key = key;
    // Initialize parent
    node->parent = y;
    // Initialize left child, and right child as NULL
    node->left = NULL;
    node->right = NULL;
    if(node->parent != NULL) {
        if(key <= node->parent->key) node->parent->left = node;
        else node->parent->right = node;
    }

}

void sumLeaf(Node* node, int *sumPtr){
    if(node == NULL) return;
    if(node->left == NULL && node->right == NULL){
        *sumPtr += node->key;
        return;
    }
    sumLeaf(node->left, sumPtr);
    sumLeaf(node->right, sumPtr);
}

int main(){
    int i, n, j;
    int sum = 0;
    cin >> n;
    Node* root = createRoot(n);
    cin >> n;
    for(i=0; i<n; i++){
        cin >> j;
        addNode(j, root);
    }
    sumLeaf(root, &sum);
    cout << sum;
}

