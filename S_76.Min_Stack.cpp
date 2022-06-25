class MinStack {
    stack<long> st;
    long minEle;

public:
    MinStack() {
        minEle = INT_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            minEle = val;
            st.push(val);
            return;
        }
        if (val < minEle) {
            st.push((long long )2 * val - minEle);
            minEle = val;
        } else
            st.push(val);
    }

    void pop() {
        if (st.top() < minEle) {
            minEle = (long long )2 * minEle - st.top();
        }
        st.pop();
        if (st.empty()) {
            minEle = INT_MAX;
        }
    }

    int top() {
        if (st.top() < minEle) {
            return minEle;
        }
        return st.top();
    }

    int getMin() {
        return minEle;
    }
};
