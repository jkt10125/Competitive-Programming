#define T int
class MinMaxQUEUE {
	vector<pair<T, pair<T, T>>> push_stack, pop_stack;
	void stack_transfer() {
		while(push_stack.size() != 0) {
			T mn, mx;
			mn = mx = push_stack.back().first;
			mn = (pop_stack.size() == 0) ? mn : std::min(mn, pop_stack.back().second.first);
			mx = (pop_stack.size() == 0) ? mx : std::max(mx, pop_stack.back().second.second);
			pop_stack.push_back({push_stack.back().first, {mn, mx}});
			push_stack.pop_back();
		}
	}
public:
	int size() { return (push_stack.size() + pop_stack.size()); }
	bool empty() { return (size() == 0); }

	void push(T val) {
		T mn = (push_stack.size() == 0) ? val : std::min(push_stack.back().second.first, val);
		T mx = (push_stack.size() == 0) ? val : std::max(push_stack.back().second.second, val);
		push_stack.push_back({val, {mn, mx}});
	}

	void pop() {
		if(pop_stack.size() == 0) stack_transfer();
		pop_stack.pop_back();
	}

	T min() {
		if(pop_stack.size() == 0) return push_stack.back().second.first;
		else if(push_stack.size() == 0) return pop_stack.back().second.first;
		return std::min(push_stack.back().second.first, pop_stack.back().second.first);
	}

	T max() {
		if(pop_stack.size() == 0) return push_stack.back().second.second;
		else if(push_stack.size() == 0) return pop_stack.back().second.second;
		return std::max(push_stack.back().second.second, pop_stack.back().second.second);
	}

	T front() {
		if(pop_stack.size() == 0) stack_transfer();
		return pop_stack.back().first;
	}


	friend ostream& operator<<(ostream &os, const MinMaxQUEUE &q) {
		for(int i=q.pop_stack.size()-1; i>0; i--) os << q.pop_stack[i].first << " ";
		if(q.pop_stack.size()) {
			cout << q.pop_stack.front().first;
			if(q.push_stack.size()) os << " ";
		}
		for(int i=0; i<q.push_stack.size(); i++) {
			os << q.push_stack[i].first;
			if(i != q.push_stack.size()-1) os << " ";
		}
		return os;
	}
};