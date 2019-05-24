# sort-cpp
C++ Realizations of Sorting Algorithms

# Algorithms
* Bubble Sort - simplest sorting algo, just replacing of nearby elements, O(n^2)
* Selection Sort - build sorted array starts from first element to last by replacing smallest element with current i-th element after comparison, O(n^2)
* Insertion Sort - build sorted array by inserting every element of input array started from (l + 1) via comparison and replacing nearby elements, O(n^2)
* ShellSort - improved insertion sort via usage of range of comparison, O(n^2) but can be better depend on 'step' value
* TreeSort - based on BST, just insert all sorting array into std::multiset<T> (based on BSTs), and for_each it, O(n logn).
* Merge Sort - split input array on elementary parts and merge them into output sorted array by per-element comparison via recurse, O(n logn)
* QuickSort - compare elements depend on pivot (median value in current case) and replace them if needed via recurse, O(n logn)

# Usage example
Ready usage example in main.cpp
