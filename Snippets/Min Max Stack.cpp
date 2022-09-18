#define T int
class MinMaxSTACK {
	vector<pair<T, pair<T, T>>> stack;
public:
	int size() { return stack.size(); }
	bool empty() { return (size() == 0); }
	
	void push(T val) {
		T mn = (size()) ? std::min(stack.back().second.first, val) : val;
		T mx = (size()) ? std::max(stack.back().second.second, val) : val;
		stack.push_back({val, {mn, mx}}); 
	}
	void pop() { stack.pop_back(); }
	T max() { return stack.back().second.second; }
	T min() { return stack.back().second.first; }
	T top() { return stack.back().first; }

	friend ostream& operator<<(ostream &os, const MinMaxSTACK &v) {
		for(auto it=v.stack.begin(); it!=v.stack.end(); it++) {
			os << it->first;
			if(it != --v.stack.end()) os << " ";
		}
		return os;
	}
};