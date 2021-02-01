#include <iostream>
using namespace std;

typedef struct node{
    int key;
    struct node* parent;
    struct node* leftChild;
    struct node* rightSibling;
}Node;

Node* createRoot(int key){
    // Allocate memory for new node
    Node* node = new Node;
    // Assign key to this node
    node->key = key;
    // Initialize parent
    node->parent = NULL;
    // Initialize left child, and right sibling as NULL
    node->leftChild = NULL;
    node->rightSibling = NULL;
    return node;
}

Node* createNode(int key, Node* parent){
    // Allocate memory for new node
    Node* node = new Node;
    // Assign key to this node
    node->key = key;
    // Initialize parent
    node->parent = parent;
    // Initialize left child, and right sibling as NULL
    node->leftChild = NULL;
    node->rightSibling = NULL;
    if(node->parent != NULL) {
        if(node->parent->leftChild != NULL) {
            Node* child = node->parent->leftChild;
            while(child->rightSibling != NULL){
                child = child->rightSibling;
            }
            child->rightSibling = node;
        }
        else {
            node->parent->leftChild = node;
        }
    }
    return node;
}

void postorder(Node* node){
    if(node == NULL) return;

    postorder(node->leftChild);
    cout << node->key << " ";
    postorder(node->rightSibling);
}

void preorder(Node* node){
    if(node == NULL) return;

    cout << node->key << " ";
    preorder(node->leftChild);
    preorder(node->rightSibling);
}


void addRelation(Node* node, int k1, int k2){
    if(node == NULL) return;

    if(node->key == k1) createNode(k2, node);

    addRelation(node->leftChild, k1, k2);
    addRelation(node->rightSibling, k1, k2);
}

int main(){
    
    int i, n, n1, n2;
    cin >> n >> n1;
    Node* root = createRoot(n1);
    for(i=0; i<n; i++){
        cin >> n1 >> n2;
        addRelation(root, n1, n2);
    }
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

}