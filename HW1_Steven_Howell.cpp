

#include <iostream>
#include "intSLList.h"
#include <string>
#include <iterator>
#include <vector>

#include <bits/stdc++.h>

void output_menu(){
    std::cout.width(25);
    std::cout<<"MENU"<<std::endl<<std::endl<<"SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)"<<std::endl;
    std::cout<<"DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)"<<std::endl<<"Exit Program (12)"<<std::endl<<"Choose? ";


}

std::string decision(std::string user_input){
    
    std::string key;
    char del = ' ';
    std::stringstream ss(user_input);
    std::string word;
/*
while (!ss.eof()) {
    
    getline(ss, word, del);
    std::cout << word << std::endl;
}
*/

    while (ss >> word) {
            std::cout << word << std::endl;
        }

    return key;
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
return 0;

}