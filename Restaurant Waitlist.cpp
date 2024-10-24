#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

struct Party {
    string name;
    int size;
    Party(string _name, int _size) : name(_name), size(_size) {}
};

class RestaurantWaitlist {
private:
    list<Party> waitlist;
    unordered_map<string, list<Party>::iterator> nameToParty;

public:
    void joinWaitlist(string name, int size) {
        waitlist.push_back(Party(name, size));
        nameToParty[name] = prev(waitlist.end());
    }

    void leaveWaitlist(string name) {
        auto itr = nameToParty[name];
        waitlist.erase(itr);
        nameToParty.erase(name);
    }

    Party* findParty(int tableSize) {
        for(Party& party : waitlist) {
            if(party.size >= tableSize) 
                return &party;
        }
        return nullptr;
    }

    void displayWaitlist() {
        for(Party& party : waitlist) {
            cout << party.name << endl;
        }
    }
};

int main() {
    return 0;
}
