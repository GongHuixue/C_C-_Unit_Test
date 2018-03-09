#include <iostream>
#include <string>

using namespace std;

/*
**The constructor is private;
**Only one static m_pInstance, 
**get the instance by public fun GetInstance();
**/

class Singleton {
	public:
		static Singleton * GetInstance();

	private:
		Singleton() {}

		static Singleton *m_pInstance;
}

Singleton * Singleton::m_pInstance = NULL;

Singleton * Singleton::GetInstance() {
	if (m_pInstance == NULL)
		m_pInstance = new Singleton();

	return m_pInstance;
}

void main() {
	
}
