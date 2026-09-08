#ifndef GC_OBJECT_HPP
#define GC_OBJECT_HPP

class GCObject{
public:
    bool marked = false;
    virtual ~GCObject() = default;
};

#endif
