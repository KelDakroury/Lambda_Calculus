#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include "stack"

using namespace std;
ifstream inFile;
ofstream txtOut;

//checking if it is alphabet
bool isTerminal(const string& s) {
    if (s.length() == 0) return false;
    for(char i : s) {
        if (!isalnum(i)) return false;
    }
    return true;
}

int occurences(const string& s1, const string& s2) {
    int count = 0;
    int pos = 0;
    while ((pos = s1.find(s2, pos)) != string::npos) {
        pos++;
        count++;
    }
    return count;
}


// Balancing
int balance (const string& s){
    stack <char> check;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') {check.push('('); }
        else if (s[i] == ')') {check.pop();}
        if (check.empty()){return i; }
    }
    return -1;
}

//checking the starts
bool isLambda(const string& s) {
    if (isTerminal(s)) return true;
    else if (s[0] == '\\') {
        int first = s.find_first_of('.');
        if (first == string::npos) return false;
        string Ft =  s.substr(1 , first - 1);
        string St =  s.substr(first + 1);
        return isTerminal(Ft) && isLambda(St);
    }
    else if (s[0] == '('){
        int last = balance(s);
        if (last == -1) return false;
        string Ft =  s.substr(1 , last - 1);
        string St =  s.substr(last + 1);
        return isLambda(Ft) && isLambda(St);
    }
    return false;
}

int main() {
    //input
    inFile.open("input.txt");
    txtOut.open("output.txt");
    //.....................................
    string x;
    inFile>>x;
    if(!isLambda(x)) {txtOut << "NO"<<endl;}
    else txtOut << "YES" << endl << occurences(x, "(\\") << endl;


}