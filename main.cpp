#include "gc.hpp"

#include<iostream>
#include<string>

class Person : public GCObject{
public:
    Person(std::string name,int age) : name(name), age(age)
    {
        std::cout<<"Constructed "<<name<<'\n';
    }
    ~Person(){ std::cout<<"Destroyed "<<name<<'\n'; }

private:
    std::string name;
    int age;
};

int main(){
    GC gc;
    Person* name1 = new Person("name1", 25);
    Person* name2 = new Person("name2", 30);
    Person* name3 = new Person("name3", 35);
    
    gc.track(name1);
    gc.track(name2);
    gc.track(name3);

    gc.add_root(name1);

    std::cout<<"Before collections: "<<gc.object_count()<<" objects."<<'\n';

    gc.collect();

    std::cout<<"After collections: "<<gc.object_count()<<" objects."<<'\n';
    gc.remove_root(name1);
    std::cout<<gc.object_count()<<" "<<gc.root_count()<<'\n';
    gc.collect();
    std::cout<<gc.object_count()<<" "<<gc.root_count()<<'\n';
    return 0;
}
