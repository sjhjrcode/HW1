

#include <iostream>
#include <string>
//#include <iterator>
#include <utility>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>

class Single { //create singly linked list node
public:
    Single* next; //next pointer
    std::string info; //node info
    Single(){
        info = "NULL";
        next = nullptr;
    }
    explicit Single(std::string store, Single *ptr = nullptr){
        this->info = std::move(store);
        this->next = ptr;
    }

};

class Single_List {// create singly linked list
    Single* head; // head pointer
    Single* tail; // tail pointer
public:
    Single_List() {

        head = tail= nullptr; //instantiate head and tail
    }
    //~Single_List();
    //static int isEmpty() {
    //    return head == nullptr;
    //}
    void addToHead(std::string); //add node to head
    void addToTail(std::string); //add node to tail
    std::string  deleteFromHead(); // delete the head and return its info;
    std::string  deleteFromTail(); // delete the tail and return its info;
    void deleteNode(std::string); //search and delete node
    //bool isInList(std::string);
    void printAll(); //print all

};


class Double {
public:
    Double* next;
    Double* prev{};//declare previous pointer
    std::string info;
    Double(){
        info = "NULL";
        next = nullptr;
    }
    explicit Double(std::string store, Double *ptr = nullptr,Double *ptr2 = nullptr){
        this->info = std::move(store);
        this->next = ptr;
        this->prev = ptr2;
    }

};

class Double_List {
    Double* head;
    Double* tail;
public:
    Double_List() {

        head = tail= nullptr;
    }
    //~Single_List();
    //static int isEmpty() {
    //    return head == nullptr;
    //}
    void addToHead(std::string); //all functions are the same as in single_linked list
    void addToTail(std::string);
    std::string  deleteFromHead();
    std::string  deleteFromTail();
    void deleteNode(std::string);
    //bool isInList(std::string);
    void printAll();

};

/*
class Double {
public:
    Double *next;
    std::string info;
    Double(){
        next = nullptr;
    }
    explicit Double(std::string store, Double *ptr = nullptr){
        info = std::move(store); next = ptr;
    }


};

class Double_List {
public:
    Double_List() {
        head = tail = nullptr;
    }
    ~Double_List();
    int isEmpty() {
        return head == nullptr;
    }
    static void addToHead(std::string);
    void addToTail(std::string);
    std::string  deleteFromHead(); // delete the head and return its info;
    std::string  deleteFromTail(); // delete the tail and return its info;
    void deleteNode(std::string);
    bool isInList(std::string) const;
    void printAll() const;
private:
    static Double *head;
    static Double *tail;
};
*/
//static Single_List SL;
Single_List SL; //declare singly and doubly linked list
Double_List DL;
void output_menu(){ //print menu
    std::cout.width(25);
    std::cout<<"MENU"<<std::endl<<std::endl<<"SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)"<<std::endl;
    std::cout<<"DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)"<<std::endl<<"Exit Program (12)"<<std::endl<<"Choose?";


}

