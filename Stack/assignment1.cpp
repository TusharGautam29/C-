//Q1. [2]
//Q3 Print binary representation of n
//Q4. 3,4
void removeelement(stack<int> &a,int k){
    stack<int> b;
    for(int i=0;i<k;i++){ 
        b.push(a.top());
        a.pop();
    }
    a.pop();
    while(!b.empty()){
        a.push(b.top());
        b.pop();
    }
    return;
};