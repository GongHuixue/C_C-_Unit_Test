#include <iostream>
#include <list>
#include <string>

using namespace std;

//observer
class observer {
	public:
		observer() {}
		virtual ~observer() {}
		virtual void update() {}
};

//blog
class blog {
	public:
		blog() {}
		virtual ~blog() {}
		void Attach(observer *observer) { m_observers.push_back(observer); }
		void Remove(observer *observer) { m_observers.remove(observer);}
		
		void notify()
		{
			list<observer*>::iterator iter = m_observers.begin();
			for(; iter != m_observers.end(); iter++) {
				(*iter)->update();
			}
		}

		virtual void SetStatus(string s) {m_status = s;}
		virtual string GetStatus() {return m_status;}

	private:
		list<observer*> m_observers;
	protected:
		string m_status;
};

class blogcsdn : public blog {
	private:
		string m_name;
	public:
		blogcsdn(string name):m_name(name) {}
		~blogcsdn() {}
		
		void SetStatus(string s) { m_status = "csdn notify:" + m_name + s; }
		string GetStatus () {return m_status;}
};

class observerblog : public observer {
	private:
		string m_name;
		blog *m_blog;
	public:
		observerblog(string name, blog *blog):m_name(name), m_blog(blog) {}
		~observerblog() {}

	void update() {
		string status = m_blog->GetStatus();
		cout << m_name << "---------" << status << endl;
	}	
};

int main() {
	blog *blog1 = new blogcsdn("fany");

	observer *observer1 = new observerblog("csdn", blog1);

	blog1->Attach(observer1);

	blog1->SetStatus("a new blog");

	blog1->notify();

	delete blog1; delete observer1;

	return 0;
}
