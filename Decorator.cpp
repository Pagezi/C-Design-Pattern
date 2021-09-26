#include <iostream>
#include <list>



// Component 组件  饮料基类
class Beverage {
protected:
	std::string descript;

public:
    Beverage() {}

	std::string GetDescription() {
		return descript;
	}

	virtual float Cost() { return 0.0f; };
};

// 装饰器基类  加料
class CondimentDecorator :public Beverage {
public:
	CondimentDecorator(){}
};

//饮料
class Coffee :public Beverage {
public:
	Coffee(){
		descript = "Coffee";
	}
	
	float Cost() override
	{
		return 0.55f;
	}
};

class Milk :public CondimentDecorator
{
private:
	Beverage* beverage;
public:
	Milk(Beverage* beverage) {
		this->beverage = beverage;
		this->descript = "Milk " + beverage->GetDescription();
	}

	float Cost() override {
		return 0.1f + beverage->Cost();
	}
};

class Mocha :public CondimentDecorator
{
private:
	Beverage* beverage;
public:

	Mocha(Beverage* beverage){
		this->beverage = beverage;
		this->descript = "Mocha " + beverage->GetDescription();
	}


	float Cost() override{
		return 0.2f + beverage->Cost();
	}
};

class Soy :public CondimentDecorator
{
private:
	Beverage* beverage;
public:
	Soy(Beverage* beverage){
		this->beverage = beverage;
		this->descript = "Soy " + beverage->GetDescription();
	}

	float Cost() override{
		return 0.2f + beverage->Cost();
	}
};

int main()
{
	Beverage* berverage = new Coffee();
	berverage = new Milk(berverage);
	berverage = new Soy(berverage);
	berverage = new Mocha(berverage);
	std::cout << berverage->Cost() << std::endl;
	std::cout << berverage->GetDescription() << std::endl;
	return 0;
}