#include "gc.hpp"

void GC::mark(){
    for(GCObject* root: roots){ root->marked = true; }
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

GC::~GC(){
    for(GCObject* object: objects){ delete object; }
}
