// Ascii overvlow issue. 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{

    string msgAc = "ahmad";
    string cipherText = "";
    string deCipheredText = "";

    int i = 0;
    int j = 1;
    while (j < msgAc.length())
    {
        char a = msgAc[i];
        char b = msgAc[j];
        long long int x = (long long int)(a);
        long long int y = (long long int)(b);
        long long int z = x << y;
        char append = (char)z;
        cipherText += append;
        i++;
        j++;
    }

    cout<<"Ciphered Text is "<<cipherText<<endl;

    int k = cipherText.length() - 1;
    // cout<<k<<endl;
    int l = cipherText.length() - 2;

    while (l >= 0)
    {
        char a = cipherText[k];
        char b = cipherText[l];
        long long int x = (long long int)(a);
        long long int y = (long long int)(b);       
        long long int z = y >> x;
        char append = (char)z;
        deCipheredText += append;
        k--;
        l--;
    }

    cout<<"Deciphered Text is "<<deCipheredText<<endl;

    return 0;
}