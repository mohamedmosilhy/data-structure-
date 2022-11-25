#include<iostream>
using namespace std;
#include"stack"
#include<string>

// bool isValid(string s){
//     stack <char> st;
//     for(auto i : s){
//         if (st.empty())
//         {
//            st.push(i);
//         }
//         else if (i == '[' ||i == '{' ||i == '(')
//         {
//             st.push(i);
//         }
//         else if (i == ']'){ 
//             if (st.top() == '[')
//             {
//                 st.pop();
//             }
//             else
//             break;   
//         } 
//         else if (i == '}'){ 
//             if (st.top() == '{')
//             {
//                 st.pop();
//             }
//             else
//             break;    
//         } 
//         else if (i == ')'){ 
//             if (st.top() == '(')
//             {
//                 st.pop();
//             }
//             else
//             break;    
//         } 
//     }
//     return st.empty();
// }

bool isValid(string s){
    stack <char> st;
    for(auto i : s){
        if (st.empty())
        {
            st.push(i);
        }
        else if(i == '[' ||i == '{' ||i == '('){
            st.push(i);
        }
        else if(i == ']'||i == '}'||i == ')'){
            if ((i == ']' && st.top() == '[') ||(i == '}' && st.top() == '{') ||(i == ')' && st.top() == '('))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}


int main(){

    cout<<isValid("]");

    return 0;
}