#include "Set.h"
#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;

Set::Set(){

    size = 0;
    root = NULL;
}

Set::~Set(){
    deleteNode(root);
}

void Set::deleteNode(Set::Node* & node){

    if(node != NULL){
        deleteNode(node->left);
        deleteNode(node->right);
        delete node;
    }

}

Set::Set(Set & listObject){
    
    copyNode(listObject.root);
    
}

void Set::copyNode(Node* & node){
    if (node != NULL) {
        add(node->data);
        copyNode(node->left);
        copyNode(node->right);
    }
    
}

void Set::display (ostream & out) 
{
    displayNode(root, out);
}

void Set::displayNode(Node* & node, ostream & out){
   
    if(node != NULL){
        displayNode(node->left, out);
        cout << node->data << endl;
        displayNode(node->right, out);
    }
}

int Set::getSize() const {
    
    return size;
}


bool Set::empty() const {
    
    return(size == 0);
}

bool Set::find(const ItemType & item){   // WRITE !!

    return binSearch(root, item);
}

bool Set::binSearch(Node* & rootTree, const ItemType & item){

    if(rootTree == NULL){
        return false;
    }
    else if(rootTree->data == item){
        return true;
    }
    else if(rootTree->data < item){
        return binSearch(rootTree->right, item);
    }
    else {
       return binSearch(rootTree->left, item);
    }
    return false;
    
}

int Set::height(){
    
    return findHeight(root);
    
}

int Set::findHeight(Node* & node){

    if(node == NULL)
        return 0;
    
    return max(findHeight(node->left), findHeight(node->right)) + 1;

}

bool Set::add(const ItemType & item){

    if(find(item)){
        return false;
    }
    else if(root == NULL){
        Node *newNode = new Node;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = item;
        root = newNode;
        size++;
        return true;
    }
    else{
        addNode(item, root);
        size++;
        return true;
    
    }

}


void Set::addNode(const ItemType & item, Node* & node){


    if(item > node->data && node->right  == NULL){
        Node *newNode = new Node;
        newNode->data = item;
        node->right = newNode;
        newNode->left = NULL;
        newNode->right = NULL;
        
    }
    else if(item < node->data && node->left == NULL){
        
        Node *newNode = new Node;
        newNode->data = item;
        node->left = newNode;
        newNode->left = NULL;
        newNode->right = NULL;
        
    }
    else if (item > node->data && node->right != NULL){
        addNode(item, node->right);
    }
    else{
        addNode(item, node->left);
    }
}

bool Set::remove(const ItemType & item){

    return deleteHelper(root, item);
}


Set::Node* Set::findMinimumNode(Node* & node){

    while(node->left != NULL){
        node = node->left;
    }

    return node;

}

// For Academic Honesty, Source Note;
// Only Delete Helper funtion was inspired by this link. " https://gist.github.com/mycodeschool/9465a188248b624afdbf "
// github remove code is working with returning Node, I convert it to be returning bool, it is my delete helper function.


bool Set::deleteHelper(Node* & node, const ItemType & item){


    if(node == NULL){
        return false;
    }
    else if(item < node->data){
        deleteHelper(node->left, item);
    }
    else if(item > node->data){
        deleteHelper(node->right, item);
    }
    else{
    
        // Case 1, if there is no child.
        if(node->left == NULL && node->right == NULL){
        
            delete node;
            node = NULL;
            size--;
            return true;
        }
        // Case 2, if there is one child in right
        else if(node->left == NULL){
            Node *temporay = node;
            node = node->right;
            delete temporay;
            size--;
            return true;
        }
        // case 3, if there is one child in left
        else if(node->right == NULL){
            Node *temporary = node;
            node = node->left;
            delete temporary;
            size--;
            return true;
        }
        // case 4 if node has two child.
        else{
        
            Node *temp = findMinimumNode(node->right);
            node->data = temp->data;
            deleteHelper(node->right, temp->data);
            
        
        
        }
        
    
    }
    return false;
}









