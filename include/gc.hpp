#ifndef GC_CLASS_HPP
#define GC_CLASS_HPP

#include "gc_object.hpp"
#include<vector>
#include<cstddef>
#include<algorithm>

class GC{
public:
    void track(GCObject* object){
        if(object == nullptr){ return; }
        objects.push_back(object);
    }

    std::size_t object_count() const{
        return objects.size();
    }

    void add_root(GCObject* object){
        if(object == nullptr){ return; }
        if(std::find(roots.begin(), roots.end(), object) == roots.end()){
            roots.push_back(object);
        }
    }

    void remove_root(GCObject* object){
        if(object == nullptr){ return; }

        auto it = std::find(roots.begin(), roots.end(), object);

        if(it != roots.end()){ roots.erase(it); }
    }

    std::size_t root_count() const{
        return roots.size();
    }

    void collect(){
        mark();
        sweep();
    }

    ~GC();
private:
    std::vector<GCObject*> objects;
    std::vector<GCObject*> roots;
    void mark();
    void sweep();
};

#endif
