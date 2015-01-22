#ifndef MYSTATUS_H_
#define MYSTATUS_H_

class MyStatus {
	std::string name_;
	bool ok_;

	public:
		MyStatus(const std::string& name):name_(name),ok_(true) {}
		void break_it() {
			ok_=false;
		}

		bool is_broken() const {
			return ok_;
		}

		void report() const {
			std::cout << name_ << " is " <<
				(ok_ ? "working nominally":"terribly broken") << '\n';
		}

};

#endif
