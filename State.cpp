// 状态模式

#include <iostream>
#include <vector>
#include <list>
#include <stack>

class GumallStateMachine;

class State{
private:
    GumallStateMachine* gumallStateMachine;
public:
    virtual void InsertQuater()=0;
    virtual void EjectQuater()=0;
    virtual void TurnCrank()=0;
    virtual void Dispense()=0;
};

class SoldState:public State{
public:
    SoldState(GumallStateMachine* gumallStateMachine){
        gumallStateMachine = gumallStateMachine;
    }
    void InsertQuater(){}
    void EjectQuater(){}
    void TurnCrank(){}
    void Dispense(){}
};

class SoldOutState:public State{
public:
    SoldOutState(GumallStateMachine* gumallStateMachine){
        gumallStateMachine = gumallStateMachine;
    }
    void InsertQuater(){}
    void EjectQuater(){}
    void TurnCrank(){}
    void Dispense(){}
};

class NoQuaterState:public State{
public:
    NoQuaterState(GumallStateMachine* gumallStateMachine){
        gumallStateMachine = gumallStateMachine;
    }
    void InsertQuater(){}
    void EjectQuater(){}
    void TurnCrank(){}
    void Dispense(){}
};

class HasQuaterState:public State{
public:
    HasQuaterState(GumallStateMachine* gumallStateMachine){
        gumallStateMachine = gumallStateMachine;
    }
    void InsertQuater(){}
    void EjectQuater(){}
    void TurnCrank(){}
    void Dispense(){}
};

class GumallStateMachine{
private:
    State* soldState;
    State* soldOutState;
    State* noQuaterState;
    State* hasQuaterState;
    
    State* currentState;
    int count;
public:
    GumallStateMachine(int count){
        soldState = new SoldState(this);
        soldOutState = new SoldOutState(this);
        noQuaterState = new NoQuaterState(this);
        hasQuaterState = new HasQuaterState(this);
        this->count = count;
    }
    void InsertQuater(){currentState->InsertQuater();}
    void EjectQuater(){currentState->EjectQuater();}
    void TurnCrank(){currentState->TurnCrank();}
    void Dispense(){currentState->Dispense();}
    
    void SetCurrentState(State* state){this->currentState = state;}
};


int main()
{

    
    return 0;
}
