/*  
    Use 2 heaps.
    One max heap for storing smaller/lower half elements.
    One min heap for storing larger/upper half elements.
    First element goes to upper half, i.e, min_heap
    At every instance, sizeof(upper) == sizeof(lower) OR sizeof(upper) + 1 == sizeof(lower) 
*/
class MedianFinder {
public:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;
    bool isSizeEqual = true;
    
    void addNum(int num) {
        if(isSizeEqual) {
            lower.push(num);
            upper.push(lower.top());
            lower.pop();
        } else {
            upper.push(num);
            lower.push(upper.top());
            upper.pop();
        }
        isSizeEqual = !isSizeEqual;
    }
    
    double findMedian() {
        if(lower.size() == upper.size()) return (lower.top() + upper.top())/2.0;
        return upper.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
