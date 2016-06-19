# heap
heap implemetations

heap.cpp


     Array implementation of min-heap
     Calculations:

        parent(i)  =  (i-1)/2                           where i is the index of a child (either left or right)

        child(i)   =    left : 2*i+1 , right : 2*i+2    where i is the index of parent


heapsort.cpp

          Sorting int elements
          optimal sorting time attained O(n log n)
          min-heap is used (root have less key value than its both children)
          first elements are min-heaped then deletion process is done until heap exhaust
