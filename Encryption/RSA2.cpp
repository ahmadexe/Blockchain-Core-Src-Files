#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// m^e mod n = c
// c^d mod n = m
// encryption key = (n,e)
// decryption key = (d)
// n = p*q
// phi = (p-1)*(q-1)

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int generate_e(int phi)
{
    int e = 2;
    while (gcd(e, phi) != 1)
        e++;
    return e;
}

int generate_d(int e, int phi) {
    int d = 1;
    while (1) {
        int x = (e * d) % phi;
        if (x == 1)
            return d;
        d++;
    }
}

int main(int argc, char const *argv[])
{
    // int p, q, n, phi, d;
    // int e;
    // string msg;
    // cin>>p>>q;
    // n = p*q;
    // phi = (p-1)*(q-1);

    int e = 3;
    int phi = 9328;
    cout<<generate_d(e, phi)<<endl;

    return 0;
}