#include <iostream>
using namespace std;

class Rectangle{
	public:
		int width;
		int length;

	int area(){
		return width*length;
	}
	int perimeter(){
		return (width+length)*2;
	}
	Rectangle() {}

	Rectangle(int width, int length) {
		this->width = width;
		this->length = length;
	}

	friend ostream& operator<<(ostream& pr, Rectangle rec){
                pr<<"width is: " << rec.width<<endl;
                pr<<"length is: " << rec.length<<endl;
                pr<<"area is: " << rec.area()<<endl;
                pr<<"perimeter is: " << rec.perimeter()<<endl;
                return pr;
	}
};



class Specialist {
	public:
		string name;
		string surname;
		int age;
		int languages;
		int iq;
	Specialist(){}        

	Specialist (string name, string surname,int age, int languages,int iq) {
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->languages = languages;
		this->iq = iq;
	}
   
	//operator bool(){
	//	if (name !=nullptr || surname !=nullptr || age!=0) {
	//		return true;
	//	} else {
	//		return false;
	//	}
	//}
	friend ostream& operator<<(ostream& pr, Specialist spec){
                pr<<"name is: " << spec.name<<endl;
                pr<<"surname is: " << spec.surname<<endl;
                pr<<"age is: " << spec.age<<endl;
                pr<<"languages is: " << spec.languages<<endl;
                pr<<"iq is: " << spec.iq<<endl;
                return pr;
        }	

};

template <class K,class V>
class Node {
    public:
	K key;
        V value;
        Node<K,V>* left;
        Node<K,V>* right;
	Node<K,V>* parent;
        Node (K key,V value) {
	    this->key = key;
            this->value = value;
	    parent = nullptr;
            left = nullptr;
            right = nullptr;
        }
};

template <class K,class V>
class Map{ 
    private:
        Node<K,V>* root = nullptr;
        int length = 0;
        int(* comp)(const K& a, const K& b);

    public:
		bool is_empty(){
			return (root==nullptr);
		}

		~Map(){
			if (!is_empty()) {
				destroy(root);	
			}				
		}

		Map (int (* x)(const K& a,const K& b) ) {
                        comp = x;
		}
		
