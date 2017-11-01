#ifndef MY_QUEUE_H
#define MY_QUEUE_H

enum Error_code { success, underflow, overflow, fail};

template<typename Queue_entry>
struct Node {
	Node *next;
	Queue_entry data;
	Node(const Queue_entry &data, Node *next = nullptr) :data(data), next(next) {}
};

template<typename Queue_entry>
class Queue {
public:
	Queue() :head(nullptr), rear(nullptr), size(0) {}
	~Queue() {
		while (size--) {
			rear = head->next;
			delete head;
			head = rear;
		}
	}
	bool empty() const {
		return size == 0;
	}
	Error_code append(const Queue_entry &x) {
		Node<Queue_entry> *temp = new Node<Queue_entry>(x);
		if(temp == nullptr)
			return overflow;
		
		if(size++){
			rear->next = temp;
			rear = temp;
		}
		else{
			head = rear = temp;
		}
		return success;
	}
	Error_code serve() {
		if (size == 0)
			return underflow;
		Node<Queue_entry> *temp = head;
		head = head->next;
		delete temp;
		--size;
		return success;
	}
	Error_code retrieve(Queue_entry &x) const {
		if (size == 0)
			return underflow;
		x = head->data;
		return success;
	}
protected:
	int size;
private:
	Node<Queue_entry> *head, *rear;
};

template<typename Queue_entry>
class Extended_queue : public Queue<Queue_entry> {
public:
	int size() const {
		return Queue::size;
	}
	bool full() const {
		return false;
	}
	void clear() {
		while (Queue::size--) {
			rear = head->next;
			delete head;
			head = rear;
		}
		Queue::size = 0;
		head = rear = nullptr;
	}
	Error_code serve_and_retrieve(Queue_entry &item) {
		retrieve(item);
		return serve();
	}
};

#endif