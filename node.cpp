#include"node.hpp"
#include"GC.hpp"

Node::Node(char name_) :
    node_Name_(name_) { };

void Node::set_Left_Node(Node* node){
    left_=node;
}

void Node::set_Right_Node(Node* node){
    right_=node;
}

void Node::trace(GC& gc){
    gc.mark(left_);
    gc.mark(right_);
}

Node::~Node(){
    this->left_=nullptr;
    this->right_=nullptr;
}
