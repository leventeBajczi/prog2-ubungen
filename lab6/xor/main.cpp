#include "xor.hpp"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
    if(argc < 4){
        cout<<"not enough parameters!" <<endl;
        return 0;
    } 
    if(strcmp(argv[1], "-e") == 0)
    {
        string string1(argv[2]);
        Xor codec1(string1);
        cout<<"Encrypted: "<<codec1.encrypt(argv[3]);  
    }
    else if(strcmp(argv[1], "-d") == 0)
    {
        string string1(argv[2]);
        Xor codec1(string1);
        cout<<"Decrypted: "<<codec1.decrypt(argv[3]);  
    }
    else{
        cout<<"unkown switch "<<argv[1]<<endl;
    }
    

    return 0;
}