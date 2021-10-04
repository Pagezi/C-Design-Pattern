// 组合模式


#include <iostream>
#include <vector>
#include <list>
#include <stack>

class Iterator;

class MenuComponent{
protected:
    std::string _name = "";
    std::string _description = "";
    bool _isVegetarian = false;
    double _price = -1;
public:
    std::string GetName()
    {
        return _name;
    }
    
    std::string GetDesc()
    {
        return _description;
    }
    
    double GetPrice()
    {
        return _price;
    }
    
    bool IsVegetarian()
    {
        return _isVegetarian;
    }
    void PrintMenu()
    {
        std::cout << GetName() << std::endl;
        std::cout << GetDesc() << std::endl;
        std::cout << GetPrice() << std::endl;
        std::cout << IsVegetarian() << std::endl;
    }
    
    Iterator* CreateIterator();
    
    void Add(MenuComponent component){
        
    }
    
    void Remove(MenuComponent component)
    {
        
    }
    MenuComponent GetChild(int index);
};

class Menu:public MenuComponent
{
protected:
    std::vector<MenuComponent> menuComponents = std::vector<MenuComponent>();
public:

    void Add(MenuComponent component){
        menuComponents.push_back(component);
    }
    
    void Remove(MenuComponent component){
        
    }
    
    MenuComponent GetChild(int index){
        return menuComponents[index];
    }
    
};

class MenuItem:public MenuComponent {
private:
    std::string _name;
    std::string _description;
    bool _isVegetarian;
    double _price;
public:
    MenuItem(){}
    MenuItem(std::string name, std::string description, bool isVegetarian, double price) :_name(name), _description(description), _isVegetarian(isVegetarian), _price(price)
    {
        
    }
};


class Iterator {
public:
    virtual bool HasNext() = 0;
    virtual MenuItem Next() = 0;
};

//class ComponentIterator: public Iterator
//{
//private:
//    std::stack<Iterator*> stack;
//public:
//    ComponentIterator(Iterator* iter)
//    {
//        stack = std::stack<Iterator*>();
//        stack.push(iter);
//    }
//
//    bool HasNext()
//    {
//
//    }
//
//    MenuItem Next()
//    {
//
//    }
//};

class PancakeHouseMenuIterator :public Iterator
{
private:
    std::vector<MenuItem> menuItems;
    int position = 0;
public:
    PancakeHouseMenuIterator(std::vector<MenuItem> items):menuItems(items){}
    
    bool HasNext()
    {
        if (position <menuItems.size())
        {
            return true;
        }
        return false;
    }
    
    MenuItem Next()
    {
        MenuItem ans;
        if (HasNext())
        {
            ans = menuItems[position];
            position += 1;
            return ans;
        }
        return ans;
    }
};

class DinnerMenuIterator :public Iterator
{
private:
    std::list<MenuItem> menuItems;
    std::list<MenuItem>::iterator listIterator;
public:
    DinnerMenuIterator(std::list<MenuItem> items) :menuItems(items)
    {
        listIterator = menuItems.begin();
    }
    
    
    bool HasNext()
    {
        if (listIterator!= menuItems.end())
        {
            return true;
        }
        return false;
    }
    
    MenuItem Next()
    {
        MenuItem ans;
        if (HasNext())
        {
            MenuItem ans = *listIterator;
            listIterator++;
            return ans;
        }
        return ans;
    }
};

class PancakeHouseMenu :public MenuComponent
{
private:
    std::vector<MenuItem> menuItems;
public:
    PancakeHouseMenu(std::vector<MenuItem> items) {
        this->menuItems = items;
    }
    
    Iterator* CreateIterator()
    {
        return new PancakeHouseMenuIterator(menuItems);
    }
};

class DinnerMenu :public MenuComponent
{
private:
    std::list<MenuItem> menuItems;
public:
    DinnerMenu(std::list<MenuItem> items) {
        this->menuItems = items;
    }
    
    Iterator* CreateIterator()
    {
        return new DinnerMenuIterator(menuItems);
    }
};


void PrintMenu(Iterator* iter)
{
    while (iter->HasNext())
    {
        MenuItem ans = iter->Next();
        std::cout << ans.GetName() << std::endl;
        std::cout << ans.GetDesc() << std::endl;
        std::cout << ans.GetPrice() << std::endl;
        std::cout << ans.IsVegetarian() << std::endl;
    }
}

int main()
{
    std::list<MenuItem> items = std::list<MenuItem>();
    items.push_back(MenuItem("cake", "1", false, 1.66));
    DinnerMenu dinnerMenu = DinnerMenu(items);
    
    std::vector<MenuItem> vecItems = std::vector<MenuItem>();
    vecItems.push_back(MenuItem("bread", "2", false, 1.77));
    PancakeHouseMenu pancakeMenu = PancakeHouseMenu(vecItems);
    
    Iterator* dinnerIterator = dinnerMenu.CreateIterator();
    PrintMenu(dinnerIterator);
    
    Iterator* pancakeIterator = pancakeMenu.CreateIterator();
    PrintMenu(pancakeIterator);
    
    return 0;
}
