#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{	
	private:
		std::deque<T> data_;
	public:
		MutantStack() {}
		MutantStack(const MutantStack &mutantStack) {
			*this = mutantStack; }
		~MutantStack() {}
		MutantStack &operator=(const MutantStack &mutantStack) {
			if (this != &mutantStack) {
				data_ = mutantStack.data_; }
			return (*this);
		}
		T &top() { return (data_.front()); }
		const T &top() const { return (data_.front()); }
		bool empty() const { return (data_.empty()); }
		size_t size() const { return (data_.size()); }
		void push(const T& value) { data_.push_front(value);	}
		void pop() { data_.pop_front(); }
		typedef typename std::deque<T>::iterator iterator;
		iterator begin() { return (data_.begin()); }
		iterator end() { return (data_.end()); }
};

template <typename T>
void printAll(MutantStack<T> mstack)
{
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

#endif