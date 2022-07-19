#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T value;
    Node<T>* prev;
    Node<T>* next;
    Node(int x)
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

    void push_back(Node<T>* temp){
        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        ++length;
    }

    void push_front(Node<T>* temp) {
        if (is_empty()) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        ++length;
    }

    void insert(Node<T>* add, int i) {
        auto tmp = head;
        //Node* add = new Node(value);
        //if (is_empty())
        //{
        //    head = tail = add;
	//    cout << "add -> val" << add->value << endl;
        //    return;
        //}
        if (i == 0) {
            push_front(add);
            return;
        } else if (i == length) {
            push_back(add);
            return;
        } else {
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
  
    void push(int x) {
	auto t = new Node<T>(x);
        if (is_empty()) {
            push_front(t);
            return;
        } 
        if (x < tail->value ) {
    	    push_back(t);
            return;
	}
        int i = 0;
        for (auto tmp = head; tmp != nullptr; tmp = tmp->next) {
            if (x > tmp->value) {
                insert(t, i);
                return;
            }
            ++i;
        }
    }

    bool find(int x) {
        for (auto tmp = head; tmp != nullptr; tmp = tmp->next) {
            if (tmp->value == x) {
                return true;
            }
        }
        return false;
    }

    int pop_back() {
        if (is_empty()) {
            return -1;
        }
        auto t = tail;
        if (head == tail) {
            head = tail = nullptr;
            --length;
            int val = t->value;
            delete t;
            return val;
        }
        tail = tail->prev;
        tail->next = nullptr;
        int val = t->value;
        delete t;
        --length;
        return val;
    }

    int pop_front() {
        if (is_empty()) {
            return -1;
        }
        auto h = head;
        if (head == tail) {
            head = tail = nullptr;
            --length;
            int val = h->value;
            delete h;
            return val;
        }
        head = head->next;
        head->prev = nullptr;
        int val = h->value;
        delete h;
        --length;
        return val;
    }

    void print() {
        for (auto tmp = head; tmp != nullptr; tmp = tmp->next){
            cout << tmp->value << endl;
        }
    }

    int get_node(int i) {
        auto tmp = head;
        if (i > length) {
            return -1;
        }
        for (int j = 0; tmp != nullptr && j != i; j++) {
            tmp = tmp->next;
        }
        return tmp->value;
    }

    int pop(int i) {
        auto tmp = head;
        cout << length << " : length is " << endl;
        if (is_empty() || i > (length - 1)) {
            return -1;
        }
        if (head == tail) {
            head = tail = nullptr;
            --length;
            int val = tmp->value;
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
                int val = tmp->value;
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
    pr_queue<int> pq;
    pq.push(4);
    pq.push(15);
    pq.push(17);
    pq.push(5);
    pq.push(18);
    pq.push(7);
    pq.push(25);
    pq.push(11);
    pq.push(3);
    pq.push(19);
    pq.print();
    pr_queue<int> pq1;
    pq1.push(1);
    pq1.push(2);
    pq1.push(3);
    pq1.push(4);
    pq1.push(5);
    pr_queue<int> pq2;
    
    return 0;
}
