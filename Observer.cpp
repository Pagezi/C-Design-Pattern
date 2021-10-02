// 观察者模式


#include <iostream>
#include <list>


// 观察者 
class Observer
{
public:
	virtual void Update(float temperature, float humidity, float pressure)=0;
};

//气象站公告板
class CurrentConditionDisplay :Observer
{
private:
	float temperature = 0.0f;
	float humidity = 0.0f;
	float pressure = 0.0f;
	WeatherData* subject;
public:
	CurrentConditionDisplay(WeatherData* s)
	{
		this->subject = s;
		subject->RegisterObserver(this);
	}

	void Update(float temperature, float humidity, float pressure) override
	{
		this->temperature = temperature;
		this->humidity = humidity;
		this->pressure = pressure;
		Display();
	}
	void Display()
	{
		std::cout << "Current conditions: " << temperature << std::endl;
		std::cout << "Humidity: " << humidity << std::endl;
		std::cout << "Pressure: " << pressure << std::endl << std::endl;
	}
};


// 主题
class Subject
{
public:
	virtual void RegisterObserver(Observer* observer) = 0;
	virtual void RemoveObserver(Observer* observer) = 0;
	virtual void NotifyObserver() = 0;
};

// 气象站数据
class WeatherData :Subject
{
private:
	std::list<Observer*> observerList;
	float temperature;
	float humidity;
	float pressure;
public:
	WeatherData()
	{
		this->observerList = std::list<Observer*>();
	}

	void RegisterObserver(Observer* observer)
	{
		this->observerList.push_back(observer);
	}

	void RemoveObserver(Observer* observer)
	{
		observerList.remove(observer);
	}

	void NotifyObserver()
	{
		for (std::list<Observer*>::iterator it = this->observerList.begin(); it != this->observerList.end(); ++it)
		{
			(*it)->Update(temperature, humidity, pressure);
		}
	}

	void SetMeasurements(float temperature, float humidity, float pressure)
	{
		this->temperature = temperature;
		this->humidity = humidity;
		this->pressure = pressure;
		NotifyObserver();
	}
};



int main()
{
	WeatherData* weatherData = new WeatherData();
	CurrentConditionDisplay display = CurrentConditionDisplay(weatherData);
	weatherData->SetMeasurements(30.4f, 65, 90);
	weatherData->SetMeasurements(20.4f, 60, 80);
	weatherData->SetMeasurements(10.4f, 55, 70);
}
