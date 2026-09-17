#include "gc.hpp"
#include "gc_root.hpp"

#include<iostream>
#include<string>

class Person : public GCObject{
public:
    Person(std::string name,int age) : name(name), age(age)
    {
        std::cout<<"Constructed "<<name<<'\n';
    }
    ~Person(){ std::cout<<"Destroyed "<<name<<'\n'; }

private:
    std::string name;
    int age;
};

class Node : public GCObject{
public:
    Node(std::string name) : name(name), next(nullptr)
    {
        std::cout<<"Constructed Node -> "<<name<<'\n';
    }

    void trace(GC& gc) override{
        gc.mark_object(next);
    }

    ~Node(){ std::cout<<"Destroyed Node -> "<<name<<'\n'; }

    void set_next(Node* node){ next = node; }

private:
    std::string name;
    Node* next;
};

int main(){
    GC gc;

    Node* a = new Node("A");
    Node* b = new Node("B");
    Node* c = new Node("C");
    //Node* d = new Node("D");

    gc.track(a);
    gc.track(b);
    gc.track(c);
    //gc.track(d);
    
    a->set_next(b);
    b->set_next(c);
    
    GCRoot root(gc,a);

    std::cout<<"Total objects managed by GC: "<<gc.object_count()<<'\n';
    std::cout<<gc.get_Collect()<<'\n';
    std::cout<<"Total objects collected: "<<gc.get_Obj_Collect()<<'\n';

    gc.maybe_collect();

    std::cout<<"Total objects managed by GC: "<<gc.object_count()<<'\n';
    std::cout<<gc.get_Collect()<<'\n';
    std::cout<<"Total objects collected: "<<gc.get_Obj_Collect()<<'\n';
    std::cout<<gc.get_Threshold()<<'\n';

    return 0;
}
