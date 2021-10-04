// 工厂方法模式
//
//
#include <iostream>
#include <vector>
#include <list>
#include <stack>

class Pizza{
protected:
    std::vector<std::string> others;
public:
    void Prepare(){
        std::cout<< "prepare"<<std::endl;
    }
    
    void Bake(){
        std::cout<< "bake"<<std::endl;
    }
    
    void Cut(){
        std::cout<< "cut"<<std::endl;
    }
    
    void Box(){
        std::cout<< "box"<<std::endl;
    }
    
    void Other(){
        for(std::vector<std::string>::iterator it = others.begin();it!=others.end();++it){
            std::cout<<*it<<std::endl;
        }
    }
};

class ShanghaiCheesePizza:public Pizza
{
public:
    ShanghaiCheesePizza(){
        others.push_back("shanghai CheesePizza1");
        others.push_back("shanghai CheesePizza2");
        others.push_back("shanghai CheesePizza3");
    }
};

class ShanghaiVeggiePizza:public Pizza
{
public:
    ShanghaiVeggiePizza(){
        others.push_back("shanghai VeggiePizza1");
        others.push_back("shanghai VeggiePizza2");
        others.push_back("shanghai VeggiePizza3");
    }
};

class BeijingCheesePizza:public Pizza
{
public:
    BeijingCheesePizza(){
        others.push_back("beijing CheesePizza1");
        others.push_back("beijing CheesePizza2");
        others.push_back("beijing CheesePizza3");
    }
};

class BeijingVeggiePizza:public Pizza
{
public:
    BeijingVeggiePizza(){
        others.push_back("beijing VeggiePizza1");
        others.push_back("beijing VeggiePizza2");
        others.push_back("beijing VeggiePizza3");
    }
};

class PizzaStoreBase{
public:
    virtual Pizza* CreatePizza(std::string type) = 0;
    Pizza* OrderPizza(std::string type){
        Pizza* pizza = CreatePizza(type);
        pizza->Prepare();
        pizza->Bake();
        pizza->Cut();
        pizza->Box();
        pizza->Other();
        return pizza;
    }
};

class ShanghaiPizzaStore:public PizzaStoreBase{
public:
    Pizza* CreatePizza(std::string type){
        Pizza* pizza;
        if(type == "CheesePizza")
            pizza = new ShanghaiCheesePizza();
        else if(type == "VeggiePizza")
            pizza = new ShanghaiVeggiePizza();
        else
            pizza = new ShanghaiVeggiePizza();
        return pizza;
    }
};

class BeijingPizzaStore:public PizzaStoreBase{
public:
    Pizza* CreatePizza(std::string type){
        Pizza* pizza;
        if(type == "CheesePizza")
            pizza = new BeijingCheesePizza();
        else if(type == "VeggiePizza")
            pizza = new BeijingVeggiePizza();
        else
            pizza = new BeijingVeggiePizza();
        return pizza;
    }
};

int main()
{
    BeijingPizzaStore beijing = BeijingPizzaStore();
    beijing.OrderPizza("CheesePizza");
    ShanghaiPizzaStore shanghai = ShanghaiPizzaStore();
    shanghai.OrderPizza("VeggiePizza");
    return 0;
}
