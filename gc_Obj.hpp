#ifndef GC_OBJ_HPP
#define GC_OBJ_HPP

class GC;

class gc_Obj{
    public:
        bool is_Marked() const;
        void mark();
        void unmark();
        virtual void trace(GC& gc);
        virtual ~gc_Obj();
    private:
        bool marked_=false;
};

#endif
