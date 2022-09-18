// Classical Segment Tree
template <typename T, T (*func) (T, T)>
class SegTree {
    pair<int, int> range;
    T data;
    SegTree *left, *right;
  public:
    SegTree(vector<T> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) { data = A[R.first]; left = right = NULL; }
        else {
            int mid = (R.first + R.second) / 2;
            left = new SegTree(A, {R.first, mid});
            right = new SegTree(A, {mid+1, R.second});
            data = func(left->data, right->data);
        }
    }

    void update(int idx, int val) {
        if(range.first == range.second) {
            data = val;
            return;
        }
        int mid = (range.first + range.second) / 2;
        if(idx > mid) right->update(idx, val);
        else left->update(idx, val);
        data = func(left->data, right->data);
    }

    T query(pair<int, int> R) {
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        return func(left->query({R.first, mid}), right->query({mid+1, R.second}));
    }

    void print() {
        cout<<range.first<<" "<<range.second<<" : "<<data<<endl;
        if(left) left->print();
        if(right) right->print();
    }
};

// MergeSort Tree
template <typename T>
class MergeSortTree {
    pair<int, int> range;
    multiset<T> data;
    MergeSortTree *left, *right;
public:
    MergeSortTree(vector<T> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) {
            data.insert(A[R.first]);
            left = right = NULL;
        }
        else {
            int mid = (R.first + R.second) / 2;
            left = new MergeSortTree(A, {R.first, mid});
            right = new MergeSortTree(A, {mid+1, R.second});
            for(T it : left->data) data.insert(it);
            for(T it : right->data) data.insert(it);
        }
    }

    T query(pair<int, int> R, T x) {
        if(R.first > range.second || R.second < range.first) return INT_MAX;
        if(R.first <= range.first && R.second >= range.second) {
            if(*(--data.end()) < x) return INT_MAX;
            return *data.lower_bound(x);
        }
        return min(left->query(R, x), right->query(R, x));
    }

    void update(int idx, int val) {
        if(range.first == range.second) {
            A[range.first] = val;
            data.clear();
            data.insert(val);
            return;
        }
        data.erase(data.find(A[idx]));
        data.insert(val);
        int mid = (range.first + range.second) / 2;
        if(idx > mid) right->update(idx, val);
        else left->update(idx, val);
    }

    void printTree() {
        cerr<<"{"<<range.first<<" "<<range.second<<"}"<<" : ";
        for(int it : data) cerr<<it<<" ";
        cerr<<endl;
        if(left) left->printTree();
        if(right) right->printTree();
    }
};

// Lazy Segment Tree
class LazySegTree {
    int data, value;
    pair<int, int> range;
    LazySegTree *left, *right;
  public:
    LazySegTree(vector<int> &A, pair<int, int> R) {
        range = R;
        value = 0;
        if(R.first == R.second) { data = A[R.first]; left = right = NULL; }
        else {
            int mid = (R.first + R.second) / 2;
            left = new LazySegTree(A, {R.first, mid});
            right = new LazySegTree(A, {mid+1, R.second});
            data = left->data + right->data;
        }
    }

    void push() {
        if(!value) return;
        if(left) {
            left->data += value * (left->range.second - left->range.first + 1);
            left->value += value;
        }
        if(right) {
            right->data += value * (right->range.second - right->range.first + 1);
            right->value += value;
        }
        value = 0;
    }

    void update(pair<int, int> R, int val) {
        if(range == R) {
            data += val * (range.second - range.first + 1);
            value += val;
            return;
        }
        data += val * (R.second - R.first + 1);
        push();
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) right->update(R, val);
        else if(R.second <= mid) left->update(R, val);
        else {
            left->update({R.first, mid}, val);
            right->update({mid+1, R.second}, val);
        }
    }

    int query(pair<int, int> R) {
        if(range == R) return data;
        push();
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        else return left->query({R.first, mid}) + right->query({mid+1, R.second});
    }

    void print() {
        cout<<range.first<<" "<<range.second<<" : "<<data<<" "<<value<<endl;
        if(left) left->print();
        if(right) right->print();
    }
};

template <typename T>
class LazySegTree {
    T value;
    pair<int, int> range;
    LazySegTree *left, *right;
    public:
    LazySegTree(vector<T> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) {
            value = A[R.first];
            left = right = NULL;
        }
        else {
            int mid = (R.first + R.second) / 2;
            left = new LazySegTree(A, {R.first, mid});
            right = new LazySegTree(A, {mid+1, R.second});
            value = 0;
        }
    }

    void push() {
        if(!value) return;
        if(range.first == range.second) return;
        left->value += value;
        right->value += value;
        value = 0;
    }

    void update(pair<int, int> R, T val) {
        if(range == R) {
            value += val;
            return;
        }
        push();
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) right->update(R, val);
        else if(R.second <= mid) left->update(R, val);
        else {
            left->update({R.first, mid}, val);
            right->update({mid+1, R.second}, val);
        }
    }

    T value_at_index(int idx) {
        if(range.first == range.second) return value;
        push();
        int mid = (range.first + range.second) / 2;
        if(idx > mid) return right->value_at_index(idx);
        else return left->value_at_index(idx);
    }
};

// Different Combiner Functions 
    // -> GCD / LCM
    // -> Min / Max
    // -> Sum / Product

    // Function which stores the maximum and its frequency in the array
    // pii MX_Frequency(pii A, pii B) {
    //     if(A.ff == B.ff) return {A.ff, A.ss + B.ss};
    //     return (A.ff > B.ff) ? A : B;
    // } 

    // Function which stores the max_subsegment_sum over a range
    // template <typename T = int>
    // class Data {
    // public:
    //     T sum, max_psum, max_ssum, max_subseg_sum;
    //     Data(T current_segment_sum=0, T max_prefix_sum=0, T max_suffix_sum=0, T max_subsegment_sum=0) 
    //     {
    //         sum = current_segment_sum;
    //         max_psum = max_prefix_sum;
    //         max_ssum = max_suffix_sum;
    //         max_subseg_sum = max_subsegment_sum;
    //     }
    //     T get_ans() { 
    //         return max_subseg_sum;
    //     }
    // };
    // template <typename T = int>
    // Data<T> func(Data<T> L, Data<T> R) {
    //     Data<T> res;
    //     res.sum = L.sum + R.sum;
    //     res.max_psum = MAX(L.max_psum, L.sum + R.max_psum);
    //     res.max_ssum = MAX(R.max_ssum, R.sum + L.max_ssum);
    //     res.max_subseg_sum = MAX(MAX(L.max_subseg_sum, R.max_subseg_sum), L.max_ssum + R.max_psum);
    //     return res;
    // }

    // Function to find kth zero
    // Function to find the ith element such that the prefix sum is equal to the given value(x)
    // int find_that_element(pii R, int k) {
    //     if(k > data) return -1;
    //     if(range.ff == range.ss) return range.ff;
    //     int mid = (range.ff + range.ss) / 2;
    //     if(R.ff > mid) return right->find_that_element(R, k);
    //     if(R.ss <= mid) return left->find_that_element(R, k);
    //     int l = left->query({R.ff, mid});
    //     if(l >= k) return left->find_that_element({R.ff, mid}, k);
    //     return right->find_that_element({mid + 1, R.ss}, k - l);
    // }

    // Searching for the first element greater than a given amount
    // -> We only need to modify the last statement of the above function
    // --> We do not need to subtract l from k in the last line.