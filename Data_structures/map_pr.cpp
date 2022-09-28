#include <iostream>
using namespace std;
class Node {
    public:
        int value;
	int key;
        Node* prev = nullptr;
        Node* next = nullptr;
        Node (int x,int k) {
            value = x;
            key = k; 		
            prev = nullptr;
            next = nullptr;
        }
};
class map{
    private:
        Node* head = nullptr;
        Node* tail = nullptr;
        int length = 0;
	
        Node* find(int key) {
            for( Node* tmp = head;tmp!= nullptr;tmp = tmp->next){
            	if (tmp->key==key){
		    return tmp;
		}
	    } 		
	    return nullptr;
	}
	
        void push_back(Node* temp, int k) {
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
        void push_front(Node* temp, int k) {
		if (is_empty()) {
		    head = temp;
		    tail = temp;
		} else {
		    if (!find(k)) {
			temp->next = head;
			head-> prev = temp;
			head = temp;
		    }
		
		} 
		++length;
        }


    public:
	   
       ~map() {
           while( head != tail ) {
               head = head->next;
               delete head->prev;
           }
           if (head != nullptr) {
               delete head;
           }
        }
	map () {}
        map (const map& ll ) {
                Node* h = ll.head;
                for (int i = 0; i < length ; ++i) {
                        push_back(h,h->key);
                        h = h ->next;
		}
	}
	
	map& operator=(const map& ll){
		cout<<"operator " <<endl;
		Node* h = ll.head;
                for (int i = 0; i < length ; ++i) {
                        h = h ->next;
                        push_back(h,h->key);
                }
		return *this;
	}
	bool operator==(map& ll) {
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
	//Fast search 
        void push(int key, int value) {
	    if (find(key)== nullptr) {
                Node* t = new Node(value,key);
		if (is_empty()){
		    head = tail = t;
		    return;
		}
		if (key > head->key) {
		    push_front(t,key);
		    return;
		}
		else if (key < tail->key){
		    push_back(t,key);
		    return;
		} else {
		    Node* tmp = head;
	            while (tmp!=nullptr) {
            		if (key > tmp->key) {
			    break;
			}
			tmp = tmp->next;	
                    }
		    tmp->prev->next = t;
		    t->next = tmp;
		    t->prev = tmp->prev;
		    tmp->prev = t;
		}
	    } else {
		find(key)->value = value;
	    }
        }

        Node* pop_back(){
            if (is_empty()){
                return nullptr;
            }
            Node* t = tail;
	    if (head == tail){
	        head=tail=nullptr;
                --length;
                Node* val = t;
                delete t;
                return val; 
	    }
            tail = tail-> prev;
            tail-> next = nullptr;
	    Node* val = t;
	    delete t;
            --length;
            return val;
        }
        Node* pop_front(){
            if (is_empty()){
                return nullptr;
            }
            Node* h = head;
	    if (head == tail){
	        head=tail=nullptr;
                --length;
                Node* val = h;
                delete h;
                return val; 
	    }
            head = head-> next;
            head-> prev = nullptr;
            Node* val = h;
	    delete h;
            --length;
            return val;
        }
        void print () {
            for( Node* tmp = head;tmp!= nullptr;tmp = tmp->next){
                cout<<tmp->value << " value and key is " << tmp->key  << endl;
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

        Node* pop(int i){
            Node* tmp = head;
            cout << length << " : length is " << endl;
            if (is_empty() || i > (length-1)){
                return nullptr;
            }
            if (head == tail){
                head=tail=nullptr;
		--length;
		Node* val = tmp;
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
	            Node* val = tmp;
                    delete tmp;
                    return val;
                } else {
                    return pop_front();
                }
            } else {
                return pop_back();
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
    map ll;
    ll.push(4,0);
    ll.push(15,5);
    ll.push(17,2);
    ll.push(1,11);
    ll.push(6,4);
    ll.push(2,4);
    ll.push(2,5);
    ll.print();
    cout << ll.pop(1)->value;
    //if (ll == ll1) {
    //    cout << "Is equal" << endl;
    //} else {
    //    cout << "Is not equal" << endl;
    //}
    //map ll2; 
    //ll2 = ll;    
    //cout << "Find" <<endl; 
    //cout << ll.find(14) << endl;
    return 0;
}
