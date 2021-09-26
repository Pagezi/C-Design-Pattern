#include <iostream>
#include <vector>

class DuckBase {
public:
	virtual void Quack() = 0;
	virtual void Fly() = 0;
};

class Duck:public DuckBase {
public:
	void Quack() override{
		std::cout << "quack" << std::endl;
	}

	void Fly() override {
		std::cout << "duck fly" << std::endl;
	}
};

class TurkeyBase{
public:
	virtual void Gobble() = 0;
	virtual void Fly() = 0;
};

class Turkey :TurkeyBase {
public:
	void Gobble() override {
		std::cout << "gobble" << std::endl;
	}

	void Fly() override {
		std::cout << "turkey fly" << std::endl;
	}
};

class TurkeyAdapter :public DuckBase {
	// 通过 DuckBase 继承
private:
	Turkey turkey;
public:
	TurkeyAdapter(Turkey turkey)
	{
		turkey = turkey;
	}
	void Quack() override
	{
		turkey.Gobble();
	}
	void Fly() override
	{
		turkey.Fly();
	}
};

int main()
{
	Turkey turkey = Turkey();
	DuckBase* adatper = new TurkeyAdapter(turkey);
	adatper->Quack();
	adatper->Fly();
	return 0;
}