

#include <iostream>
#include <string>
#include <iterator>
#include <utility>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

class Single {
public:
    Single* next;
    std::string info;
    Single(){
        info = "NULL";
        next = nullptr;
    }
    Single(std::string store, Single *ptr = nullptr){
        this->info = store;
        this->next = ptr;
    }

};

class Single_List {
    Single* head;
    Single* tail;
public:
    Single_List() {

        head = tail= nullptr;
    }
    //~Single_List();
    //static int isEmpty() {
    //    return head == nullptr;
    //}
    void addToHead(std::string);
    //static void addToTail(std::string);
    //static std::string  deleteFromHead(); // delete the head and return its info;
    //static std::string  deleteFromTail(); // delete the tail and return its info;
    //static void deleteNode(std::string);
    //static bool isInList(std::string);
    //static void printAll();

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
Single_List SL;
void output_menu(){
    std::cout.width(25);
    std::cout<<"MENU"<<std::endl<<std::endl<<"SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)"<<std::endl;
    std::cout<<"DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)"<<std::endl<<"Exit Program (12)"<<std::endl<<"Choose?";


}

std::string decision(const std::string& user_input){
    
    std::string key;
    std::string del = " ";
    std::stringstream ss(user_input);
    std::string word;
    std::vector<std::string> wordlist{};
/*
while (!ss.eof()) {
    
    getline(ss, word, del);
    std::cout << word << std::endl;
}
*/

    while (ss >> word) {
            //std::cout << word << std::endl;

            wordlist.push_back(word);
            if(wordlist.size()>2){
                std::cout<<"Input has too many parameters. Please try again."<<std::endl;
                wordlist.empty();
                break;
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

    if(wordlist.at(0) == "0"){
        //addToHead();
        //Single_List::addToHead(wordlist.at(1));
        SL.addToHead(wordlist.at(1));
    }

    if(wordlist.at(0) == "1"){

    }

    if(wordlist.at(0) == "2"){

    }
    if(wordlist.at(0) == "3"){

    }
    if(wordlist.at(0) == "4"){

    }
    if(wordlist.at(0) == "5"){
        //Single_List::printAll();
    }
    if(wordlist.at(0) == "6"){
        //Double_List::addToHead(wordlist.at(1));
    }
    if(wordlist.at(0) == "7"){

    }
    if(wordlist.at(0) == "8"){

    }
    if(wordlist.at(0) == "9"){

    }
    if(wordlist.at(0) == "10"){

    }
    if(wordlist.at(0) == "11"){

    }
    if(wordlist.at(0) == "12"){
        //std::cout<<wordlist.at(0)<<std::endl;
        key = "exit";

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
    Single* Node_Temp = new Single(std::move(data), head);
    head = Node_Temp;
            //head = new Single(std::move(data), head);
    if (tail == nullptr)
        tail = head;
}

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


    //testing

    // Inserting nodes





    //Double_List DL;
    std::string exit = "go";

    while(exit != "exit"){
        output_menu();
        std::string u_input;
        getline(std::cin,u_input);
        //std::cout<<"decision"<<std::endl;
        exit = decision(u_input);

}


    std::cout<<"Program finished have a nice day!"<<std::endl;
return 0;

}