#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PatientRecord {
private:
    string name;
    int patientID;
    string dateOfBirth;
    vector<string> medicalHistory;
    string currentTreatment;

    void addToMedicalHistory(const string& history) {
        medicalHistory.push_back(history);
    }
    void setCurrentTreatment(const string& treatment) {
        currentTreatment = treatment;
    }

public:
    PatientRecord(string n, int id, string dob) : name(n), patientID(id), dateOfBirth(dob) {}
    string getPublicDetails() const {
        return "Name: " + name + ", ID: " + to_string(patientID) + ", Date of Birth: " + dateOfBirth;
    }

    vector<string> getMedicalHistory() const {
        return medicalHistory;
    }
    string getCurrentTreatment() const {
        return currentTreatment;
    }
    friend class Doctor;
    friend class Billing;
};
class Doctor {
public:
    void updateMedicalData(PatientRecord& record, const string& history, const string& treatment) {
        record.addToMedicalHistory(history);
        record.setCurrentTreatment(treatment);
    }
};

class Billing {
public:
    void addBillingInfo(PatientRecord& record, const string& details) {
        cout << "Billing details for patient ID " << record.patientID << ": " << details << endl;
    }
};
class Receptionist {
public:

    void showPatientPublicInfo(const PatientRecord& record) {
        cout << "Public Info: " << record.getPublicDetails() << endl;
    }
};

int main() {
    PatientRecord patient("Bisma Khan", 12345, "01/01/2000");

    Doctor doctor;
    doctor.updateMedicalData(patient, "Viral Infection diagnosis", "Prescribed antiviral medication");

    Billing billing;
    billing.addBillingInfo(patient, "Amount: RS.500");

    Receptionist receptionist;
    receptionist.showPatientPublicInfo(patient);
    return 0;
}

