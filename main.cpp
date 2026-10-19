#include"gc_Obj.hpp"
#include"node.hpp"
#include"GC.hpp"

#include<iostream>

int main(){
    GC gc;

    Node* A=new Node('A');
    Node* B=new Node('B');
    Node* C=new Node('C');

    A->set_Left_Node(B);
    A->set_Right_Node(C);

    gc.track(A);
    gc.track(B);
    gc.track(C);

    gc.add_Root(A);

    gc.mark(A);
    gc.sweep();
    
    return 0;
}
