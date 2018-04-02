SET(min MinMaxHeap.cpp MinMaxHeap.hpp)
SET(max MaxMinHeap.cpp MaxMinHeap.hpp)
add_executable(Lab08Test test.cpp ${min} ${max})
