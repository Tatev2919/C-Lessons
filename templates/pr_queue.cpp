#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T value;
    Node<T>* prev;
    Node<T>* next;
    Node(T x)
    {
        this->value = x;
        prev = nullptr;
        next = nullptr;
    }
};


template <class T>
class pr_queue {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int length = 0;

    bool is_empty() {
        return head == nullptr;
    }

    void push_back(const T& val){
	Node<T>* temp = new Node<T> (val);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        ++length;
    }

    void push_front(const T& val) {
	Node<T>* temp = new Node<T> (val);
        if (is_empty()) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        ++length;
    }

    void insert(const T& val, int i) {
        auto tmp = head;
        if (i == 0) {
            push_front(val);
            return;
        } else if (i == length) {
            push_back(val);
            return;
        } else {
	    Node<T>* add = new Node<T> (val);
            for (int j = 0; j != i; ++j) {
                tmp = tmp->next;
            }
            tmp->prev->next = add;
            add->next = tmp;
            add->prev = tmp->prev;
            tmp->prev = add;
            return;
        }
    }

public:
    ~pr_queue() {
        while (head != tail) {
            head = head->next;
            delete head->prev;
        }
        if (head != nullptr) {
            delete head;
        }
    }

    pr_queue() {}
    
    pr_queue(const pr_queue &ll) {
        auto h = ll.head;
        for (int i = 0; i < ll.length; ++i) {
            push_back(h);
            h = h->next;
        }
    }

    void destroy() {
        while (head != tail) {
            head = head->next;
            delete head->prev;
        }
        if (head != nullptr) {
            delete head;
        }
    }

    pr_queue &operator=(const pr_queue &ll) {
        if (!is_empty()) {
            destroy();
            head = tail = nullptr;
        }
        cout << ll.head->value;
        auto h = ll.head;
        for (int i = 0; i < ll.length; ++i) {
            push_back(h);
            h = h->next;
        }
        return *this;
    }
    bool operator==(pr_queue &ll) {
        if (length != ll.length) {
            return false;
        } 
        else {
            auto t1 = head;
            auto t2 = ll.head;

            for (int i = 0; i < ll.length; ++i) {
                if (t1->value != t2->value) {
                    return false;
                }
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        return true;
    }
    
    //Added public push function 
    //using which you can organise the priority of queue.  
  
    void push(const T& x) {
        if (is_empty()) {
            push_front(x);
            return;
        } 
        if (x < tail->value ) {
    	    push_back(x);
            return;
	}
        int i = 0;
        for (auto tmp = head; tmp != nullptr; tmp = tmp->next) {
            if (x > tmp->value) {
                insert(x, i);
                return;
            }
            ++i;
        }
    }

    bool find(const T& x) {
        for (auto tmp = head; tmp != nullptr; tmp = tmp->next) {
            if (tmp->value == x) {
                return true;
            }
        }
        return false;
    }

    T pop_back() {
        if (is_empty()) {
            return -1;
        }
        auto t = tail;
        if (head == tail) {
            head = tail = nullptr;
            --length;
            T val = t->value;
            delete t;
            return val;
        }
        tail = tail->prev;
        tail->next = nullptr;
        T val = t->value;
        delete t;
        --length;
        return val;
    }

    T pop_front() {
        if (is_empty()) {
            return -1;
        }
        auto h = head;
        if (head == tail) {
            head = tail = nullptr;
            --length;
            T val = h->value;
            delete h;
            return val;
        }
        head = head->next;
        head->prev = nullptr;
        T val = h->value;
        delete h;
        --length;
        return val;
    }

    void print() {
        for (auto tmp = head; tmp != nullptr; tmp = tmp->next){
            cout << tmp->value << endl;
        }
    }

    T get_node(int i) {
        auto tmp = head;
        if (i > length) {
            return -1;
        }
        for (int j = 0; tmp != nullptr && j != i; j++) {
            tmp = tmp->next;
        }
        return tmp->value;
    }

    T pop(int i) {
        auto tmp = head;
        cout << length << " : length is " << endl;
        if (is_empty() || i > (length - 1)) {
            return -1;
        }
        if (head == tail) {
            head = tail = nullptr;
            --length;
            T val = tmp->value;
            delete tmp;
            return val;
        }
        for (int j = 0; tmp != nullptr && j != i; ++j) {
            tmp = tmp->next;
        }
        if (tmp != tail){
            if (tmp != head) {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
                cout << tmp->value << endl;
                --length;
                T val = tmp->value;
                delete tmp;
                return val;
            }
            else {
                return pop_front();
            }
        }
        else {
            return pop_back();
        }
    }

    void print_reverse() {
        for (auto tmp = tail; tmp != nullptr; tmp = tmp->prev) {
            cout << tmp->value << endl;
        }
    }
};
int main()
{
    pr_queue<string> pq;
    pq.push("hello");
    pq.push("world");
    pq.push("Everything");
    pq.push("is");
    pq.push("great");
    pq.push("now");
    pq.print();
    pr_queue<int> pq1;
    pq1.push(1);
    pq1.push(2);
    pq1.push(3);
    pq1.push(4);
    pq1.push(5);
    pq1.print();
    pr_queue<int> pq2;
    
    return 0;
}
