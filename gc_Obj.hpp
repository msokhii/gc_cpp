#ifndef GC_OBJ_HPP
#define GC_OBJ_HPP

class gc_Obj{
    public:
        bool is_Marked() const;
        void mark();
        void unmark();
        virtual ~gc_Obj();
    private:
        bool marked_=false;
};

#endif
