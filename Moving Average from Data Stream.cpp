// https://www.lintcode.com/problem/moving-average-from-data-stream/description

class MovingAverage {
private:
    queue<int> q;
    double sum;
    int len;
    
public:
    MovingAverage(int size) {
        sum = 0;
        len = size;
    }

    double next(int val) {
        sum += val;
        q.push(val);
        if(q.size() > len){
            sum -= q.front();
            q.pop();
        }
        return sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */
