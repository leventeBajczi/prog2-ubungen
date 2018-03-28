#ifndef _XOR_HPP
#define _XOR_HPP

using namespace std;
#include <string>

class Xor{
    private:
        string codec;
    public:
        Xor(string& codec){this->codec = codec;}
        string encrypt(string plainText);
        string decrypt(string cipherText);
        static string base64Encode(string cipherText);
        static string base64Decode(string base64Text);
};


#endif