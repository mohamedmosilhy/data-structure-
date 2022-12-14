#include "p2.h"
using namespace std;

set<string> word_amalgamation(vector<string> dictionary, string scrambled_word){
    set<string> result;

    set<char> s1;
    set<char> s2;

    // loop on each string in the dictionary and check if this string is equal to the size of scrambled_word
    // if this is true then put the two strings in two sets 
    // check if the elements in the sets are the same 
    // then insert the string from the dictionary in the result 
    for (auto element : dictionary)
    {   
        if (element.size() == scrambled_word.size())
        {   
            int i = 0;
            for (auto ch : scrambled_word)
            {
                s1.insert(ch);
                s2.insert(element[i]);
                i++;
            } 
            if (s1 == s2)
            {
               result.insert(element);
            }
            s1.clear();
            s2.clear();
        }
    }
    return result;
}