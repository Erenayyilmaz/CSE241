#include <iostream>

using namespace std;

class NewClass
{
public:
	NewClass();
	~NewClass();
	friend NewClass operator-(NewClass a);
	//inline	NewClass operator-(){set_data(get_data() * -1 );};
	void	set_data(int asd);
	inline int	get_data(){ return data; };
private:
	int	data;
};

NewClass::NewClass()
{
}

NewClass::~NewClass()
{
}

void NewClass::set_data(int asd)
{
	data = asd;
}

NewClass operator-(NewClass a)
{
	a.data *= -1;
	return a;
}


int main(void)
{
	NewClass x;
	x.set_data(25);
	x = -x;
	cout << x.get_data();

	cin.
}
