SET(min MinMaxHeap.cpp MinMaxHeap.hpp)
SET(max MaxMinHeap.cpp MaxMinHeap.hpp)
SET(heap Heap.cpp Heap.hpp)
add_executable(Lab08Test test.cpp ${heap} ${min} ${max})
