#include "iostream"
using namespace std;
class Shipment{
    protected:
    string trackingNumber;
    double weight;
    public:
    Shipment(string tn, double w) : trackingNumber(tn), weight(w) {}
    virtual void estimateDeliveryTime() = 0;
    virtual void DisplayInfo() = 0;

};
class AirFreight : public Shipment{
    public:
    AirFreight(string tn, double w) : Shipment(tn, w) {}
    void estimateDeliveryTime() {
        cout << "Estimated delivery time for Air Freight: 2-3 days" << endl;
    }
    void DisplayInfo() {
        cout << "Air Freight Shipment Info:" << endl;
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};
class GroundShipment : public Shipment{
    public:
    GroundShipment(string tn, double w) : Shipment(tn, w) {}
    void estimateDeliveryTime() {
        cout << "Estimated delivery time for Ground Shipment: 5-7 days" << endl;
    }
    void DisplayInfo() {
        cout << "Ground Shipment Info:" << endl;
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};
int main(){
    AirFreight airShipment("AF12345", 10.5);
    GroundShipment groundShipment("GS67890", 20.0);
    
    airShipment.DisplayInfo();
    airShipment.estimateDeliveryTime();
    
    cout << endl;
    
    groundShipment.DisplayInfo();
    groundShipment.estimateDeliveryTime();
    
    cout << endl;
    return 0;
}