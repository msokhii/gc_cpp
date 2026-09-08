#ifndef GC_OBJECT_HPP
#define GC_OBJECT_HPP

class GC;

class GCObject{
public:
    bool marked = false;
    virtual void trace(GC&){ };
    virtual ~GCObject() = default;
};

#endif
