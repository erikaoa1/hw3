#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

#include <iostream>
#include <vector>
#include <cmath>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  // Destroy the Heap object
  ~Heap();

   //Push an item to the heap
  void push(const T& item);

   //Returns the top (priority) item
   //@throw std::underflow_error if the heap is empty
  T const & top() const;

   //Remove the top priority item
   //underflow_error if the heap is empty
  void pop();

   // Returns true if the heap is empty
  bool empty() const;

   // Returns size of the heap
  size_t size() const;



private:
  std::vector<T> heapVector;

  //sorts heaps from the bottom  to the top.
  void trickleUp(int childIndex);

  //sorts heap from the top to the bottom
  void trickleDown(int index);

  //swaps the array elements that exist in indexA and indexB
  void swap(int indexA, int indexB);

  int nodeMax; //ary-ness. how many child nodes possible AT MOST.
  PComparator comp;  //comparative object function passed in by user or using the default one

};


template <typename T, typename PComparator >
Heap<T, PComparator>::Heap(int m, PComparator c)
		: nodeMax(m), comp(c) {
}

template <typename T, typename PComparator >
Heap<T, PComparator>::~Heap() {   
  
}

template <typename T, typename PComparator >
void Heap<T, PComparator >::push(const T& item) {
  heapVector.push_back(item);
  trickleUp(heapVector.size()-1); //last index (item just added)
}

template <typename T, typename PComparator >
T const & Heap<T, PComparator >::top() const {
  if (heapVector.empty())
  {
    throw std::underflow_error("Can't get top, the heap is empty.");
  }
 return heapVector.front();
}

template <typename T, typename PComparator >
void Heap<T, PComparator >::pop() {

  if (heapVector.empty())
  {
    throw std::underflow_error("Can't pop, the heap is empty.");
  }
	if (heapVector.size() == 1){
		heapVector.pop_back();
    return;
  }
  heapVector.at(0) = heapVector.back();
  heapVector.pop_back();
  trickleDown(0);
}

template <typename T, typename PComparator >
bool Heap<T, PComparator >::empty() const {
  return heapVector.empty();
}


template <typename T, typename PComparator >
size_t Heap<T, PComparator >::size() const {
  return heapVector.size();
}


template <typename T, typename PComparator >
void Heap<T, PComparator >::trickleUp(int childIndex) {
  int parentIndex = (childIndex-1)/nodeMax;
  while ( (parentIndex >= 0) && (comp(heapVector[childIndex], heapVector[parentIndex]))  ){
    swap(childIndex, parentIndex);
      childIndex = parentIndex;
      parentIndex = (childIndex-1)/nodeMax;
  }
  }


template <typename T, typename PComparator >
void Heap<T, PComparator >::trickleDown(int index) {

  //vector to keep all the child indexes of the given index 
  std::vector<int> childrenIndex;
  childrenIndex.push_back(0); // this vector is root 1, so occupy index 0 with 0
  if(heapVector.size() == 1){ //no need to swap
    return;
  }
  
  while (1){
  //populates childrenIndex vector, starts at index 1
	std::vector<int> childrenIndex;
	childrenIndex.push_back(0);
  for (int i=1; i<=nodeMax; i++){
    if ( (unsigned)(nodeMax*index + i) < heapVector.size() ){ // the child exists
      childrenIndex.push_back( (nodeMax*index) + i );  //add this child's index to the vector, (starting at index 1)
      } 
  }
    
      T bestChild = heapVector.at(childrenIndex.at(1)); //first child is automatically best for now
      int bestChildIndex =childrenIndex.at(1);

    //swapping if there is only one child & that child is better.
    if (childrenIndex.size()==2){//only one child. remember this vector's 0 index is "empty"
      if ( comp(heapVector[childrenIndex.at(1)], heapVector[index]) ){ //if childIndex is < parent, swap
      swap(index, childrenIndex.at(1));  
        return; //we're done because heaps are full... if there is only one child there cant be another subtree
  }else { //it's only one child and that child is not better than parent. then everything is already sorted
        return;
  }
    }
    //finding best child if there is more than one child
    if (childrenIndex.size() >= 3){ //there are at least 2 children, maybe more.
      for (unsigned int i=2; i<childrenIndex.size(); i++){
        if (comp(heapVector.at(childrenIndex.at(i)), bestChild)){ //if this child is better than previous best
          bestChild = heapVector.at(childrenIndex.at(i)); //this child becomes the new best
          bestChildIndex = childrenIndex.at(i); //store new best index for when we swap with parent.
        }
      }

      if (comp(bestChild, heapVector.at(index))){ //bestChild is better than parent
        swap(bestChildIndex, index); //swap the bestChild and the parent
      }
    }
    index = bestChildIndex; //setting index = to new parent node so that we can sort the following subtree if there is one
    
    if ((unsigned)index > (heapVector.size()-2)/nodeMax ){ //if index is now a leaf node, return. no more swapping
    return;
  }
    continue; // if index is NOT a leaf node, skip to next iteration so that we can sort the next subtree
    
 } 
  } 

template <typename T, typename PComparator >
void Heap<T, PComparator >::swap(int indexA, int indexB) {
  T temp = heapVector[indexB];
  heapVector[indexB] = heapVector[indexA];
  heapVector[indexA] = temp;

}



#endif

