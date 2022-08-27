#include <iostream>
#include <climits>
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

class pr_queue{
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
	
        void push_back(Node* temp) {
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


    public:
	   
       ~pr_queue() {
           while( head != tail ) {
               head = head->next;
               delete head->prev;
           }
           if (head != nullptr) {
               delete head;
           }
        }
	pr_queue () {}
        pr_queue (const pr_queue& ll ) {
                Node* h = ll.head;
                for (int i = 0; i < length ; ++i) {
                        push_back(h);
                        h = h ->next;
		}
	}
	
	pr_queue& operator=(const pr_queue& ll){
		cout<<"operator " <<endl;
		Node* h = ll.head;
                for (int i = 0; i < length ; ++i) {
                        h = h ->next;
                        push_back(h);
                }
		return *this;
	}
	bool operator==(pr_queue& ll) {
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
		if (value > head->value) {
		    push_front(t);
		    return;
		}
		else if (value < tail->value){
		    push_back(t);
		    return;
		} else {
		    Node* tmp = head;
	            while (tmp!=nullptr) {
            		if (value > tmp->value) {
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
                if (find(key)->value >value){
		    find(key)->value = value;
                }
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

        Node* get_head(){
            return head;
        }
};


int main() {
	int x [9][9]{
            {5,0,0,0,0,0,45,0,15},
            {0,5,0,0,0,0,0,12,0},
            {0,0,0,20,0,60,0 ,0,0},
            {0,0,20,0,60,0,40,0,0},
            {0,0,0,60,0,0,0,30,0},
            {0,0,60,0,0,0,25,0,30},
            {0,45,0,40,0,25,0,70,0},
            {12,0,0,0,30,0,70,0,0},
            {0,15,0,0,0,30,0,0,0}
        };
        
         
        string names [9] = {"Yerevan","Ashtarak","Gyumri","Artashat","Yeghvard","Talin", "Aparan", "Abovyan","Oshakan"}; 
        int gagatner[9] =  {INT_MAX,INT_MAX,0,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
         
        for(int i = 0; i < 9; i++){
                cout << i << ": ";
                for(int j = 0; j < 9; j++){
                	cout << x[i][j] << "  ";
                } 
                cout << endl;
	}
       
        pr_queue pq;
       
        //start is Gyumri, as you need to add Gyumri pq first.
        pq.push(2,0);
        int ind = 2;
        int dest = 0;
        while (pq.is_empty()==0){
		for (int i =0; i<9; ++i){
 			if (x[ind][i] >= 0) {
                                if (gagatner[i]> (x[ind][i]+gagatner[ind])) { 
				    gagatner[i] = (x[ind][i]+gagatner[ind]);
                                }
                                pq.push(i,gagatner[i]);
		        } 
                }
                pq.pop(ind);
                ind = pq.get_head()->key; 
        }

        pq.print(); 
        for(int i = 0; i < 9; i++){
                cout << i <<" : " << gagatner[i] << endl;
        } 
        for(int i = 0; i < 9; i++){
                cout << i <<" : " << names[i] << endl;
        }
	return 0;
}
