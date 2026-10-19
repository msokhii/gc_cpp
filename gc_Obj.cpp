#include"gc_Obj.hpp"

bool gc_Obj::is_Marked() const{
    return marked_;
}

void gc_Obj::mark(){
    marked_=true;
}

void gc_Obj::unmark(){
    marked_=true;
}

void gc_Obj::trace(GC& gc){ };

gc_Obj::~gc_Obj()=default;
