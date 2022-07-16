// 5   3   4   2   6
// 5   4   4  3.5  4

// 

class MedianFinder {
public:
    priority_queue<double, vector<double>, greater<double>>mn;
    priority_queue<double>mx;
    int sz1, sz2;
    
    MedianFinder() {
        sz1 = 0;
        sz2 = 0;
    }
    
    void addNum(int num) {
        if(sz1 == 0)
        {
            mx.push(num);
            sz1++;
        }
        else if(sz1 == sz2)
        {
            if(num < mx.top())
            {
                mx.push(num);
                sz1++;
            }
            else if(num > mn.top())
            {
                int x = mn.top();
                mn.pop();
                mn.push(num);
                
                mx.push(x);
                sz1++;
            }
            else
            {
                mx.push(num);
                sz1++;
            }
        }
        else
        {
            if(mx.top() < num)
            {
                mn.push(num);
                sz2++;
            }
            else if(mx.top() > num)
            {
                int x = mx.top();
                mx.pop();
                mx.push(num);
                
                mn.push(x);
                sz2++;
            }
            else
            {
                mn.push(num);
                sz2++;
            }
        }
    }
    
    double findMedian() {
        if(sz1 == sz2 + 1)
        {
            double ans = mx.top();
            return ans;
        }
        else
        {
            double ans = (mx.top() + mn.top())/2;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */