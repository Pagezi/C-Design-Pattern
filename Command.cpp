#include <iostream>
#include <vector>


// 实际的控制对象  receiver
class Light {
public:
	void LightOn()
	{
		std::cout << "light on" << std::endl;
	}

	void LightOff()
	{
		std::cout << "light off" << std::endl;
	}
};


// 命令们
class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class NoCommand :public Command {
	void execute() override {}
	void undo() override {}
};

class LightOnCommand :public Command
{
private:
	Light* light;
public:
	void execute() override
	{
		light->LightOn();
	}

	void undo() override
	{
		light->LightOff();
	}
};

class LightOffCommand :public Command
{
private:
	Light* light;
public:
	void execute() override
	{
		light->LightOff();
	}

	void undo() override
	{
		light->LightOn();
	}
};


// 控制器 Invoker
class RemoteControl {
private:
	int size = 7;
	std::vector<Command*> onCommands;
	std::vector<Command*> offCommands;
	std::vector<Command*> undoCommands;
public:
	RemoteControl()
	{
		for (int i = 0; i < 7; i++)
		{
			Command* noCommand = new NoCommand();
			onCommands.push_back(noCommand);
			offCommands.push_back(noCommand);
		}
	}

	void SetCommand(Command* onCommand, Command* offCommand, int slot)
	{
		onCommands[slot] = onCommand;
		offCommands[slot] = offCommand;
	}

	void OnButtonPress(int slot)
	{
		onCommands[slot]->execute();
		undoCommands.push_back(onCommands[slot]);
	}

	void OffButtonPress(int slot)
	{
		offCommands[slot]->execute();
		undoCommands.push_back(offCommands[slot]);
	}

	void UnodoButtonPress()
	{
		if (undoCommands.size() > 0)
		{
			Command* undoCommand = undoCommands.back();
			undoCommand->execute();
			undoCommands.pop_back();
		}
	}
};


int main()
{
	Light light = Light();
	RemoteControl reControl = RemoteControl();
	Command* lightOnCommand = new LightOnCommand();
	Command* lightOffCommand = new LightOffCommand();
	reControl.SetCommand(lightOnCommand, lightOffCommand, 0);
	reControl.OnButtonPress(0);
	reControl.OffButtonPress(0);
	reControl.UnodoButtonPress();
	reControl.UnodoButtonPress();
	return 0;
}