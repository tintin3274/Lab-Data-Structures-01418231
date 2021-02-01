#include <iostream>
using namespace std;

typedef struct node{
    string key;
    int size;
    struct node* parent;
    struct node* leftChild;
    struct node* rightSibling;
}File;

File* createRoot(string key, int size){
    // Allocate memory for new node
    File* node = new File;
    // Assign key to this node
    node->key = key;
    node->size = size;
    // Initialize parent
    node->parent = NULL;
    // Initialize left child, and right sibling as NULL
    node->leftChild = NULL;
    node->rightSibling = NULL;
    return(node);
}

File* createNode(string key, int size, File* parent){
    // Allocate memory for new node
    File* node = new File;
    // Assign key to this node
    node->key = key;
    node->size = size;
    // Initialize parent
    node->parent = parent;
    // Initialize left child, and right sibling as NULL
    node->leftChild = NULL;
    node->rightSibling = NULL;
    // Set this node as a child to its parent
    if(node->parent != NULL) {
        if(node->parent->leftChild != NULL) {
            File* child = node->parent->leftChild;
            while(child->rightSibling != NULL) {
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

File* getParent(File* node){
    return node->parent;
}

File* getChild(File* node, int k){
    File* child = node->leftChild;
    for(int i=1; i<k; i++) {
        child = child->rightSibling;
    }
    return child;
}

void isRoot(File* node){
    if(node->parent == NULL)
        printf("Yes\n");
    else
        printf("No\n");
}

void isExternal(File* node){
    if(node->leftChild == NULL)
        printf("Yes\n");
    else
        printf("No\n");
}

int depth(File* node)
{
    int depth = 0;
    while(node->parent != NULL) {
        node = node->parent;
        depth++;
    }
    return depth;
}

void postorder(File* node, File* nodeO, int* c){
    if(node == NULL){
        return;
    }
    postorder(node->leftChild,nodeO, c);
    if(node == nodeO){
        return;
    }
    *c += node->size;
    postorder(node->rightSibling,nodeO, c);
    //*c += node->size;
}

int sizefolder(File* node){
    int c = 0;
    int* cPtr = &c;
    postorder(node, node, cPtr);
    return node->size+c;
}

void preorder(File* node, File* nodeO, int d, string p){
    if(node == NULL){
        return;
    }
    if(node == nodeO->rightSibling){
        return;
    }
    if(node->leftChild != NULL){
        cout << "[Folder Size: " << node->size << " || Folder and File include Size: "<< sizefolder(node) << "]\n   " << p+node->key << endl << endl;
    }
    else{
        cout << "[File Size: " << node->size << "]\n    " << p+node->key <<  endl << endl;
    }
    preorder(node->leftChild, nodeO, d+1, p+node->key);
    preorder(node->rightSibling, nodeO, d, p);
}


int main()
{
    File* root = createRoot("/user/rt/courses/", 1000);

        File* f1 = createNode("cs016/", 2000, root);

            File* f1_f1 = createNode("grades", 8000, f1);

            File* f1_f2 = createNode("homeworks/", 1000, f1);
                File* f1_f2_f1 = createNode("hw1", 3000, f1_f2);
                File* f1_f2_f2 = createNode("hw2", 2000, f1_f2);
                File* f1_f2_f3 = createNode("hw3", 4000, f1_f2);

            File* f1_f3 = createNode("programs/", 1000, f1);
                File* f1_f3_f1 = createNode("pr1", 57000, f1_f3);
                File* f1_f3_f2 = createNode("pr2", 97000, f1_f3);
                File* f1_f3_f3 = createNode("pr3", 74000, f1_f3);

        File* f2 = createNode("cs252/", 1000, root);

            File* f2_f1 = createNode("projects/", 1000, f2);

                File* f2_f1_f1 = createNode("papers/", 1000, f2_f1);
                    File* f2_f1_f1_f1 = createNode("buynow", 26000, f2_f1_f1);
                    File* f2_f1_f1_f2 = createNode("sellhigh", 55000, f2_f1_f1);

                File* f2_f1_f2 = createNode("demos/", 1000, f2_f1);
                    File* f2_f1_f2_f1 = createNode("market", 4786000, f2_f1_f2);

            File* f2_f2 = createNode("grades", 3000, f2);
    
    preorder(root, root, 0, "");
}