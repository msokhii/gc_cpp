#include"node.hpp"

Node::Node(char name_) :
    node_Name_(name_) { };

void Node::set_Left_Node(Node* node){
    left_=node;
}

void Node::set_Right_Node(Node* node){
    right_=node;
}

Node::~Node(){
    this->left_=nullptr;
    this->right_=nullptr;
}
