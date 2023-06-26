#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

class Vehicle{
    private:
        static string LicenseNo;
    public:
        Vehicle();
        Vehicle(string LicenseNo){
            this->LicenseNo = LicenseNo;
        }
        virtual void assignTicket(ParkingTicket ticket) = 0;
};

class Car : public Vehicle{
    public:
        Car();
        Car(string licenseNo): Vehicle(licenseNo){};

        void assignTicket(ParkingTicket ticket) override {
            
        }
};

class Truck : public Vehicle{
    public:
        Truck(string licenseNo) : Vehicle(licenseNo) {};
        void assignTicket(ParkingTicket ticket) override {

        }
};

class Van : public Vehicle{
    public:
        Van(string licenseNo) : Vehicle(licenseNo){};

        void assignTicket(ParkingTicket ticket) override {

        }
};

class Motorcycle : public Vehicle {
    public:
        Motorcycle(string licenseNo) : Vehicle(licenseNo){};
        void assignTicket(ParkingTicket ticket) override {

        }

};

class ElectricPanel {
    private:
        int payedForMinute;
        system_clock::time_point start;
        system_clock::time_point end;
        seconds duration;
        time_t chargingStartTime;
    public: 
        ElectricPanel(int payedForMinute, system_clock::time_point start ){
            this->payedForMinute = payedForMinute;
            this->start = start;
        }
        bool cancelCharging(){
            this->end = system_clock::now();
            this->duration = duration_cast<seconds>(end - start);
            cout<<&duration<<endl;
            return true;
        }
};

class ParkingSpot{
    private:
        int id;
        bool isFree = 1;
        //type parkingSpotType; ??????? what is type???????
        Vehicle* vehicle;

    public:
        ParkingSpot(int id, Vehicle* vehicle){
            this->id = id;
            this->isFree = 0;
            this->vehicle = vehicle;
        }

        bool getIsFree(){
            return isFree;
        }
        virtual bool assignVehicle(Vehicle* vehicle) = 0;
        bool removeVehicle(){

        }
};


class LargeSpot : public ParkingSpot{
    public:
        LargeSpot(int id, Vehicle* vehicle) : ParkingSpot(id, vehicle){};
        bool assignVehicle(Vehicle* vehicle) override {

        }
};

class HandicappedSpot : public ParkingSpot{
    public:
        bool assignVehicle(Vehicle* vehicle) override {

        }
};

class Electric : public ParkingSpot{
    public:
        bool assignVehicle(Vehicle* vehicle) override {

        }
};

class CompactSpot : public ParkingSpot{
    public:
        bool assignVehicle(Vehicle* vehicle) override {

        }
};

class MotorcycleSpot : public ParkingSpot{
    public:
        bool assignVehicle(Vehicle* vehicle) override {

        }
};

class AccountStatus{

};

class Person{
    private:
        string name;
        string address;
        string city;
        string state;
        int zipCode;
        string country;
        string phone;
        string email;
};


class Account{
    private:
        string userName;
        string password;
        AccountStatus status;
        Person person;
    public:
        virtual bool resetPassword() = 0;
};

class Admin : public Account{
    private:
    
    public:
        // bool addParkingFloor(ParkingFloor floor){ }

        bool addParkingSpot(ParkingFloor floorName, ParkingSpot* spot){

        }
        
        bool addDisplayBoard(ParkingFloor floorName, DisplayBoard displayBoard){

        }
        bool addEntrance(Entrance entrance){

        }
        bool addExit(Exit exit){

        }
        bool resetPassword(){

        }
};

class Agent : public Account{
    public: 
        bool processTicket(string ticketNumber);

        bool resetPassword(){

        }

};

class DisplayBoard{
    private:
        int id;
        vector<HandicappedSpot> handicappedSpot;
        vector<CompactSpot> compactSpot;
        vector<LargeSpot> LargeSpot;
        vector<MotorcycleSpot> motorcycleSpot;
    public:
        void showFreeSlot(){

        }
};



class ParkingTicket{
    private:
        int ticketNo;
        time_t timestamp;
        time_t exit;
        double amount;
        bool status;
        system_clock::time_point entry;
        Payment* payment;
        Entrance entrance;
        Vehicle* vehicle;
        Exit exitIns;
    public:
        ParkingTicket();
        ParkingTicket(int no) {  
            this->ticketNo = no;
            this->entry = system_clock::now();            
        }
        void setTicketNo(int no){
            ticketNo = no;
        }
        int getTicketNo(){
            return ticketNo;
        }
};


class Payment{
    private:
        double amount;
        PaymentStatus status;
        time_t timestamp;
    public:
        void calculate(){

        }
        virtual bool initiateTransaction() = 0;
};

class PaymentStatus{
    

};

class Cash : public Payment{
    public :
        Cash(double amount, PaymentStatus paymentStatus){}
        bool initiateTransaction() override  {

        }
};

class CreditCard : public Payment{
    public:
        bool initiateTransaction() override {

        }

};

class ParkingRate{
    double hours;
    double rate;
    public:
        ParkingRate(double hour=0, double rate=0){
            this->hours = hour;
            this->rate = rate;
        }
        void calculate(){
            
        }
};

class Address{
    private:
        int zipCode;
        string address;
        string city;
        string state;
        string country;
    public:
        Address(int zipcode=0, string address="", string city="", string state="", string country){
            this->zipCode = zipcode;
            this->address = address;
            this->city = city;
            this->state = state;
            this->country = country;
        }
};

class ParkingLot{
    private:
        int id;
        string name;
        Address address;
        ParkingRate parkingRate;
        
        static ParkingLot* instance;

        map<string, Entrance> entrance;
        map<string, Exit> exit;

        map<string, ParkingTicket> tickets;

        
    public:
        static ParkingLot* getInstance(int id=-1, string name="", ParkingRate parkingRate) {
            if (instance == nullptr) {
                instance = new ParkingLot();
            }
            return instance;
        }

        bool addEntrance(){
            return 1;
        }
        bool addExit(){
            return 1;
        }
        ParkingTicket getParkingTicket(){
            
        }
        bool isFull(){

        }
};
ParkingLot* ParkingLot::instance = nullptr;

class Entrance{
    private:
        int id;
        ParkingTicket ticket;
    public:
        
        Entrance(int id = -1, ParkingTicket ticket = NULL){
            this->id = id;
            this->ticket = ticket;
        }
        ParkingTicket* getTicket(ParkingTicket* ticket){
            return ticket;
        };
};

class Exit{
    private:
        int id;
        ParkingTicket ticket;
    public:
        Exit(int id = -1, ParkingTicket ticket = NULL){
            this->id = id;
            this->ticket = ticket;
        }
        void validateTicket(ParkingTicket ticket){

        }
};

class ParkingFloor{
    private:
        string name;
    public:
        ParkingFloor(string name = ""){
            this->name = name;
        }
        void updateDisplayBoard(){

        }

        void assignVehicleToSpot(){

        }

        void addParkingSlot(){

        }
        void freeSlot(){

        }
};



enum PaymentStatusEnum{
        COMPLETED, 
        FAILED,
        PENDING,
        UNPAID,
        REFUNDED
};

enum AccountStatusenum{
    ACTIVE,
    CLOSED,
    CANCELLED,
    BLACKLISTED,
    NONE
};

int main(){
    ParkingLot* parkingLot = ParkingLot::getInstance();
    return 0;

}