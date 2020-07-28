cmake_minimum_required(VERSION 3.16)
project(DSKhademiGraph)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSKhademiGraph main.cpp entity/Person/person.h entity/Person/person.cpp entity/Relation/relation.cpp entity/Relation/relation.h utils/Stack/stack.cpp utils/Stack/stack.h entity/Graph/graph.cpp entity/Graph/graph.h entity/Graph/BFS/BFS.cpp entity/Graph/BFS/BFS.h)