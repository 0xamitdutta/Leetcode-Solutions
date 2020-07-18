class MedianFinder {
public:
    /* Use 2 heaps.
    One max heap for storing smaller half elements.
    Another min heap for storing larger half elements.
    */
    priority_queue<long> small, large; // long is used cuz problem will arise when we try to negate -2^31. Range of int is (-2^31 to 2^31 - 1)
    MedianFinder() {
    }
    
    void addNum(int num) {
        // Pay attention xD
        small.push(num);
        large.push(-small.top()); // Min heap is made by negating the integers
        small.pop();
        if(small.size() < large.size()){
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        // If odd elements return top of small else return mean of top of small and top of large
        return small.size() > large.size() ? small.top() : (small.top()-large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
