#include <iostream>
using namespace std;


string convert(string s, int numRows){
    // iterate by the offset and create a new string out of it
    // what is the offset?
    // n + (n-2) is the offset where n is numrows?
    // at n <= 2 there are no center pieces right?

    int centerRows = 0;
    int offset = 0;
    if(numRows > 2){
        centerRows = numRows - 2; // the # of rows in the middle
        offset = 2*numRows - 2; // the # of character offset between each character in each collumn
    }
    else{
        if(numRows == 2){
            offset = 2; // case 2 rows
        }
        else{
            offset = 1; // case 1 row
        }
        centerRows = 0; // no "in between" rows for these cases
    }


    // iterate row by row
    string builtString = "";
    bool shouldEnd = false;
    for(int row = 0; row < numRows; row++){ // we go row by row
        int position = row;
        if(position != 0 && position != numRows-1){ // 0th row and last row have no inbetween collumns
            int betweenPos = offset - position;
            while(position < s.length()){ // while we haven't overstepped boundary
                builtString += s[position]; // add the row
                if(position == s.length()-1){ // checking if we are at the last one
                    break; // we are at the end, break and end
                }

            

                if(betweenPos < s.length()){ // checking if a "in between" collumn exists
                    builtString += s[betweenPos];

                    if(betweenPos == s.length()-1){
                        break;
                    }
                }
                position += offset;
                betweenPos += offset;
            }
        }
        else{ // else this row has no inbetween collumns, just add the rows
            while(position < s.length()){
                builtString += s[position]; // this occurs at the last and first rows
                position += offset; //
            }
        }


    }

    




    return builtString;
}


int main(){
    cout << "Hello world" << endl;
    cout << convert("AB",2) << endl;
}