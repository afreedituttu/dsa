#include<iostream>
#include<string>
using namespace std;

struct Node{
    int value;
    Node *next;

    Node(int value, Node *next = nullptr){
        this->value = value;
        this->next = next;
    }
};

class Linkedlist{
    private:
        Node *head;
    public:
        Linkedlist(){
            head = nullptr;
        };
        void display();
        void find(int value);
        void insert(int value);
        void insertAfterPosWithVal(int pos_value, int value);
        void remove(int value);
        void removeAtPosWithVal(int value);
        void sort();
};

int main(){
    int exit = 0, choice, value, pos_value;
    Linkedlist list;
    do{
        cout << "\n 1) Display" ;
        cout << "\n 2) Find" ;
        cout << "\n 3) insert" ;
        cout << "\n 4) insert after pos" ;
        cout << "\n 5) remove" ;
        cout << "\n 6) sort" ;
        cout << "\n 7) exit" ;
        cout << "\n Please select an option :\t" ;
        cin >> choice;

        switch(choice){
            case 1:
                list.display();
                break;
            case 2:
                cout << "\nEnter the value to find :\t" ;
                cin >> value;
                list.find(value);
                break;
            case 3:
                cout << "\nEnter the value to insert :\t"  ;
                cin >> value;
                list.insert(value);
                break;
            case 4:
                cout << "\nEnter the value of postion :\t"  ;
                cin >> pos_value;
                cout << "\nEnter the actual value to insert:\t"  ;
                cin >> value;
                list.insertAfterPosWithVal(pos_value, value);
                break;
            case 5:
                cout << "\nEnter the element to delete :\t" ;
                cin >> value;
                list.remove(value);
                break;
            case 6:
                cout << "\nSorting Linkedlist...\n";
                list.sort();
                break;
            case 7:
                exit = 1;
                break;
            default:
                cout << "\n Wrong option\t" ;
                break;
        }
    }while(exit == 0);
    return 0;
};

void Linkedlist::display(){
    Node *temp = head;
    while(temp != nullptr){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << "\n";
};
void Linkedlist::find(int value){
    Node *temp = head;
    int index=0;
    while(temp->value != value && temp != nullptr){
        temp = temp->next;
        index++;
    }
    if(temp == nullptr){
        cout << "\nElement does not exist \n";
        return;
    }else{
        cout << "\nElement " << value << " found at postion " << index;
        return;
    }
};
void Linkedlist::insert(int value){
    Node *current = head;
    Node *temp = new Node(value);

    if(head == nullptr){
        head = temp;
    }else{
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = temp;
        return;
    }
};
void Linkedlist::insertAfterPosWithVal(int pos_value, int value){
    Node *current = head;
    Node *temp = new Node(value);
    if(current->value == value){
        temp->next = head;
        head = temp;
    }else{
        while(current->value != pos_value && current != nullptr){
            current = current->next;
        }
        if(temp == nullptr){
            cout << "\n Element with the give values does not exist \n";
            return;
        }else{
            temp->next = current->next;
            current->next = temp;
            return;
        }
    }
}
void Linkedlist::remove(int value){
    Node *temp = head;
    Node *prev = head;
    if(temp->value == value){
        head = head->next;
        delete temp;
        return;
    }
    while(temp->value != value && temp != nullptr){
        prev = temp;
        temp = temp->next;
    }
    cout << temp;
    if(temp == nullptr){
        cout << "\nElement Not found\n";
        return;
    }else{
        prev->next = temp->next;
        delete temp;
        return;
    }
};

// not working
void Linkedlist::sort(){
    Node *current = head;
    Node *future;
    Node *temp;
    for(current = head; current->next != nullptr; current = current->next){
        for(future = current->next; future != nullptr; future = future->next){
            if(current->value > future->value){
                temp = current;
                current = future;
                future = temp;
            }
        }
    }
}