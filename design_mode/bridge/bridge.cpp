#include <iostream>
#include <string>

using namespace std;

class Os {
	public: 
		virtual void Install_Os_Impl() {}
};

class LinuxOs : public Os {
	public:
		void Install_Os_Impl() {cout << "Install Linux Os" << endl;}
};

class WindowOs : public Os {
	public:
		void Install_Os_Impl() {cout << "Install Window Os" << endl;}
};

class Computer {
	public:
		virtual void Install_Os(Os *os) {}
};

class Lenovo_Computer : public Computer {
	public:
		void Install_Os(Os * os) { os->Install_Os_Impl(); }
};

class Dell_Computer : public Computer {
	public:
		void Install_Os(Os * os) { os->Install_Os_Impl(); }
};

int main() {
	Os *os1 = new LinuxOs();
	Os *os2 = new WindowOs();

	Computer *comp1, *comp2;

	comp1 = new Lenovo_Computer();
	comp2 = new Dell_Computer();	
	
	comp1->Install_Os(os1);
	comp1->Install_Os(os2);

	comp2->Install_Os(os2);
	comp2->Install_Os(os1);

	return 0;
}
