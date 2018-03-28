#include "xor.hpp"
#include <iostream>
#include "lib/text/libtext.h"
#include <string>
using namespace std;

string Xor::encrypt(string plainText)
{
    int j = 0;
    string cipherText = "";
    for(int i = 0; i<plainText.length(); i++)
    {
        cipherText += plainText[i] ^ this->codec[j];
        j = (j+1)%(this->codec.length());
    }
    return Xor::base64Encode(cipherText);
}
string Xor::decrypt(string cipherText)
{
    int j = 0;
    cipherText = Xor::base64Decode(cipherText);
    string plainText = "";
    for(int i = 0; i<cipherText.length(); i++)
    {
        plainText += cipherText[i] ^ this->codec[j];
        j = (j+1)%(this->codec.length());
    }
    return plainText;
}
string Xor::base64Encode(string cipherText)
{
    string* encoded = new string(encode_base64((uint8_t*)cipherText.c_str(), cipherText.length()));
    return *encoded;

}
string Xor::base64Decode(string base64Text)
{
    string* decoded = new string((char*)decode_base64((char*)base64Text.c_str()));
    return *decoded;
}