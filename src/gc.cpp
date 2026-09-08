#include "gc.hpp"

void GC::mark(){
    for(GCObject* root: roots){ mark_object(root); }
}

void GC::sweep(){
    auto it = objects.begin();

    while(it != objects.end()){
        GCObject* object = *it;

        if(!object->marked){
            delete object;
            it = objects.erase(it);
        } else {
            object->marked=false;
            ++it;
        }
    }
}

void GC::mark_object(GCObject* object){
    if(object == nullptr){ return; }
    if(object->marked){ return; }
    object->marked=true;
    object->trace(*this);
}

GC::~GC(){
    for(GCObject* object: objects){ delete object; }
}
