#ifndef NODE_HPP
#define NODE_HPP

#include"gc_Obj.hpp"
#include"GC.hpp"

class Node:public gc_Obj{
    public:
        Node()=default;
        Node(char name_);
        void set_Left_Node(Node* node);
        void set_Right_Node(Node* node);
        void trace(GC& gc) override;
        ~Node();
    private:
        char node_Name_='A';
        Node* left_=nullptr;
        Node* right_=nullptr;
};

#endif
