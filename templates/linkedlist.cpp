#include <iostream>
#include<ctime>
using namespace std;

class indexOutOfBounds: public exception{
	public:
		string cause;
		string solution;
		int index;
		time_t time;
		int length;
		
		indexOutOfBounds(string cause, string solution, int index,time_t time,int length){
			this->cause = cause;
			this->solution = solution;
			this->index= index;
			this->time = time;
			this->length = length;
		}
		
		void print (){
			cout << "cause is : " <<  cause << endl;
			cout << "solution is: " << solution << endl;
			cout << "index is : " << index << " while length is : " << length << endl;
			cout << "time is : " << ctime(&time) << endl;
		}
		
		const char* what() const throw() {
			return "index out of bounds exception";
		}

};
class exforpop : public exception{
	public:
		string cause;
		string solution;
		time_t time;
		int length;
		
		exforpop(string cause, string solution,time_t time,int length){
			this->cause = cause;
			this->solution = solution;
			this->time = time;
			this->length = length;
		}
		
		void print (){
			cout << "cause is : " <<  cause << endl;
			cout << "solution is: " << solution << endl;
			cout << "length is : " << length << endl;
			cout << "time is : " << ctime(&time) << endl;
		}
		const char* what() const throw () {
			return "exception for pop function";
		}
};


template <class T>
class Node {
    public:
        T value;
        Node<T>* prev;
        Node<T>* next;
        Node (T x) {
            value = x;
            prev = nullptr;
            next = nullptr;
        }
};

template <class T>
class Linkedlist{
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
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
                auto h = ll.head;
                for (int i = 0; i < ll.length ; ++i) {
                        push_back(h->value);
                        h = h ->next;
                }
        }
         void destroy() {
           while( head != tail ) {
               head = head->next;
               delete head->prev;
           }
           if (head != nullptr) {
               delete head;
           }
        }
        Linkedlist& operator=(const Linkedlist& ll){
                if (!is_empty()){
                    destroy();
                    head=tail=nullptr;
                }
		
                auto h = ll.head;
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
                auto t1 = head;
                auto t2 = ll.head;
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
        bool find(T x) {
            for( auto tmp = head;tmp!= nullptr;tmp = tmp->next){
                if (tmp->value==x){
                    return true;
                }
            }
            return false;
        }
        void push_back(T x) {
            auto temp = new Node<T>(x);
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
        void push_front(T x) {
            auto temp = new Node<T>(x);
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

        T pop_back(){
            if (is_empty()){
		exforpop ex("trying to get value from the end of empty ll","not to use pop for empty ll",time(0),length);
                throw ex;
            }
            auto t = tail;
            if (head == tail){
                head=tail=nullptr;
                --length;
                T val = t->value;
                delete t;
                return val;
            }
            tail = tail-> prev;
            tail-> next = nullptr;
            T val = t-> value;
            delete t;
            --length;
            return val;
        }
        T pop_front(){
            if (is_empty()){
		exforpop ex("trying to get value from the start of empty ll","not to use pop for empty ll",time(0),length);
                throw ex;
            }
            auto h = head;
            if (head == tail){
                head=tail=nullptr;
                --length;
                T val = h->value;
                delete h;
                return val;
            }
            head = head-> next;
            head-> prev = nullptr;
            T val = h->value;
            delete h;
            --length;
            return val;
        }
        void print () {
            for( auto tmp = head;tmp!= nullptr;tmp = tmp->next){
                cout<<tmp->value << endl;
            }
        }
        T operator[](int i){
            auto tmp = head;
            if (i > length){
                indexOutOfBounds ex("index is out of scope","insert correct index less than length",i,time(0),length);
		throw ex;
            }
            for(int j = 0;tmp!= nullptr && j != i; j++){
                tmp = tmp->next;
            }
            return tmp->value;
        }
        T pop(int i){
            auto tmp = head;
            if (is_empty() || i > (length-1)){
		exforpop ex("trying to get value using specific index of empty ll","not to use pop for empty ll",time(0),length);
                throw ex;
            }
            if (head == tail){
                head=tail=nullptr;
                --length;
                T val = tmp->value;
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
                    --length;
                    T val = tmp -> value;
                    delete tmp;
                    return val;
                } else {
                    return pop_front();
                }
            } else {
   		return pop_back();
            }
        }
        void insert(T value,int i) {
            auto tmp = head;
            auto add = new Node<T>(value);
            if (is_empty()){
                head = tail = add;
            }
            if (i == 0) {
                push_front(value);
            } else if (i > length) {
                indexOutOfBounds ex("index is out of scope","insert correct index less than length",i,time(0),length);
		throw ex;
	    } else if (i == length){
                push_back(value);
            } else {
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
            for (auto tmp = tail;tmp!= nullptr; tmp = tmp->prev){
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
		Node<T>* t = nullptr;
		for (auto tmp = head->next;tmp!= nullptr; tmp = tmp->next){
			t = tmp->prev;
			while (t!=nullptr && t->value > tmp->value){
				t = t -> prev;
			}
			//if my 2 initial values are not moved  
			if (t != tmp->prev){
				// if tmp value is not in tail cut tmp from ll
				// --common part
				if (tmp!= tail){
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
				} else { // if tmp value is in tail change tail to tmp;
				    tail = tmp->prev;
				    tmp->prev->next=nullptr;
				}
				// if comparison pointer is on head will be done --common part and push value from front  
				if (t==nullptr) {
					push_front(tmp);
				} else { // if comparison pointer is not on head will be done --common part and add tmp value from the middle of ll 
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
    Linkedlist<int> ll;
    ll.insert(40,0);
    ll.insert(15,1);
    ll.insert(17,2);
    ll.print(); 
    //ll.insertion_sort();
    ll.print(); 
    Linkedlist<int>ll1;
    ll1.push_back(4);
    ll1.push_back(15);
    ll1.push_back(17);
    Linkedlist<int> ll2 = ll;
    cout << "Calling copy constructor . " << endl; 
    ll2.print();
    ll1 = ll;
    ll1.print();
    Linkedlist<string> l;
    try {
	l.pop_back();
    } catch (indexOutOfBounds ex ){
        cout << "exception was catched" << endl;
        cout<< ex.what();
        ex.print();
    } catch (exforpop ex){
        cout<< ex.what();
        ex.print();
    }
    return 0;
} 
