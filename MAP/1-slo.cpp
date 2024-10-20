#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> words;

void add_word(string w){
    if(w.size() == n){
        words.push_back(w);
        return;
    }else if(w.size() > n){
        return;
    }
    if(w.back() == 'a'){
        add_word(w + "b");
        add_word(w + "c");
    }
    if(w.back() == 'b'){
        add_word(w + "a");
        add_word(w + "c");
    }
    if(w.back() == 'c'){
        add_word(w + "a");
        add_word(w + "b");
    }
}

int main(){
    cin >> n;

    add_word("a");
    add_word("b");
    add_word("c");
    
    cout << words.size() << "\n";
    for(string w : words){
        cout << w << "\n";
    }
    
    return 0;
}
