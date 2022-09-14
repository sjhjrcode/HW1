

#include <iostream>
#include "intSLList.h"
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

class Single {
public:
    Single *next;
    std::string info;
    Single(){
        next = 0;
    }
    Single(std::string store, Single *ptr = 0){
        info = store; next = ptr;
    }
    /*
    IntSLLNode() {
        next = 0;
    }
    IntSLLNode(int el, IntSLLNode *ptr = 0) {
        info = el; next = ptr;
    }
    int info;
    IntSLLNode *next;
     */
};

class Double {
public:

    /*
    IntSLLNode() {
        next = 0;
    }
    IntSLLNode(int el, IntSLLNode *ptr = 0) {
        info = el; next = ptr;
    }
    int info;
    IntSLLNode *next;
     */
};
class Single_List {
public:
    Single_List() {
        head = tail = 0;
    }
    ~Single_List();
    int isEmpty() {
        return head == 0;
    }
    void addToHead(int);
    void addToTail(int);
    int  deleteFromHead(); // delete the head and return its info;
    int  deleteFromTail(); // delete the tail and return its info;
    void deleteNode(int);
    bool isInList(int) const;
    void printAll() const;
private:
    IntSLLNode *head, *tail;
};
class Double_List {
public:
    Double_List() {
        head = tail = 0;
    }
    ~Double_List();
    int isEmpty() {
        return head == 0;
    }
    void addToHead(int);
    void addToTail(int);
    int  deleteFromHead(); // delete the head and return its info;
    int  deleteFromTail(); // delete the tail and return its info;
    void deleteNode(int);
    bool isInList(int) const;
    void printAll() const;
private:
    IntSLLNode *head, *tail;
};


void output_menu(){
    std::cout.width(25);
    std::cout<<"MENU"<<std::endl<<std::endl<<"SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)"<<std::endl;
    std::cout<<"DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)"<<std::endl<<"Exit Program (12)"<<std::endl<<"Choose?";


}

std::string decision(std::string user_input){
    
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
            std::cout << word << std::endl;

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

    }
    if(wordlist.at(0) == "6"){

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
        std::cout<<wordlist.at(0)<<std::endl;
        key = "exit";

    }




    return key;
}

Single_List::~Single_List() {
    for (IntSLLNode *p; !isEmpty(); ) {
        p = head->next;
        delete head;
        head = p;
    }
}





int main(){
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