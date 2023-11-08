#include<bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s){
    stack<char> st;
    for(int i = 0; i<s.length();i++){
        char ch = s[i];
        if(ch=='(' || ch =='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool isRed = true;
                while(st.top()!='('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRed = false;
                    }
                    st.pop();
                }
                if(isRed==true)
                return true;
                st.pop();
            }
        }
    }
    return false;
}