std::string decision(const std::string& user_input){ //method to make decisions based off input string
    
    std::string key; //return key used for exit
    std::string del = " ";//parameter to use
    std::stringstream ss(user_input);
    std::string word;
    std::vector<std::string> wordlist{};//command vector
/*
while (!ss.eof()) {
    
    getline(ss, word, del);
    std::cout << word << std::endl;
}
*/

    while (ss >> word) {//splits string by space
            //std::cout << word << std::endl;

            wordlist.push_back(word);//puts the individual strings into a vector
            if(wordlist.size()>2){//if there is are 3 detected inputs then return error
                std::cout<<"Input has too many parameters. Please try again."<<std::endl;
                //wordlist.empty();
                return key;
                //break;
            }
        }
    //checks if the first input matches the command number and is a valid input
    if((wordlist.at(0) == ("0")||
    wordlist.at(0) == ("1")||
    wordlist.at(0) == ("4")||
    wordlist.at(0) == ("6")||
    wordlist.at(0) == ("7")||
    wordlist.at(0) == ("10"))&&
    wordlist.size()!=2){
       std::cout<<"No input parameter"<<std::endl;
       return key;
    }
    else if ((wordlist.at(0) == ("2")||
             wordlist.at(0) == ("3")||
             wordlist.at(0) == ("5")||
             wordlist.at(0) == ("8")||
             wordlist.at(0) == ("9")||
             wordlist.at(0) == ("11"))&&
            wordlist.size()!=1){
        std::cout<<"too many inputs"<<std::endl;
        return key;

    }
    //honestly I dislike how inefficient this is, but it is the best I got with the libraries and functions I could find that works in all standard cases.
    //if the word list has two inputs then check if the second input is a char or an int
    if(wordlist.size() == 2){
        if(wordlist.at(1).size() > 1){
            for(char i : wordlist.at(1)){
                if(!std::isdigit(i)){
                    std::cout<<"input is not a int or char"<<std::endl;
                    return key;
                }
            }

        }
        else if(!(std::isalpha(wordlist.at(1).at(0))||std::isdigit(wordlist.at(1).at(0)))){
            std::cout<<"input is not a int or char"<<std::endl;
            return key;
        }

    }

    /*
    size_t pos = 0;
    while ((pos = word.find(del)) != std::string::npos) {
        wordlist.push_back(word.substr(0, pos));
        word.erase(0, pos + del.length());
    }
     */
    //std::cout<<wordlist.at(0)<<std::endl;
    //std::cout<<wordlist.at(1)<<std::endl;

    //based on first input decide what to do.
    if(wordlist.at(0) == "0"){
        //addToHead();
        //Single_List::addToHead(wordlist.at(1));
        SL.addToHead(wordlist.at(1)); //add input to head
    }

    else if(wordlist.at(0) == "1"){
        SL.addToTail(wordlist.at(1));//add input to tail
    }

    else if(wordlist.at(0) == "2"){
        SL.deleteFromHead();//delete from head
    }
    else if(wordlist.at(0) == "3"){
        SL.deleteFromTail();//delete from tail
    }
    else if(wordlist.at(0) == "4"){
        SL.deleteNode(wordlist.at(1));//search and delete

    }
    else if(wordlist.at(0) == "5"){
        SL.printAll();//print out
        //Single_List::printAll();
    }
    //repeat for doubly linked list
    else if(wordlist.at(0) == "6"){
        //Double_List::addToHead(wordlist.at(1));
        DL.addToHead(wordlist.at(1));
    }
    else if(wordlist.at(0) == "7"){
        DL.addToTail(wordlist.at(1));
    }
    else if(wordlist.at(0) == "8"){
        DL.deleteFromHead();

    }
    else if(wordlist.at(0) == "9"){
        DL.deleteFromTail();
    }
    else if(wordlist.at(0) == "10"){
        DL.deleteNode(wordlist.at(1));

    }
    else if(wordlist.at(0) == "11"){
        DL.printAll();
    }
    else if(wordlist.at(0) == "12"){
        //std::cout<<wordlist.at(0)<<std::endl;
        key = "exit"; //pass exit code

    }
    else{
        std::cout<<"Invalid command please try again"<<std::endl; //wrong first input
    }




    return key;
}
/*
Single_List::~Single_List() {
    for (Single *p; !isEmpty(); ) {
        p = head->next;
        delete head;
        head =p;
    }
}

Double_List::~Double_List() {
    for (Double *p; !isEmpty(); ) {
        p = head->next;
        delete head;
        head = p;
    }
}

*/
void Single_List::addToHead(std::string data) {
    auto* Node_Temp = new Single(std::move(data), head); //make a new node temp with the next pointer pointing towards current head
    head = Node_Temp; //set head equal to node temp
            //head = new Single(std::move(data), head);
    if (tail == nullptr)
        tail = head;//if tail is null set equal to head
}

void Single_List::addToTail(std::string data) {
    if(tail != nullptr){ //if tail exists then the current tail next equals a new node
        tail->next = new Single(data);
        tail = tail->next; // tail equals the next node
    }
    else head = tail = new Single(data); //if tail is null then set head and tail equal to a new node


}
std::string Single_List::deleteFromHead() {
    std::string data = head->info; //store head pointer info
    Single* tmp = head; // make a pointer at head
    if (head==tail){
        head = tail =nullptr;
    }
    else{
        head = head->next;//make next node new head
    }
    delete tmp; //delete head node
    return data;//return head data

}
std::string Single_List::deleteFromTail() {
    std::string data = tail->info;
    if (head == tail) {   // if only one node on the list;
        delete head;
        head = tail = nullptr;
    }
    else {                // if more than one node in the list,
        Single *tmp; // find the predecessor of tail;
        for (tmp = head; tmp->next != tail; tmp = tmp->next);
        delete tail;
        tail = tmp;      // the predecessor of tail becomes tail;
        tail->next = nullptr;
    }
    return data;
}

