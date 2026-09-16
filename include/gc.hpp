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
        total_Collect++;
    }

    void mark_object(GCObject* object);

    std::size_t get_Collect(){
        return total_Collect;
    }

    std::size_t get_Obj_Collect(){
        return obj_Collect;
    }

    ~GC();
private:
    std::vector<GCObject*> objects;
    std::vector<GCObject*> roots;
    void mark();
    void sweep();
    std::size_t total_Collect=0;
    std::size_t obj_Collect=0;
};

#endif
