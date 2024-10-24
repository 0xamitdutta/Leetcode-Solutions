#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct Fizzbuzz {
    string type;
    string name;
    int quantity;
};

void matchFizzbuzz(vector<Fizzbuzz>& fb) {
    queue<Fizzbuzz> fizz, buzz;
    unordered_map<string, int> matches;
    for(Fizzbuzz& f : fb) {
        if(f.type == "Fizz")
            fizz.push(f);
        else
            buzz.push(f);
    }
    while(!fizz.empty() && !buzz.empty()) {
        Fizzbuzz f = fizz.front(), b = buzz.front();
        fizz.pop(), buzz.pop();
        matches[f.name + ":" + b.name] += min(f.quantity, b.quantity);
        if(f.quantity > b.quantity)
            fizz.push({f.type, f.name, f.quantity - b.quantity});
        else if(f.quantity < b.quantity)
            buzz.push({b.type, b.name, b.quantity - f.quantity});
    }
    for(auto& [key, val] : matches) {
        cout << "FizzBuzz! " << val << " " << key << endl;
    }
}

int main() {
    vector<Fizzbuzz> fb = {
        {"Fizz", "Alice", 5},
        {"Buzz", "Bob", 3},
        {"Buzz", "Catherine", 4},
        {"Fizz", "Alice", 4},
        {"Buzz", "Bob", 2}
    };
    matchFizzbuzz(fb);
    return 0;
}
