#include <iostream>

using namespace std;


string longestPalindrome(string s) {
    int max = 0;
    string maxSubString = "";
    int maxStart = 0;
    // char array
    int **palArr = new int*[s.length()];
    
    for(int i = 0; i < s.length(); i++){ // creating our dynamic array
        palArr[i] = new int[s.length()];
    }
    
    for(int i = 0; i < s.length(); i++){
        palArr[i][i] = 1; // filling base 1 letter palindromes
        if(max < 1){
            max = 1;
            maxStart = i;
        }
    }


    for(int i = 0; i < s.length()-1; i++){ // filling base 2 letter palindromes
        if(s[i] == s[i+1]){
            palArr[i][i+1] = 2;
            if(max < 2){
                max = 2;
                maxStart = i;
            }
        }
        else{
            palArr[i][i+1] = 0;
        }
    }


    

    // final deciding loop


    for(int j = 2; j < s.length() ; j++){
        int x = 0;
        for(int i = 0; i < s.length() - j; i++){
            if(palArr[i+1][j+i-1] > 0 && s[i] == s[i+j]){ // our palindrome is made up of a palindrome AND is enclosed by the same characters 
                palArr[i][j+i] = palArr[i+1][i+j-1] + 2; // doing a little bit of adding
                if(max <= palArr[i][j+i]){
                    max = palArr[i][j+i];
                    maxStart = i;
                }
            }
            else{
                palArr[i][j+i] = 0; // cannot be a palindrome
            }
        }
    }
    
    if(max > 0){
        maxSubString = s.substr(maxStart,max);
    }
    else{
        maxSubString = "";
    }

    return maxSubString;
   
}


int main(){

    std :: cout << longestPalindrome("0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    ) << std::endl;
}



