#include<iostream>
using namespace std;


int oddsum(int a, int b){
    if (a>b)return 0;
    if (a%2==0) a++;
    if(b%2==0) b--;
    return a + oddsum(a+2,b);
}
int main() {
    int x, y; // Declare variables x and y
    cout << "Enter two integers: ";
    cin >> x >> y; // Input values for x and y
    int sum = oddsum(x, y); // Calculate the sum of odd numbers
    cout << "Sum of odd numbers between " << x << " and " << y << " is: " << sum << endl;
    return 0;
}
