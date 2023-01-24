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
		typedef typename std::deque<T>::const_iterator const_iterator;
		const_iterator begin() const { return (data_.begin()); }
		const_iterator end() const { return (data_.end()); }
		void printAllData() const
		{
			for (const_iterator itr = begin(); itr != end(); itr++)
				std::cout << *itr << std::endl;
		}
};

#endif