#include <iostream>
#include <string>
using namespace std;


// given an integer x, reverse it. return 0 if reversing it causes integer overflow
int reverse(int x) {
    bool overflow = false;
    // we need a safe way to check if an integer overflow occured.
    // how do we know this? if we go from negative to positive, overflow
    // from positive to negative, overflow.
    // how do we know this? 


    // we have original number in x.

    string originalString = to_string(x); // turn it into a string for easy reversal
    string returningString = "";
    int i = 0;
    if(x < 0){
        i = 1;
        returningString += "-";
    }


    bool numberStarted = false;

    for(int x = originalString.length()-1 ; x >= i ; x--){ // start at the back of the string and move toward
        if(numberStarted){
            returningString += originalString[x];
        }
        if(!numberStarted && originalString[x] != 0){ // we havent started the number and its 
            numberStarted = true;
            returningString += originalString[x];
        }
        
    }
    int returningInt = 0;
    try
    {
        returningInt = stoi(returningString);
    }
    catch(const std::exception& e)
    {
        returningInt = 0;
    }

    // checking for overflows
    if((x < 0 && returningInt > 0) || (x > 0 && returningInt < 0)){
        returningInt = 0;
    }
    return returningInt;

}

int main(){
    cout << "hello world" << endl;
    cout << reverse(1534236469) << endl;
}