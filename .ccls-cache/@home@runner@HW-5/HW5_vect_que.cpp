#include <iostream>
#include <vector>

using namespace std;

// For this homework, you are going to implement an extendable vector based queue that 
// uses "jump" trick to save space. 
// Finish function 
//              front() that prints the first element in the queue
//              deque() that dequeues the queue
//          	enque(val) that enqueues val to the queue
//              print_vect() that prints out vect_que.
// Demonstrate that your code works in main.
// Refer to class PPT if you forgot all the different cases. 

template <class T>
class vect_queue {
	std::vector<T> vect_que;
	size_t size_;
	int que_front_;
public:
	vect_queue(T val) {
		vect_que.push_back(val);
		size_ = 1;
		que_front_ = 0;
	}
	T front() const;
	void deque();
	void enque(T val);
	void print_vect() const;
};

// return value at front of queue
template<class T>
T vect_queue<T>::front() const {
  return vect_que.at(que_front_);
}

// move front of queue to next value, decrease size by one
template <class T>
void vect_queue<T>::deque() {
  que_front_ = (que_front_ + 1) % vect_que.size();
  size_--;
}

// add val to end of queue
template <class T>
void vect_queue<T>::enque(T val) {
  size_t i = (que_front_ + size_) % vect_que.size();
  vect_que[i] = val;
  size_++;
}

// print all values of queue in order
template <class T>
void vect_queue<T>::print_vect() const {
  for (auto i : vect_que) {
    cout << i << " ";
  }
  cout << endl;
}

int main()
{   
  //Demonstrate your code works by adding/removing values in a vect_que class 
  //object. Print out your result.
  //You should include front index of queue, back index of queue, and the entire
  //vector (not queue) for each case.
  
  //case 1: add to an empty queue
  vect_queue queue1;
  queue1.enque(1);
  queue1.print_vect();
    
  //case 2: add to a non-empty queue without jump 
    
  //case 3: add to a non-empty queue with a jump
    
  //case 4: remove from a queue with number of elements > 1 
  //        and que.front not at vect.back

  //case 5: remove from a queue with number of elements > 1 
  //        and que.front at vect.back
    
  //case 6: remove from a queue with 1 element in it and que.front 
  //        not at vect[0]
    
    
  cout<<"\nprogram ends here.\n";

  return 0;
}