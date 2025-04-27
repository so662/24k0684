 #include "iostream"
using namespace std;
class WeatherSensor{
    public:
    virtual void ReadData() = 0;
    virtual void DisplayReport() = 0;
};
class Thermometer : public WeatherSensor{
    public:
    void ReadData() {
        cout << "Reading temperature data..." << endl;
    }
    void DisplayReport() {
        cout << "Displaying temperature report..." << endl;
    }
};
class Barometer : public WeatherSensor{
    public:
    void ReadData() {
        cout << "Reading pressure data..." << endl;
    }
    void DisplayReport() {
        cout << "Displaying pressure report..." << endl;
    }
};
int main(){
    Thermometer tempSensor;
    Barometer pressureSensor;
    tempSensor.ReadData();
    tempSensor.DisplayReport();
    pressureSensor.ReadData();
    pressureSensor.DisplayReport();
    cout << endl;
    return 0;
}