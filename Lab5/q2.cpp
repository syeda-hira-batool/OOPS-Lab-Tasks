#include <iostream>
#include <string>
using namespace std;

class MedicationEntry
{
private:
    string drugName;
    string dose;
    float timeGiven;

public:
    MedicationEntry(string dn, string d, float t)
        : drugName(dn), dose(d), timeGiven(t)
    {
        cout << "MedicationEntry created for drug: " << drugName << endl;
    }

    void display()
    {
        cout << "Medication: " << drugName
             << ", Dose: " << dose
             << ", Time Given: " << timeGiven << " hrs" << endl;
    }

    ~MedicationEntry()
    {
        cout << "MedicationEntry deleted for drug: " << drugName << endl;
    }
};

class VitalSignsCheck
{
private:
    float temperature;
    float heartRate;
    float timeChecked;

public:
    VitalSignsCheck(float t, float hr, float tc)
        : temperature(t), heartRate(hr), timeChecked(tc)
    {
        cout << "VitalSignsCheck created" << endl;
    }

    void display()
    {
        cout << "Temperature: " << temperature
             << " C, Heart Rate: " << heartRate
             << " bpm, Time Checked: " << timeChecked << " hrs" << endl;
    }

    ~VitalSignsCheck()
    {
        cout << "VitalSignsCheck deleted" << endl;
    }
};

class DiagnosisNote
{
private:
    string noteText;
    string doctorName;
    string date;

public:
    DiagnosisNote(string nt, string dn, string d)
        : noteText(nt), doctorName(dn), date(d)
    {
        cout << "DiagnosisNote created by Dr. " << doctorName << endl;
    }

    void display()
    {
        cout << "Diagnosis: " << noteText
             << ", Doctor: " << doctorName
             << ", Date: " << date << endl;
    }

    ~DiagnosisNote()
    {
        cout << "DiagnosisNote deleted" << endl;
    }
};

class PatientRecord
{
private:
    string patientId;
    string name;
    string dob;

    MedicationEntry *medicationEntry;
    VitalSignsCheck *vitalSignsCheck;
    DiagnosisNote *diagnosisNote;

public:
    PatientRecord(string p, string n, string d,
                  string drug, string dose, float medTime,
                  float temp, float hr, float vitTime,
                  string diagText, string doctor, string diagDate)
        : patientId(p), name(n), dob(d)
    {
        medicationEntry = new MedicationEntry(drug, dose, medTime);
        vitalSignsCheck = new VitalSignsCheck(temp, hr, vitTime);
        diagnosisNote = new DiagnosisNote(diagText, doctor, diagDate);

        cout << "PatientRecord created for " << name << endl;
    }

    void displayRecord()
    {
        cout << "\n-------- Patient Record --------" << endl;
        cout << "Patient ID: " << patientId << endl;
        cout << "Name: " << name << endl;
        cout << "DOB: " << dob << endl;
        medicationEntry->display();
        vitalSignsCheck->display();
        diagnosisNote->display();
        cout << "\n"
             << endl;
    }

    ~PatientRecord()
    {
        delete medicationEntry;
        delete vitalSignsCheck;
        delete diagnosisNote;
        cout << "PatientRecord deleted for " << name << endl;
    }
};

int main()
{

    PatientRecord *lily = new PatientRecord(
        "P100", "Lily", "02-04-1997",
        "Panadol", "500mg", 11.30,
        67.2, 80, 67.45,
        "Flu Symptoms", "Dr. James", "02-02-2026");

    lily->displayRecord();
    delete lily;

    return 0;
}