void Single_List::deleteNode(std::string data) {
    if (head != nullptr)                     // if non-empty list;
        if (head == tail && data == head->info) { // if only one
            delete head;                       // node on the list;
            head = tail = nullptr;
        }
        else if (data == head->info) {  // if more than one node on the list
            Single* tmp = head;
            head = head->next;
            delete tmp;              // and old head is deleted;
        }
        else {                        // if more than one node in the list
            Single* prev;
            Single* tmp;
            for (prev = head, tmp = head->next; // and a non-head node
                 tmp != nullptr && !(tmp->info == data);// is deleted;
                 prev = prev->next, tmp = tmp->next);
            if (tmp != nullptr) {
                prev->next = tmp->next;
                if (tmp == tail)
                    tail = prev;
                delete tmp;
            }
        }
}



void Single_List::printAll() {
    for (Single* tmp = head; tmp != nullptr; tmp = tmp->next)
        std::cout << tmp->info << " "; //print out current node info
    std::cout << std::endl;
}
//most functions operate similarly if not the same will only mark diffrences
void Double_List::addToHead(std::string data) {
    auto* Node_Temp = new Double(std::move(data), head, nullptr);
    if(head != nullptr) {
        head->prev = Node_Temp;

    }
    head = Node_Temp;
    //head = new Single(std::move(data), head);
    if (tail == nullptr)
        tail = head;

}

void Double_List::addToTail(std::string data) {
    if(tail != nullptr){
        tail->next = new Double(data, nullptr,tail); //set previous pointer to current tail.
        tail = tail->next;
    }
    else head = tail = new Double (data);


}

std::string Double_List::deleteFromHead() {
    std::string data = head->info;
    Double* tmp = head;
    if (head==tail){
        head = tail =nullptr;
    }
    else{
        head = head->next;
        head->prev = nullptr; //remove previous pointer from head node
    }
    delete tmp;
    return data;

}
std::string Double_List::deleteFromTail() {
    std::string data = tail->info;
    if (head == tail) {   // if only one node on the list;
        delete head;
        head = tail = nullptr;
    }
    else {                // if more than one node in the list,
        //Double *tmp; // find the predecessor of tail;
        //for (tmp = tail; tmp->prev != tail; tmp = tmp->prev);
        tail = tail->prev; // use tail previous pointer instead of using a for loop

        delete tail->next;
        //tail = tmp;      // the predecessor of tail becomes tail;
        tail->next = nullptr;
    }
    return data;
}

void Double_List::deleteNode(std::string data) {
    if (head != nullptr)                     // if non-empty list;
        if (head == tail && data == head->info) { // if only one
            delete head;                       // node on the list;
            head = tail = nullptr;
        }
        else if (data == head->info) {  // if more than one node on the list
            Double* tmp = head;
            head = head->next;
            head->prev = nullptr;
            delete tmp; // and old head is deleted;

        }
        else {                        // if more than one node in the list
            //Double* prev;
            //std::cout<<"Deleting not head"<<std::endl;
            Double* tmp;
            //std::cout<<"making varible"<<std::endl;
            for(tmp=head->next;
                tmp!=nullptr&&!(tmp->info==data);
                tmp = tmp->next){}
             //std::cout<<tmp->info<<std::endl;
                /*
            for (prev = head, tmp = head->next; // and a non-head node
                 tmp != 0 && !(tmp->info == data);// is deleted;
                 prev = prev->next, tmp = tmp->next);
                 */
            if (tmp != nullptr) {
                //Double* del=tmp;
                //tmp->prev->next = tmp->next;
                //if(tmp = del->next){
               //     tmp->prev = del->prev;
                //}


                if (tmp == tail) {
                    tail = tmp->prev;
                    tail->next = nullptr;
                }
                else{ //if not tail
                    tmp->prev->next = tmp->next;//change the previous nodes next to tmp next
                    tmp->next->prev = tmp->prev;//change next nodes previous to tmp previous
                }
                delete tmp;
            }
        }
}



void Double_List::printAll() {
    for (Double* tmp = head; tmp != nullptr; tmp = tmp->next)
        std::cout << tmp->info << " ";
    std::cout << std::endl;
}




/*
bool Single_List::isInList(std::string data) {
    IntSLLNode *tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return tmp != 0;
}
 */
/*
void Double_List::addToHead(std::string data) {
    head = new Double(data,head);
    if (tail == nullptr)
        tail = head;

}


void Single_List::printAll() {
    for (Single *tmp = head; tmp != nullptr; tmp = tmp->next)
        std::cout << tmp->info << " ";
    std::cout << std::endl;
}

*/


int main(){
    //Double_List DL;
    std::string exit = "go";

    while(exit != "exit"){//if exit is caught then stop loop
        output_menu();
        std::string u_input;
        getline(std::cin,u_input);//get input line
        //std::cout<<"decision"<<std::endl;
        exit = decision(u_input);//decide on output checks if it should exit

}


    std::cout<<"Program finished have a nice day!"<<std::endl;//a friendly message
return 0;

}