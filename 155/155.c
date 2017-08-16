class MinStack {
private:
    int min;
    int *buf;
    int len;
    int stack_size;
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
        len = 0;
        stack_size  = 10;
        buf = (int *)malloc(stack_size * sizeof *buf);
    }
    
    void push(int x) {
        if (len >= stack_size) {
            stack_size  *= 2;
            buf = (int *)realloc(buf, stack_size * sizeof *buf);
        }
        if (x < min)
            min = x;
        buf[len]    = x;
        len++;
    }
    
    void pop() {
        len = len ? len-1 : len;
        if (!len) {
            min = INT_MAX;
            return;
        }
        if (buf[len] != min) {
            return;
        }
        min = buf[0];
        for (int i = 1; i < len; i++) {
            if (buf[i] < min) {
                min = buf[i];
            }
        }
    }
    
    int top() {
        return buf[len-1];
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
