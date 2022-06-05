// Ascii overvlow issue.
/* The following code doesn't work, since after using unsigned long the maximum left/right shift of bits
is 63*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{

    string msgAc = "ahmad";
    int decipherKey = (int)msgAc[msgAc.length() - 1];
    string cipherText = "";
    string deCipheredText = "";
    vector<string> numberedKey;

    int i = 1;
    int j = 2;
    char a = msgAc[0];
    char b = msgAc[1];
    long long int x = (long long int)(a);
    long long int y = (long long int)(b);
    long long int z = x << y;
    string numStr = to_string(z);
    cipherText = cipherText + numStr;
    while (j < msgAc.length())
    {
        char a = msgAc[i];
        char b = msgAc[j];
        long long int x = (long long int)(a);
        long long int y = (long long int)(b);
        long long int z = x << y;
        string numStr = to_string(z);
        numStr = "," + numStr;
        cipherText += numStr;
        i++;
        j++;
    }

    cout << "Ciphered Text is " << cipherText << endl;

    char *ptr = strtok(const_cast<char *>(cipherText.c_str()), ",");
    while (ptr != NULL)
    {
        numberedKey.push_back(ptr);
        ptr = strtok(NULL, ",");
    }
    numberedKey.push_back(to_string(decipherKey));
    int e = numberedKey.size() - 1;
    int q = numberedKey.size() - 2;
    while (q >= 0)
    {
        string a = numberedKey[e];
        string b = numberedKey[q];
        long long int x = atol(b.c_str()) >> atol(a.c_str());
        cout << a << endl;
        cout << b << endl;
        cout << x << endl;
        deCipheredText += (char)x;
        e--;
        q--;
    }

    cout << "Deciphered Text is " << deCipheredText << endl;

    return 0;
}