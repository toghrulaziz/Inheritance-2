#include <iostream>
#include <stack>

using namespace std;

class Engine {
	string engineNo;
	string company;
	double volume;
public:

	Engine(){}

	Engine(string engineNo,string company,double volume)
	{
		SetEngineNo(engineNo);
		SetCompany(company);
		SetVolume(volume);
	}

#pragma region Setters
	void SetEngineNo(string engineNo) {
		this->engineNo = engineNo;
	}

	void SetCompany(string company) {
		this->company = company;
	}

	void SetVolume(double volume) {
		this->volume = volume;
	}
#pragma endregion


#pragma region Getters
	string GetEngineNo()const { return engineNo; }
	string GetCompany()const { return company; }
	double GetVolume()const { return volume; }
#pragma endregion

	friend ostream& operator<<(ostream& out, const Engine& o) {
		out << "***** Engine *****" << "\nEngine No: " << o.engineNo << endl << "Company: " << o.company << endl << "Volume: " << o.volume;
		return out;
	}

};



class Vehicle {
	int id;
	static int staticId;
	string model;
	string vendor;
	Engine engine;
public:

	Vehicle()
	{
		id = staticId++;
	}

	Vehicle(string model,string vendor,Engine engine)
	{
		id = staticId++;
		SetModel(model);
		SetVendor(vendor);
		SetEngine(engine);
	}

#pragma region Setters
	void SetModel(string model) {
		this->model = model;
	}

	void SetVendor(string vendor) {
		this->vendor = vendor;
	}

	void SetEngine(Engine engine) {
		this->engine = engine;
	}
#pragma endregion

#pragma region Getters
	int GetId()const { return id; }
	string GetModel()const { return model; }
	string GetVendor()const { return vendor; }
	Engine GetEngine()const { return engine; }
#pragma endregion

	virtual void Show() {
		cout << "Id: " << id << "\nVendor: " << vendor << "\nModel: " << model << "\n" << engine << endl;
	}

};
int Vehicle::staticId = 1;





class Car : public Vehicle {
	bool hasSpoiler;
public:

	Car(string model, string vendor, Engine engine, bool hasSpoiler) : Vehicle(model, vendor, engine) {
		SetHasSpoiler(hasSpoiler);
	}

	void Show() override {
		cout << "****** Car ******\n";

		Vehicle::Show();
		cout << "Spoiler: " << (hasSpoiler ? "var" : "yox") << endl;
	}

	void SetHasSpoiler(bool hasSpoiler) {
		this->hasSpoiler = hasSpoiler;
	}

	bool GetHasSpoiler()const { return hasSpoiler; }


};



class Ship : public Vehicle{
	bool hasSail;
public:

	Ship(string model,string vendor,Engine engine,bool hasSail):Vehicle(model,vendor,engine)
	{
		SetHasSail(hasSail);
	}

	void Show() override {
		cout << "******* Ship *******\n";
		Vehicle::Show();
		cout << "Sail: " << (hasSail ? "var" : "yox") << endl;
	}

	void SetHasSail(bool hasSail) {
		this->hasSail = hasSail;
	}

	bool GetHasSail()const { return hasSail; }
};



class Airplane : public Vehicle {
	int engineCount;
	int passengersCapacity;
public:

	Airplane(string model,string vendor,Engine engine,int engineCount,int passengersCapacity):Vehicle(model,vendor,engine)
	{
		SetEngineCount(engineCount);
		SetPassengersCapacity(passengersCapacity);
	}

	void Show() override {
		cout << "****** Airplane ******\n";
		Vehicle::Show();
		cout << "Engine Count: " << engineCount << "\nPassengers Capacity: " << passengersCapacity << endl;
	}

	void SetEngineCount(int engineCount) {
		this->engineCount = engineCount;
	}

	void SetPassengersCapacity(int passengersCapacity) {
		this->passengersCapacity = passengersCapacity;
	}

	int GetEngineCount()const { return engineCount; }
	int GetPassengersCapacity()const { return passengersCapacity; }
};


class VehicleDepo {
public:
	stack<Vehicle*> vehicles;

	void ShowAllVehicles() {
		while (!vehicles.empty()) {
			vehicles.top()->Show();
			vehicles.pop();
		}
	}

};


void main() {
	VehicleDepo* depo = new VehicleDepo();
	depo->vehicles.push(new Car("BMW", "x5", Engine("100", "BMW",4.8 ), false));
	depo->vehicles.push(new Ship("yamaha", "2522SD", Engine("256", "Yamaha", 1.8), false));
	depo->vehicles.push(new Airplane("Boeing 777", "Boeing", Engine("GE9X", "Rolly-Royce", 343), 800, 388));

	depo->ShowAllVehicles();
	delete depo;
}