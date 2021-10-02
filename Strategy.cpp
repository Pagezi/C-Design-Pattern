// 策略模式


#include <iostream>
#include <vector>


class FlyBehavior {
public:
	virtual void Fly() = 0;
};

class QuackBehavior {
public:
	virtual void Quack() = 0;
};

class FlyWithWings :public FlyBehavior {
public:
	void Fly() override
	{
		std::cout << "fly with wings" << std::endl;
	}
};

class FlyRocket :public FlyBehavior {
public:
	void Fly() override
	{
		std::cout << "fly with Rocket" << std::endl;
	}
};

class QuackDuck :public QuackBehavior {
public:
	void Quack() override
	{
		std::cout << "quack with duck" << std::endl;
	}
};

class QuackMuteDuck :public QuackBehavior {
public:
	void Quack() override
	{
		std::cout << "quack with mute duck" << std::endl;
	}
};

class Duck {
protected:
	FlyBehavior* flybehavior;
	QuackBehavior* quackbehavior;
public:
	void Swing(){
		std::cout << "Duck Swing" << std::endl;
	}
	void PeformQuack()
	{
		quackbehavior->Quack();
	}
	void PerformFly() {
		flybehavior->Fly();
	}
	void SetFlyBehavior();
	void SetQuackBehavior();
};

class ModelRockDuck :public Duck {
public:
	void SetFlyBehavior(FlyBehavior* flyBehavior)
	{
		this->flybehavior = flyBehavior;
	}

	void SetQuackBehavior(QuackBehavior* quackBehavior)
	{
		this->quackbehavior = quackBehavior;
	}
};



int main()
{
	ModelRockDuck modelRockDuck = ModelRockDuck();
	FlyBehavior* flyWithWings = new FlyWithWings();
	FlyBehavior* flyRocket = new FlyRocket();
	QuackBehavior* quackBehavior = new QuackMuteDuck();
	modelRockDuck.SetFlyBehavior(flyWithWings);
	modelRockDuck.SetQuackBehavior(quackBehavior);
	modelRockDuck.PerformFly();
	modelRockDuck.PeformQuack();
	modelRockDuck.SetFlyBehavior(flyRocket);
	modelRockDuck.PerformFly();
	modelRockDuck.PeformQuack();
	return 0;
}