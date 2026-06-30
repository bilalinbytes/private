class MyQueue {
public:
    stack<int> s;

    MyQueue() {
    }

    void push(int x) {
        if (s.empty()) {
            s.push(x);
            return;
        }

        int temp = s.top();
        s.pop();

        push(x);

        s.push(temp);
    }

    int pop() {
        int x = s.top();
        s.pop();
        return x;
    }

    int peek() {
        return s.top();
    }

    bool empty() {
        return s.empty();
    }
};