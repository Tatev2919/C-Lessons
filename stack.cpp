
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
class Stack{
    private:
        Node* head = nullptr;
        Node* tail = nullptr;
        int length = 0;
    public:
        ~Stack() {
           while( head != tail ) {
               head = head->next;
               delete head->prev;
           }
           delete head;
	}
        void push(int x) {
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
        int pop(){
 		if(is_empty()) {
			throw 1;
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
        void print () {
            for( Node* tmp = head;tmp!= nullptr;tmp = tmp->next){
                cout<<tmp->value << endl;
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
};
int main () {
    Stack s;
    try {	
       s.pop();
    } catch ( int x){
	cout << "catched" << endl;
    }	
    //s.push(4);
    //s.push(15);
    //s.push(17);
    //s.push(1);
    //s.push(6);
    //s.push(2);
    //s.print();
    //s.pop();
    cout << "After " << endl;
    s.print();
    return 0;
}
