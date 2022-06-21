#include <iostream>
using namespace std;
class Node {
    public:
	int key;
        int value;
        Node* left;
        Node* right;
	Node* parent;
        Node (int k,int v) {
	    key = k;
            value = v;
	    parent = nullptr;
            left = nullptr;
            right = nullptr;
        }
};
class Map{ 
    private:
        Node* root = nullptr;
        int length = 0;
    

    public:
		bool is_empty(){
			return (root==nullptr);
		}

		~Map(){
			if (!is_empty()) {
				destroy(root);	
			}				
		}

		Map () {

		}
		
		Map (const Map& t ) {
			cout << "called copy constructor" << endl; 
			cp(t.root);       	
		}
	
		Map& operator=(const Map& t){
			if (this == &t) {
				cout << "The same object." << endl;
				return* this;
			}
			if (!is_empty()){
				destroy(root);
			}
			//Comment special:
			//root link is not nullpointer if the line below wasn't written
			root = nullptr;
			cp(t.root);
			return* this;       	
		}
	

		//operator for comparison 2 bts	
		bool operator==(const Map& t) {
			cout << "called == operator" << endl;
			if (this == &t) {
				cout << "The same object." << endl;
				return true;
			}
            		if (length != t.length) {
                		return false;
            		}
			return compare(root,t.root);
        	}
		
		bool operator!=(const Map& t) {
			return !(*this==t);
		}

		void add(int x,int k) {
			add(root,x,k);
		}
		

		void print(){
			if (!is_empty()) {
				print(root);
			}
		}
		void print(bool desc) {
			if (!is_empty()) {
				print(root,desc);
			}
		}

		bool find(int key){
			if (!is_empty()) {
				return find(root,key);
			} else {
				return false;
			}
		}
		
		Node* find_ex(int key){
			if (!is_empty()) {
				return find_ex(root,key);
			}
			return nullptr;
		}

		Node* find_min(Node* tmp) {
			Node* t = tmp;
			while (tmp->left!=nullptr) {
				t = tmp->left;
				tmp->left = tmp->left->left;	
			}
			return t;
		}
		
		bool remove(int key) {
			bool f = 0;
			Node* tmp = find_ex(key);
			if (tmp==nullptr){
				return false;	
			}
			//case 1: to be deleted node has no leaves
			if (tmp->left == nullptr && tmp->right == nullptr){
			 	Node* t = tmp->parent;	
				if (t->key > tmp->key) {
					f = 1;
				} 
				delete tmp;
				if (f) {
					t->left = nullptr;
				} else {
					t->right = nullptr;
				}
				--length;
				return true;
			} 
			//case 2: to be deleted node has only one leaf
			else if ( tmp->left == nullptr && tmp->right != nullptr ) {	
				tmp->key = tmp->right->key;
				tmp->value = tmp->right->value;
				Node* res = tmp;
				delete tmp->right;
				res->right = nullptr;
				--length;
				return true;
			
			} else if ( tmp -> right == nullptr && tmp->left != nullptr) {
				Node* res = tmp;
				tmp->key = tmp->left->key;
				tmp->value = tmp->left->value;
				delete tmp->left;
				res->left = nullptr;
				--length;
				return true;
			}
			//case 3: to be deleted node has 2 leaves
			else { 
				if(tmp->right->left != nullptr) {
					Node* res = find_min(tmp->right);	
					tmp->key = res->key;
					tmp->value = res->value;
					if (res->right ==nullptr) {
						Node* t = res->parent;
						delete res;
						t->left = nullptr;
						--length;
						return true;
					}
					else {
						Node* t = res->parent;
						t->left = res->right;
						delete res;
						--length;
						return true;
					}
				} else {
					tmp->key = tmp->right->key;
					tmp->value = tmp->right->value;
					Node* t = tmp->right;
					if (tmp->right->right!= nullptr){
						tmp->right = tmp->right->right;
						delete t;
						t = nullptr;
						--length;
						return true;
					} else { 
						delete tmp->right;
						tmp->right = nullptr;
						--length;
						return true;
					}
				}  
			}
			return false;
		}  

	private:
		void destroy (Node* tmp){
			if (tmp != nullptr) {
				destroy(tmp->left);
				destroy(tmp->right);
				--length;
				delete tmp;
			}
		}

		void cp( Node* tmp) {
			if (tmp!= nullptr) {	
				add(tmp->value,tmp->key);
				cp(tmp->right);
				cp(tmp->left);
			}
		} 
		
 
		bool compare (Node* tmp1, Node* tmp2) {
			if ((tmp1!=nullptr&& tmp2==nullptr) || (tmp1==nullptr && tmp2!=nullptr) ) {
				cout << "First if" << endl;
				return false;
			}
			if (tmp1!= nullptr && tmp2!=nullptr){
				if(tmp1->key != tmp2->key || tmp1->value != tmp2->value) {
					cout << "Second if" << endl;
					cout << tmp1->key << " tmp1->key and tmp2->key " <<  tmp2->key  << endl;
					cout << tmp1->value << " tmp1->value and tmp2->value " <<  tmp2->value << endl;
					return false;
				} else { 
					bool r  = compare(tmp1->left,tmp2->left);
					bool r1 = compare(tmp1->right,tmp2->right);
					return r && r1;
				}
			} 
			return true;
			
		}		


