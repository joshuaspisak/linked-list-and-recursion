/******************************************************
** Program: recursion.cpp
** Author: Joshua Spisak
** Date: 3/20/2023
** Description: implements recursive pattern function that creates fractals
** Input: number of stars on each side of cross and number of leading spaces -- two ints
** Output: Fractal pattern as specified
******************************************************/

#include <iostream>

using namespace std;

void pattern(int n, int col){
    for (int i = 0; i < col; i++){
        cout << " ";
    }
    cout << "*";
    for (int i = 0; i < 2*n-1; i++){
        cout << " ";
    }
    cout << "*" << endl;
    if(n > 1){
        pattern(n-1, col+1); // recursive call for other side of cross; completion
    }
    else{
        for (int i = 0; i < col+1; i++){
            cout << " ";
        }
        cout << "*" << endl;
    }
    for (int i = 0; i < col; i++){
        cout << " ";
    }
    cout << "*";
    for (int i = 0; i < 2*n-1; i++){
        cout << " ";
    }
    cout << "*" << endl;
}


int main(){
    cout << "Enter the amount of stars on each side: ";
    int stars;
    cin >> stars;
    cout << "Enter the amount of leading white spaces: ";
    int spaces;
    cin >> spaces;
    pattern(stars, spaces);
    return 0;
}