		Map (const Map& t, int (* x)(const K& a,const K& b)  ) {
			cout << "called copy constructor" << endl; 
                        comp = x;
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

		void add(V x,K k) {
			add(root,x,k);
		}
		

		void print(){
			if (!is_empty()) {
				print(root);
			}
		}

		bool find(K key){
			if (!is_empty()) {
				return find(root,key);
			} else {
				return false;
			}
		}
		
		Node<K,V>* find_ex(K key){
			if (!is_empty()) {
				return find_ex(root,key);
			}
			return nullptr;
		}

		Node<K,V>* find_min( Node<K,V>* tmp) {
			auto t = tmp;
			while (tmp->left!=nullptr) {
				t = tmp->left;
				tmp->left = tmp->left->left;	
			}
			return t;
		}
		
		bool remove(K key) {
			bool f = 0;
			auto tmp = find_ex(key);
			if (tmp==nullptr){
				return false;	
			}
			//case 1: to be deleted node has no leaves
			if (tmp->left == nullptr && tmp->right == nullptr){
			 	auto t = tmp->parent;	
				if (comp(t->key,tmp->key)==1) {
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
				auto res = tmp;
				delete tmp->right;
				res->right = nullptr;
				--length;
				return true;
			
			} else if ( tmp -> right == nullptr && tmp->left != nullptr) {
				auto res = tmp;
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
					auto res = find_min(tmp->right);	
					tmp->key = res->key;
					tmp->value = res->value;
					if (res->right ==nullptr) {
						auto t = res->parent;
						delete res;
						t->left = nullptr;
						--length;
						return true;
					}
					else {
						auto t = res->parent;
						t->left = res->right;
						delete res;
						--length;
						return true;
					}
				} else {
					tmp->key = tmp->right->key;
					tmp->value = tmp->right->value;
					auto t = tmp->right;
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
		void destroy (Node<K,V>* tmp){
			if (tmp != nullptr) {
				destroy(tmp->left);
				destroy(tmp->right);
				--length;
				delete tmp;
			}
		}

		void cp( Node<K,V>* tmp) {
			if (tmp!= nullptr) {	
				add(tmp->value,tmp->key);
				cp(tmp->right);
				cp(tmp->left);
			}
		} 
		
 
		bool compare (Node<K,V>* tmp1, Node<K,V>* tmp2) {
			if ((tmp1!=nullptr&& tmp2==nullptr) || (tmp1==nullptr && tmp2!=nullptr) ) {
				//cout << "First if" << endl;
				return false;
			}
			if (tmp1!= nullptr && tmp2!=nullptr){
				if((comp(tmp1->key,tmp2->key)==-1) || (tmp1->value < tmp2->value)) {
				//	cout << "Second if" << endl;
				//	cout << tmp1->key << " tmp1->key and tmp2->key " <<  tmp2->key  << endl;
				//	cout << tmp1->value << " tmp1->value and tmp2->value " <<  tmp2->value << endl;
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
		void print(Node<K,V>* tmp) {
			if (tmp != nullptr) { 
				print(tmp->left);
				cout << "key is : "<<endl;
                                cout << tmp->key << endl;
                                cout << "value is : " <<  tmp->value << endl;
				print(tmp->right);
			} 
		}

		void add(Node<K,V>* tmp, V value,K key) {
			//Comment special:
			//in this case was working one of the else if statements
			
			if (root == nullptr){
				length++;
				root = new Node<K,V>(key,value);
				return;
			}
			auto t = find_ex(key); 
			if ( (comp(key,tmp->key))>=0 ) {
				//Comment special:
				//in this case tmp->value is not in managed address
				if (tmp->right == nullptr) {	
					//Comment special:
					// then was working this block
					tmp->right=new Node<K,V>(key,value);
					tmp->right->parent = tmp;
					length++;
				} else {
					add(tmp->right, value, key);
				}
			} else if ( comp(key,tmp->key)==-1) {
				if (tmp->left == nullptr) {
					//cout << find_ex(key) << " key " << key << endl;
					tmp->left=new Node<K,V>(key,value);
					tmp->left->parent = tmp;
					length++;
				} else {
					add(tmp->left, value, key);
				}
			}
		}
		
		bool find(Node<K,V>* tmp, K key) {
			if (tmp==nullptr) {
				return false;
			} 
			if (key==tmp->key) {
				return true;
			} else if ((comp(key,tmp->key) == 1) ) {
				return find(tmp->right, key);
			} else {
				return find(tmp->left, key);
			}
			return false; 
		}
		
		
		Node<K,V>* find_ex(Node<K,V>* tmp, K key) {
			if (tmp==nullptr) {
				return nullptr;
			}
			if ( comp(key,tmp->key)==0) {
				return tmp;
			} else if ( comp(key,tmp->key)==1 ) {
				return find_ex(tmp->right, key);
			} else {
				return find_ex(tmp->left, key);
			}
			return nullptr; 
			 
		}
		
	
};

int comp( const Specialist& a,const Specialist& b) {
	if(a.age > b.age) {
                                return 1;
                        } else if (a.age == b.age) {
                                return 0;
                        } else {
                                return -1;
                        }
}

int main () {
//	Map<Specialist,int> b([](const Specialist& a,const Specialist& b){
//			if(a.age > b.age) {
//				return 1;
//			} else if (a.age == b.age) {
//				return 0;
//			} else {
//				return -1;
//			}
//        });
        Map<Specialist,int> b(comp);
	b.add(1,Specialist("John","Walker",15,2,90));
	b.add(2,Specialist("Jane","Smith",18,2,95));
	b.add(3,Specialist("Kareem","S",35,3,120));
	b.add(4,Specialist("Nahlu","Mohammad",12,1,75));
	b.print();
	
	return 0;
}
