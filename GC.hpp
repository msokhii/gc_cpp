#ifndef GC_HPP
#define GC_HPP

#include"gc_Obj.hpp"

#include<vector>

class GC{
    public:
        GC()=default;
        void track(gc_Obj* obj_);
        void add_Root(gc_Obj* obj_);
        void remove_Root(gc_Obj* obj_);
        void mark(gc_Obj* obj_);
        void sweep();
        ~GC();
    private:
        std::vector<gc_Obj*> objects_;
        std::vector<gc_Obj*> roots_;
};

#endif
