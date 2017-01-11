class MovingAverage {
private:
    queue<int> q;
    int k;
    double sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        k = size;
        sum = 0;
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if(q.size() > k){
            sum -= q.front();
            q.pop();
        }
        return sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */