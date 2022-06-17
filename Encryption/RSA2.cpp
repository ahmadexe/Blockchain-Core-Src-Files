#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// m^e mod n = c
// c^d mod n = m
// encryption key = (n,e)
// decryption key = (d)
// n = p*q
// phi = (p-1)*(q-1)

unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

unsigned long long int generate_e(unsigned long long int phi)
{
    unsigned long long int e = 2;
    int gcdv = 0;
    while (gcdv != 1)
    {
        e++;
        gcdv = gcd(e, phi);
    }
    return e;
}

unsigned long long int generate_d(unsigned long long int e,unsigned long long int phi) {
    unsigned long long int d = 1;
    while (1) {
        unsigned long long int x = (e * d) % phi;
        if (x == 1)
            return d;
        d++;
    }
}

int ModArth(long long int base, long long int exponent, long long int mod) {
    if (mod == 1)
        return 0;
    int c = 1;
    for (int i = 0; i < exponent; i++) {
        c = (c * base) % mod;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    unsigned long long int p, q, n, phi, d;
    unsigned long long int e;
    unsigned long long int msg;

    vector<long long int> v;

    p = 7907;
    q = 7919;
    n = p * q;
    phi = (p - 1) * (q - 1);
    e = generate_e(phi);
    d = generate_d(e, phi);
    string s = "My name is Zuhaib";
    string cipherText = "";
    for (int i = 0; i < s.size(); i++) {
        char m = s[i];
        int c = ModArth(m, e, n);
        v.push_back(c);
        string text = to_string(c);
        cipherText += text;
    }
    srand(time(NULL));
    random_shuffle(cipherText.begin(), cipherText.end());
    cout<<"Cipher Text "<<cipherText<<endl;
    string decryptedText = "";
    for (int i = 0; i < v.size(); i++) {
        int m = ModArth(v[i], d, n);
        char append = (char) m;
        decryptedText += append;
    }
    cout<<"Decrypted text "<<decryptedText<<endl;

    return 0;
}