#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    virtual double getTuition(const string& status, int creditHours) = 0; 
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    double getTuition(const string& status, int creditHours) override {
        double tuitionRate = 0.0;

        if (status == "undergraduate") {
            tuitionRate = 200.0;
        } else if (status == "graduate") {
            tuitionRate = 300.0;
        } else if (status == "doctoral") {
            tuitionRate = 400.0;
        }

        return tuitionRate * creditHours;
    }
    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }
    string getResearchTopic() const {
        return researchTopic;
    }
};

int main() {
    GraduateStudent gradStudent;
    gradStudent.setResearchTopic("Artificial Intelligence");
    cout << "Research Topic: " << gradStudent.getResearchTopic() << endl;
    cout << "Tuition for 12 credit hours (Graduate): $" << gradStudent.getTuition("graduate", 12) << endl;

    return 0;
}

