#include <iostream>
#include <vector>
#include <list>
#include <stack>

class Pizza{
public:
    virtual void Prepare() = 0;
    virtual void Bake() = 0;
    virtual void Cut() = 0;
    virtual void Box() = 0;
};

class CheesePizza:public Pizza
{
public:
    void Prepare(){
        std::cout<< "CheesePizza prepare"<<std::endl;
    }
    
    void Bake(){
        std::cout<< "CheesePizza bake"<<std::endl;
    }
    
    void Cut(){
        std::cout<< "CheesePizza cut"<<std::endl;
    }
    
    void Box(){
        std::cout<< "CheesePizza box"<<std::endl;
    }
};
    
class VeggiePizza:public Pizza
{
public:
    void Prepare(){
        std::cout<< "VeggiePizza prepare"<<std::endl;
    }
    
    void Bake(){
        std::cout<< "VeggiePizza bake"<<std::endl;
    }
    
    void Cut(){
        std::cout<< "VeggiePizza cut"<<std::endl;
    }
    
    void Box(){
        std::cout<< "VeggiePizza box"<<std::endl;
    }
};

    
    
class SimplePizzaFactory{
public:
    Pizza* CreatePizza(std::string type){
        Pizza* pizza;
        if(type == "CheesePizza")
            pizza = new CheesePizza();
        else if(type == "VeggiePizza")
            pizza = new VeggiePizza();
        else
            pizza = new VeggiePizza();
        return pizza;
    }
};


class PizzaStore{
private:
    SimplePizzaFactory factory;
public:
    
    PizzaStore(SimplePizzaFactory factory){
        this->factory = factory;
    }
    
    
    Pizza* OrderPizza(std::string type){
        Pizza* pizza = this->factory.CreatePizza(type);
        pizza->Prepare();
        pizza->Bake();
        pizza->Cut();
        pizza->Box();
        return pizza;
    }
};

int main()
{
    SimplePizzaFactory factory = SimplePizzaFactory();
    PizzaStore store = PizzaStore(factory);
    store.OrderPizza("VeggiePizza");
    store.OrderPizza("CheesePizza");
    return 0;
}
