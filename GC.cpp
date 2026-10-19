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

void GC::mark(gc_Obj* obj_){
    if(obj_==nullptr){
        return;
    }
    if(obj_->is_Marked()==true){
        return;
    }
    obj_->mark();
    obj_->trace(*this);
}

void GC::sweep(){
    auto itr=objects_.begin();
    while(itr!=objects_.end()){
        gc_Obj* obj_=*itr;
        if(!obj_->is_Marked()){
            delete obj_;
            itr=objects_.erase(itr);
        }
        else{
            obj_->unmark();
            itr++;
        }
   }
}

GC::~GC(){
    for(gc_Obj* obj:objects_){
            delete obj;
    }
}
