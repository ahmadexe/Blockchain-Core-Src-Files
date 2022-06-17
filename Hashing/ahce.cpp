#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{

    int n = 31;
    int m = 15;

    string text = "My name is Ahmad";
    string hash = "";
    int i = 0;
    int j = 1;
    while ( j < text.size())
    {
        int a = (int) text[i];
        int b = (int) text[j];
        a = a % n;
        b = b % m;
        int c = a << b;
        hash += to_string(c);
        i++;
        j++;
    }

    cout << hash << endl;

    return 0;
}