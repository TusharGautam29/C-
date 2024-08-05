#include<iostream>
void hanoi(int n,char a,char b, char c){
    if (n==0) return;
    hanoi(n-1,a,c,b);
    std::cout<<a<<"-->"<<c<<std::endl;
    hanoi(n-1,b,a,c);

}
int main(){
    int n;
    std::cin>>n;
    hanoi(n,'A','B','C');
}