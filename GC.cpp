#include"GC.hpp"
#include"gc_Obj.hpp"
#include<algorithm>

void GC::track(gc_Obj* obj_){
    objects_.push_back(obj_);
}

void GC::add_Root(gc_Obj* obj_){
    roots_.push_back(obj_);
}

void GC::remove_Root(gc_Obj* obj_){
    auto itr=std::find(roots_.begin(),roots_.end(),obj_);
    if(itr!=roots_.end()){
        std::erase(roots_,*itr);
    }
}

GC::~GC(){
    for(gc_Obj* obj:objects_){
            delete obj;
    }
}
