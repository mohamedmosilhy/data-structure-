#include "p1.h"

bool ransom_note(string ransomNote, string magazine){
    bool result = false;

    map <char,int> magazine_map;

    //fill the map
    for (auto ch : magazine)
    {
      magazine_map[ch]++;
    }

    // loop on the ransomNote characters and check if this char is not in the keys of the magazine_map or its value = 0
    // if this valid returns false but if it is not valid take another element form ransomNote and repeat the process
    for (auto element : ransomNote)
    {
        if(!magazine_map[element]--){
            return result;
        }  
    }
    return !result;
}
