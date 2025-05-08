#include<bits/stdc++.h>
using namespace std;

class HospitalSystem{
    private:
    struct Disease{
        vector<string> sympton;
        string desc;
        string treatment;
    };

    map<string, Disease> knowledgeBase;

    public:
    HospitalSystem(){
        knowledgeBase["flu"] = {
            {"fever", "cough", "sore throat"},
            "A common viral infection causing fever, cough, and sore throat.",
            "Rest, fluids, antiviral medications"
        };
        knowledgeBase["Diabetes"] = {
            {"fatigue", "frequent urination", "blurred vision"},
            "A chronic condition affecting blood sugar processing.",
            "Insulin therapy, healthy diet, regular exercise"
        };
        knowledgeBase["Hypertension"] = {
            {"headache", "dizziness", "chest pain"},
            "High blood pressure often with no symptoms.",
            "Lifestyle changes, blood pressure medication"
        };
    }


    void diagnose(vector<string> userInput){
        string liklyDisease;
        int totalmatch = 0;

        for (auto &entry : knowledgeBase){
            string diease = entry.first;
            Disease info  = entry.second;
            int matchcount = 0;

            for (auto &s : userInput){
                for(auto sy : info.sympton){
                    if(s == sy){
                        matchcount++;
                    }
                }
            }

            if(matchcount > totalmatch){
                totalmatch = matchcount;
                liklyDisease = diease;
            }
        }

        if (!liklyDisease.empty()) {
            cout << "\nPossible Disease: " << liklyDisease << endl;
            cout << "Description: " << knowledgeBase[liklyDisease].desc << endl;
            cout << "Treatment: " << knowledgeBase[liklyDisease].treatment << endl;
        } else {
            cout << "\nNo matching disease found." << endl;
        }
    }
};

int main(){
    HospitalSystem system;
    vector<string> symptoms;
    string input;

    cout << "Enter symptoms one by one (type 'done' to finish):\n";
    while (true) {
        cout << "Symptom: ";
        getline(cin, input);
        if (input == "done") break;
        symptoms.push_back(input);
    }

    system.diagnose(symptoms);
    return 0;
}