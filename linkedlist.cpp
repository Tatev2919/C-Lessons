#include <iostream>
using namespace std;
class Node {
    public:
        int value;
        Node* prev = nullptr;
        Node* next = nullptr;
        Node (int x) {
            value = x;
            prev = nullptr;
            next = nullptr;
        }
};
class Linkedlist{
    private:
        Node* head = nullptr;
        Node* tail = nullptr;
        int length = 0;
    public:
       ~Linkedlist() {
           while( head != tail ) {
               head = head->next;
               delete head->prev;
           }
           if (head != nullptr) {
               delete head;
           }
        }
        Linkedlist () {}
        Linkedlist (const Linkedlist& ll ) {
                Node* h = ll.head;
                for (int i = 0; i < ll.length ; ++i) {
                        push_back(h->value);
                        h = h ->next;
                }
        }
         void destroy() {
           cout << "destroy1" <<endl;
           while( head != tail ) {
               head = head->next;
               cout<<head->value<< " dest"<< endl;
               delete head->prev;
           }
           if (head != nullptr) {
               cout <<"head part1"<<endl;
               delete head;
           }
        }
        Linkedlist& operator=(const Linkedlist& ll){
                cout<<"operator " <<endl;
                if (!is_empty()){
                    cout << "is not empty" <<endl;
                    destroy();
                    head=tail=nullptr;
                }
		
                Node* h = ll.head;
                cout << "ll.head:  " << ll.head->value <<endl;
                cout << "ll.head:  " << ll.head->value <<endl;
                for (int i = 0; i < ll.length ; ++i) {
                        push_back(h->value);
                        h = h ->next;
                }
                return *this;
        }
        bool operator==(Linkedlist& ll) {
            if (length != ll.length) {
                return false;
            } else {
                Node* t1 = head;
                Node* t2 = ll.head;
                for (int i =0; i <length ; ++i){
                       if (t1->value != t2->value) {
                            return false;
                       }
                       t1 = t1->next;
                       t2 = t2->next;
               }
            }
            return true;
        }
        bool find(int x) {
            for( Node* tmp = head;tmp!= nullptr;tmp = tmp->next){
                if (tmp->value==x){
                    return true;
                }
            }
            return false;
        }
        void push_back(int x) {
            Node* temp = new Node(x);
            if (head == nullptr) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
            ++length;
        }
        void push_front(Node* temp) {
            if (is_empty()) {
                head = temp;
                tail = temp;
            } else {
                temp->next = head;
                head-> prev = temp;
                head = temp;
            }
            ++length;
        }
        int pop_back(){
            if (is_empty()){
           return -1;
            }
            Node* t = tail;
            if (head == tail){
                head=tail=nullptr;
                --length;
                int val = t->value;
                delete t;
                return val;
            }
            tail = tail-> prev;
            tail-> next = nullptr;
            int val = t-> value;
            delete t;
            --length;
            return val;
        }
        int pop_front(){
            if (is_empty()){
                return -1;
            }
            Node* h = head;
            if (head == tail){
                head=tail=nullptr;
                --length;
                int val = h->value;
                delete h;
                return val;
            }
            head = head-> next;
            head-> prev = nullptr;
            int val = h->value;
            delete h;
            --length;
            return val;
        }
        void print () {
            for( Node* tmp = head;tmp!= nullptr;tmp = tmp->next){
                cout<<tmp->value << endl;
            }
      }
        int get_node(int i){
            Node* tmp = head;
            if (i > length){
                return -1;
            }
            for(int j = 0;tmp!= nullptr && j != i; j++){
                tmp = tmp->next;
            }
            return tmp->value;
        }
        int pop(int i){
            Node* tmp = head;
            cout << length << " : length is " << endl;
            if (is_empty() || i > (length-1)){
                return -1;
            }
            if (head == tail){
                head=tail=nullptr;
                --length;
                int val = tmp->value;
                delete tmp;
                return val;
            }
            for(int j = 0;tmp!= nullptr && j != i; ++j){
                tmp = tmp->next;
            }
            if(tmp != tail){
                if (tmp!=head){
                    tmp->next->prev=tmp->prev;
                    tmp->prev->next = tmp->next;
                    cout<< tmp->value << endl;
                    --length;
                    int val = tmp -> value;
                    delete tmp;
                    return val;
                } else {
                    return pop_front();
                }
            } else {
   		return pop_back();
            }
        }
        void insert(int value,int i) {
            Node* tmp = head;
            Node* add = new Node(value);
            if (is_empty()){
                head = tail = add;
            }
            if (i == 0) {
                cout << "test1" << endl;
                push_front(add);
            }
            else if (i == length){
                push_back(value);
            } else {
                cout << "test2: " << i << endl;
                for(int j = 0; j != i; ++j){
                    tmp = tmp->next;
                }
                tmp->prev->next = add;
                add->next = tmp;
                add->prev = tmp->prev;
                tmp->prev = add;
            }
        }
        void print_reverse () {
            for (Node* tmp = tail;tmp!= nullptr; tmp = tmp->prev){
                cout<<tmp->value << endl;
            }
        }
        bool is_empty() {
            return head == nullptr;
        }
	
	void insertion_sort() {
		cout << "----insertion sort----" << endl; 
		if (head == tail) {
			return;
		}
		Node* t = nullptr;
		for (Node* tmp = head->next;tmp!= nullptr; tmp = tmp->next){
			t = tmp->prev;
			while (t!=nullptr && t->value > tmp->value){
				t = t -> prev;
			} 
			if (t != tmp->prev){
				if (tmp!= tail){
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
				} else {
				    tail = tmp->prev;
				    tmp->prev->next=nullptr;
				}
				if (t==nullptr) {
					push_front(tmp);
				} else {
					tmp->next = t->next;
					tmp->prev = t;
					t->next->prev = tmp;
					t->next = tmp;
				}
			}
		}
	}
};
int main () {
    Linkedlist ll;
    ll.push_back(4);
    ll.push_back(15);
    ll.push_back(17);
    ll.push_back(16);
    ll.push_back(6);
    ll.push_back(12);
    ll.push_back(28);
    ll.push_back(150);
    ll.push_back(7);
    ll.push_back(2);
    ll.print(); 
    ll.insertion_sort();
    ll.print(); 
    //Linkedlist ll1;
    //ll1.push_back(4);
    //ll1.push_back(15);
    //ll1.push_back(17);
    //ll1.push_back(1);
    //ll1.push_back(6);
    ////ll1.push_front(2);
    //Linkedlist ll2 = ll;
    //cout << "Calling copy constructor . " << endl; 
    //ll2.print();
    //ll1 = ll;
    //ll1.print();
    return 0;
} 
