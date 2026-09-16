#ifndef GC_ROOT_HPP
#define GC_ROOT_HPP

#include "gc.hpp"

class GCRoot{
public:
    GCRoot(GC& gc, GCObject *obj) : gc(gc),obj(obj)
    {
        gc.add_root(obj);
    }

    ~GCRoot(){ gc.remove_root(obj); }

private:
GC& gc;
GCObject* obj;

};


#endif
