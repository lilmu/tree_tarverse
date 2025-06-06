#ifndef QUEUE_H_
#define QUEUE_H_

#include <cmath>
#include <iostream>
#include <iomanip>
#include <ostream>
#include "Node.h"
using namespace std;

extern int DefaultQSize;
extern int debug;
extern int debug_queue;

template<class T> class Queue{
public:
	Queue() { top = NULL; };
	// Queue(Queue&);
	Queue(const Queue&);
	~Queue();
	void QueueFull();
	void QueueEmpty();
	bool IsFull();
	void Push(const T& item); //insert from the rear
	bool IsEmpty();
	T * Delete(T&);   // delete the first node
	T* Pop(T&);       // pop the first node
	T Pop();
	T pop();
	T Top();
	T front();
	Queue<T>& operator = (const Queue<T>& rhs) { // copy assignment
		this->qlist = rhs.qlist;
		return *this;
	};
friend	ostream & operator<< <>(ostream &, const Queue <T> &);
public:
	List<T> qlist;		
	Node<T>* top;
	int qnum = 0;
};

/*
template <class T>
Queue <T>::Queue(Queue& rhs) {
	front = rhs.front; rear = rhs.rear;
	MaxSize = rhs.MaxSize;
	top = rhs.top;
	queue = new T[MaxSize]; 
	for (int i = 0; i < top; i++) queue[i] = rhs.queue[i];
}
*/
// copy constructor 
template <class T>
Queue <T>::Queue(const Queue& rhs) {
	this->qlist = rhs.qlist;   // copy assignment for list
};

template <class T>
Queue <T>::~Queue() {
	if(debug && debug_queue) cout << "\ndelete Queue->";
};

template<class T>
bool Queue <T>::IsFull() {
	return 0;  // linked list will not full
};

template<class T>
bool Queue<T>::IsEmpty() {
	return (this->qlist.num == 0) ? true : false;
};

// remove front element from the queue
template<class T>
T* Queue <T>::Delete(T& x) {
	if (IsEmpty()) { QueueEmpty(); return NULL; }
	else {
		Node <T>* t = qlist.Pop();
		x = t->data;
		delete (t);
		qnum--;
		return &x;
	}
};

template<class T>
T* Queue <T>::Pop(T& x) {
	if (IsEmpty()) { QueueEmpty(); return NULL; }
	else {
		Node <T>* t = qlist.Pop();
		x = t->data;
		delete (t);
		qnum--;
		return &x;
	}
};

template<class T>
T Queue <T>::front() {
	if (IsEmpty()) { QueueEmpty(); return NULL; }
	else
		return qlist.first->data;
};

template<class T>
T Queue <T>::Top() {
	if (IsEmpty()) { QueueEmpty(); return NULL; }
	else
		return qlist.first->data;
};

template<class T>
T Queue <T>::pop() {
	if (IsEmpty()) { QueueEmpty(); return NULL; }
	else {
		T x;
		Node<T>* t = qlist.Pop();
		x = t->data;
		if (debug && debug_queue) cout << "\nrecycle node (" << x << ")->";
		delete (t);
		qnum--;
		return x;
	}
};

template<class T>
T Queue <T>::Pop() {
	if (IsEmpty()) { QueueEmpty(); return NULL; }
	else {
		T x;
		Node<T>* t = qlist.Pop();
		x = t->data;
		if (debug && debug_queue) cout << "\nrecycle node (" << x << ")->";
		delete (t);
		qnum--;
		return x;
	}
};


template <class T>
void Queue <T>::Push(const T &x) { // Push x to the queue 
	if (debug && debug_queue) cout << "\nnew queue node ("<<x<<")->";
	this->qlist.InsertBack(x);
	top = this->qlist.first;
}

template <class T>
void Queue <T>::QueueFull() { 
	if(debug && debug_queue) 
		cout << "Queue is full\n";
}

template <class T>
void Queue <T>::QueueEmpty() {
	if (debug && debug_queue)
	cout << "Queue is empty\n";
}

template <class T>
ostream& operator<<(ostream &s,const Queue <T> &q) {
               s<<"\n The contents in the Queue are:\n";
			   Node<T>* t = q.qlist.first; int i = 0;
			   while (t) { s << "(" << ++i << ") " << *t << setw(4) << " "; t=t->link; };
			   s<< endl;
			   return s;
}
#endif