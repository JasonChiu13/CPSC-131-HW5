#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// For this homework, you are going to implement an extendable vector based queue that 
// uses "jump" trick to save space. 
// Finish function 
//              front() that prints the first element in the queue
//              deque() that dequeues the queue
//          	  enque(val) that enqueues val to the queue
//              print_vect() that prints out vect_que.
// Demonstrate that your code works in main.
// Refer to class PPT if you forgot all the different cases. 

template <class T>
class vect_queue {
	vector<T> vect_que;
	size_t size_;
	int que_front_;
private:
void Resize() {
  size_t new_size = vect_que.size() * 2;
  vector<T> new_vect(new_size);
  for (size_t i = 0; i < size_; ++i) {
    size_t j = (que_front_ + i) % vect_que.size();
    new_vect[i] = vect_que[j];
  }
  vect_que.swap(new_vect);
  que_front_ = 0;
}
public:
  vect_queue() {
    size_ = 0;
		que_front_ = 0;
  }
	vect_queue(T val) {
		vect_que.push_back(val);
		size_ = 1;
		que_front_ = 0;
	}
	T front() const {
    return vect_que.at(que_front_);
  }
	void deque() {
    que_front_ = (que_front_ + 1) % vect_que.size();
    size_--;
    if (vect_que.size() >= (3 * size_)) {
      Resize();
    }
  }
	void enque(T val) {
    if ((size_ + 1) > vect_que.size()) {
      Resize();
    }
    size_t i = (que_front_ + size_) % vect_que.size();
    vect_que[i] = val;
    size_++;
  }
	void print_vect() const {
    for (auto i : vect_que) {
      cout << vect_que[i] << endl;
    }
    cout << endl;
  }
};


int main()
{   
  //Demonstrate your code works by adding/removing values in a vect_que class 
  //object. Print out your result.
  //You should include front index of queue, back index of queue, and the entire
  //vector (not queue) for each case.
  
  //case 1: add to an empty queue
  vect_queue<int> queue1;
  queue1.enque(1);
  //queue1.print_vect();
    
  //case 2: add to a non-empty queue without jump
  queue1.enque(2);
  queue1.print_vect();
    
  //case 3: add to a non-empty queue with a jump
  vect_queue<int> queue2;
  queue2.enque(1);
  queue2.enque(2);
  queue2.deque();
  queue2.enque(3);
  queue2.print_vect();
    
  //case 4: remove from a queue with number of elements > 1 
  //        and que.front not at vect.back
  vect_queue<int> queue3;
  queue3.enque(1);
  queue3.enque(2);
  queue3.enque(3);
  queue3.deque();
  queue3.deque();
  queue3.print_vect();

  //case 5: remove from a queue with number of elements > 1 
  //        and que.front at vect.back
  vect_queue<int> queue4;
  queue4.enque(1);
  queue4.deque();
  queue4.print_vect();
    
  //case 6: remove from a queue with 1 element in it and que.front 
  //        not at vect[0]
  vect_queue<int> queue5;
  queue5.enque(1);
  queue5.enque(2);
  queue5.enque(3);
  queue5.deque();
  queue5.enque(4);
  queue5.deque();
  queue5.deque();
  queue5.deque();
  queue5.print_vect();
    
  cout<<"\nprogram ends here.\n";

  return 0;
}