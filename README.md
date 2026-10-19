# Mark & Sweep Garbage Collector (CPP)

This repository contains a basic implementation of the mark and sweep 
algorithm coded in CPP-20. We have a garbage collector that manages 
dynamically allocated objects. It tracks these objects through its 
respective roots and reclaims memory occupied by unreachable objects.

# Implementation and Working: 

Imagine, you have some garbage objects, say a bunch of Nodes (A,B and C). Suppose, A is the root and the left and right childern of A are B and C respectively. The garbage collector works in two phases. 

### Mark Phase:

The GC starts from the root (A) and then recursively traces the nodes usingDepth-First Search (DFS). Each reachable object is marked as True and previously marked objects are skipped to prevent infinite recursion. 

### Swap Phase: 

The GC then checks which objects are not marked and deletes them reclaimingmemory. It then sets the flags of all objects back to false for the next marking phase. 

# Build & Run:

Requires a C++20 compatible compiler (For ex: GCC).
From the directory containing the source files, execute the following in the terminal:

```bash
g++ -std=c++20 -O3 gc_Obj.cpp node.cpp GC.cpp main.cpp -o gc_Test ./gc_Test```
