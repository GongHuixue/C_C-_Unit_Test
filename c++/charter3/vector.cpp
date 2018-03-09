#include <iostream>
#include <vector>

using namespace std;

int main() {
	int i;
	vector<int> v;
	
	for(i = 0; i < 100; i++)
	{
		v.push_back(i);
	}
		
	for(i = 0; i < 100; i++)
	{
		
		cout << v[i] << endl;

		if(i % 10 == 0)
		{
			cout << "\n" << endl;
		}
	}

	return 0;
}
