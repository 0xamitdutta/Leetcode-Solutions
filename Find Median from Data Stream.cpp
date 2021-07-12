/*  
    Use 2 heaps.
    One max heap for storing smaller half elements.
    Another min heap for storing larger half elements.
*/
class MedianFinder {
private:
    priority_queue<int> small; // smaleer half which is a max_heap
    priority_queue<int, vector<int>, greater<int>> large; // larger half which is a min_heap
    bool even = true;
public:
    void addNum(int num) { // O(logn)
        if(even) {
            large.push(num);
            small.push(large.top());
            large.pop();
        }
        else {
            small.push(num);
            large.push(small.top());
            small.pop();
        }
        even = !even;
    }
    
    double findMedian() { // O(1)
        if(even) 
            return (small.top() + large.top()) / 2.0;
        return small.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
