#include <iostream>
using namespace std;

//Name: Sajjal Rana
//SID: 21105090
//Branch: ECE

//CREATING NODE CLASSS
class Node{
    public:
    //Creating class objects
    string name;
    int age;
    Node*next; //A node pointer for next node
    Node*prev; //A node pointer for previous node
    //calling constructor
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; //initialising next as NULL
        prev=NULL; //initialising prev as NULL
    }
};

//FUNCTION TO INSERT DATA AT END OF LINKED LIST
void append(Node* &head,string name,int age){
    //Creating a node pointer and storing address of head in box
    Node*box=head;
    //creating a new node and storing name and age in it
    Node*new_node=new Node(name,age);
    //Inserting node in empty list
    if(box==NULL){
        head=new_node;
    }
    //Inserting node in non empty list
    else{
        while(box->next!=NULL){box=box->next;}
        box->next=new_node;
        new_node->prev=box;
    }
}

//FUNCTION TO INSERT DATA AT START OF LINKED LIST
void insert_at_head(Node*&head,string name,int age){
    //Creating a Node pointer and storing address of new node in it 
    Node*new_node=new Node(name,age);
    //Inserting new node at head
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

//FUNCTION TO DIPLAY DATA FROM START OF LINKED LIST
void display_from_start(Node*head){
    Node*box=head;
    while(box!=NULL){cout<<"[Name:"<<box->name<<" Age:"<<box->age<<"]"<<"<=>";box=box->next;}
    cout<<endl;
}

//FUNCTION TO DISPLAY DATA FROM END OF LINKED LIST
void display_from_end(Node*head){
    Node*box=head;
    while(box->next!=NULL){box=box->next;}
    while(box!=NULL){cout<<"[Name:"<<box->name<<" Age:"<<box->age<<"]"<<"<=>";box=box->prev;}
    cout<<endl;
}

//FUNCTION TO DELETE ANY INDEX(0,n-1) EXCLUDING LAST ELEMENT 
void delete_ind(Node*&head,int i){
    if(i==0){
        Node*box=head;
        head=box->next;
        head->prev=NULL;
        delete box;
    }
    else{
        Node*box=head;
        for(int j=0;j<i;j++){box=box->next;}
        box->prev->next=box->next;
        box->next->prev=box->prev;
        delete box;
    }
}

//FUNCTION TO DELETE LAST ELEMENT
void pop(Node*&head){
    Node*box=head;
    while(box->next!=NULL){box=box->next;}
    box->prev->next=NULL;
    delete box;
}

int main(){
    //Initialising an empty linked list
    Node*head=NULL;
	int no_of_family_mem;
    //Taking no of family mem as input
	cout<<"Enter Number Of Family Members:";cin>>no_of_family_mem;
    //Inserting family members details in doubly linked list
	for(int i=1;i<=no_of_family_mem;i++){
		string name;
		int age;
		cout<<"Enter Family Member "<<i<<" Name:";cin.ignore();getline(cin,name);
		cout<<"Enter Family Member "<<i<<" Age:";cin>>age;
        //appending data name and age in doubly linked list
		append(head,name,age);
	}
    cout<<endl;//For space
    //Displaying Family details
    cout<<"Doubly Linked list with my family members as elements is shown below:"<<endl;
    cout<<endl;
    display_from_start(head);
}