		//Display binary search tree with ascending order
		void print(Node* tmp) {
			if (tmp != nullptr) { 
				print(tmp->left);
				cout << "key: " << tmp->key << " value: " <<  tmp->value << endl;
				print(tmp->right);
			} 
		}
		//Display binary search tree with descending order	
	
		void print(Node* tmp, bool desc) {
			if (tmp != nullptr) { 
				print(tmp->right,true);
				cout << "key: " << tmp->key << " value: " <<  tmp->value << endl;
				print(tmp->left,true);
			} 
		}
		
		int find_loc(int key) {
			int i = 0;
			for (Node *tmp = head; tmp != nullptr; tmp = tmp->next) {
			    if (key > tmp->key) {
				insert(t, i);
				return;
			    }
			    ++i;
			}

		}
		

		void add(Node* tmp, int value,int key) {
			//Comment special:
			//in this case was working one of the else if statements
			
			if (root == nullptr){
				length++;
				//cout << "root is nullptr" << endl;
				root = new Node(key,value);
				return;
			}
			Node* t = find_ex(key); 
			if (t != nullptr) {
				while(key ) {
				t->value = value;
				return;
			}
			if ( key > tmp->key ) {
				//Comment special:
				//in this case tmp->value is not in managed address
				if (tmp->right == nullptr) {	
					//Comment special:
					// then was working this block
					tmp->right=new Node(key,value);
					tmp->right->parent = tmp;
					length++;
				} else {
					add(tmp->right, value, key);
				}
			} else if ( key < tmp->key ) {
				if (tmp->left == nullptr) {
					//cout << find_ex(key) << " key " << key << endl;
					tmp->left=new Node(key,value);
					tmp->left->parent = tmp;
					length++;
				} else {
					add(tmp->left, value, key);
				}
			}
		}
		
		bool find(Node* tmp, int key) {
			if (tmp==nullptr) {
				return false;
			} 
			if (key==tmp->key) {
				return true;
			} else if ( key > tmp->key ) {
				return find(tmp->right, key);
			} else {
				return find(tmp->left, key);
			}
			return false; 
		}
		
		
		Node* find_ex(Node* tmp, int key) {
			if (tmp==nullptr) {
				return nullptr;
			}
			if (key==tmp->key) {
				cout << "hello"<<endl;
				return tmp;
			} else if ( key > tmp->key ) {
				return find_ex(tmp->right, key);
			} else {
				return find_ex(tmp->left, key);
			}
			return nullptr; 
			 
		}
		
	
};

int main () {
	Map b;
	b.add(50,1);
	b.add(30,2);
	b.add(100,6);
	b.print();
	b.add(190,6);
	b.add(10,8);
	b.add(1,3);
	b.add(40,5);
	b.add(42,0);
	b.add(65,4);
	b.add(74,-1);
	b.print();
	Map b1;
	b1.add(5,1);
        b1.add(3,2);
	//cout << "------------our check-----------------------"	<<endl;
	//if (b!=b1) {
	//	cout << "Map s are not equal" << endl;
	//} else {
	//	cout << "Map s are equal" << endl;
	//}
	//cout << "----------------Print in asc order---------------" << endl;
	//b.print();
	//cout << "----------------Print in desc order-------------" << endl;
	//b.print(true);
	//b1 = b;
	//cout << "------------print copy-------------" << endl;
	//b1.print();
	//cout << "---------------calling copy constructor-----------------" << endl;
	//Map b2 = b1;
	//b2.print();
	//cout << "---------------Compare Map s-----------------" << endl;
	//if (b2==b1) {
	//	cout << "Map s are equal" << endl;
	//} else {
	//	cout << "Map s aren't equal" << endl;
	//}
	//cout << "-----------------Removing part---------------" << endl;
	//cout << "Removing key 4 : case 1 has no leaves" << endl;
	//b.print();
	//b.remove(4);
	//cout << "After removing key 4 value 65 " << endl;
	//b.print();
	//cout << "-----------------Removing part---------------" << endl;
	//cout << "Removing key 0 : case 2 has one leaf" << endl;
	//b.print();
	//b.remove(0);
	//cout << "After removing key 0 value 42 " << endl;
	//b.print();
	//cout << "-----------------Removing part---------------" << endl;
	//cout << "Removing key 6 : case 3 has 2 leaves" << endl;
	//b.print();
	//b.remove(6);
	//cout << "After removing key 6 value 100 " << endl;
	//b.print();
 
	//if (b==b) {
	//	cout << " true" << endl;
	//}
	//b = b;

	
	return 0;
}
