#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Main Question
class Scheduler {
private:
    queue<int> availableCores;
    unordered_map<int, bool> coreToTask;

public:
    Scheduler(int noOfCores) {
        for(int i = 0; i < noOfCores; i++) {
            availableCores.push(i);
            coreToTask[i] = true;
        }
    }

    int assignCores() {
        if(!availableCores.empty()) {
            int core = availableCores.front();
            availableCores.pop();
            coreToTask[core] = false;
            return core;
        }
        return -1;
    }

    void releaseCore(int core) {
        coreToTask[core] = true;
        availableCores.push(core);
    }
};

// Follow Up - 1
class Scheduler {
private:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> availableCores;
    unordered_map<int, int> coreToTask;

public:
    Scheduler(int noOfCores) {
        for(int i = 0; i < noOfCores; i++) {
            availableCores.push({0, i});
            coreToTask[i] = 0;
        }
    }

    int assignCores() {
        if(!availableCores.empty()) {
            auto [_, core] = availableCores.top();
            availableCores.pop();
            return core;
        }
        return -1;
    }

    void releaseCore(int core, int time) {
        coreToTask[core] += time;
        availableCores.push({coreToTask[core], core});
    }
};

int main() {

    return 0;
}
