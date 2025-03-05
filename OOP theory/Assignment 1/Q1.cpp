#include <iostream>
#include <cstring>

using namespace std;

class Skill {
private:
    int skillID;
    char skillName[50];
    char description[100];

public:
    Skill(int id, char* name, char* desc) : skillID(id) {
        strcpy(skillName, name);
        strcpy(description, desc);
    }
    void getSkillName() {
        cout << skillName << "\n";
    }

    void showSkillDetails() {
        cout << "Skill ID: " << skillID << "\n";
        cout << "Skill Name: " << skillName << "\n";
        cout << "Description: " << description << "\n";
    }

    void updateSkillDescription(char* newDescription) {
        strcpy(description, newDescription);
        cout << "Skill description updated.\n";
    }
};

class Sport {
private:
    int sportID;
    char name[50];
    char description[100];
    Skill* requiredSkills[10];
    int skillCount;

public:
    Sport(int id, char* sportName, char* desc) : sportID(id), skillCount(0) {
        strcpy(name, sportName);
        strcpy(description, desc);
    }

    void addSkill(Skill* s) {
        if (skillCount < 10) {
            requiredSkills[skillCount++] = s;
            cout << "Skill added to sport.\n";
        } else {
            cout << "Cannot add more skills.\n";
        }
    }

    void removeSkill(Skill* s) {
        for (int i = 0; i < skillCount; i++) {
            if (requiredSkills[i] == s) {
                for (int j = i; j < skillCount - 1; j++) {
                    requiredSkills[j] = requiredSkills[j + 1];
                }
                skillCount--;
                cout << "Skill removed from sport.\n";
                return;
            }
        }
        cout << "Skill not found in sport.\n";
    }

    void showSportDetails() {
        cout << "Sport ID: " << sportID << "\n";
        cout << "Name: " << name << "\n";
        cout << "Description: " << description << "\n";
        cout << "Required Skills: ";
        for (int i = 0; i < skillCount; i++) {
            requiredSkills[i]->getSkillName();
        }
        cout << "\n";
    }
};

class Mentor;

class Student {
private:
    int studentID;
    char name[50];
    int age;
    char sportsInterests[10][30];
    int sportsCount;
    Mentor* mentorAssigned;

public:
    Student(int id, char* studentName, int studentAge) : studentID(id), age(studentAge), sportsCount(0), mentorAssigned(nullptr) {
        strcpy(name, studentName);
    }

    void getDetails() {
        cout << "Student ID: " << studentID << "\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Sports Interests: ";
        for (int i = 0; i < sportsCount; i++) {
            cout << sportsInterests[i] << " ";
        }
        cout << "\n";
    }

    void registerForMentorship(Mentor* m);
    void viewMentorDetails();
    void updateSportsInterest(char* sport);
};

class Mentor {
private:
    int mentorID;
    char name[50];
    char sportsExpertise[10][30];
    int expertiseCount;
    int maxLearners;
    Student* assignedLearners[100];
    int learnerCount;

public:
    Mentor(int id, char* mentorName, int maxL) : mentorID(id), maxLearners(maxL), expertiseCount(0), learnerCount(0) {
        strcpy(name, mentorName);
    }

    void getDetails() {
        cout << "Mentor ID: " << mentorID << "\n";
        cout << "Name: " << name << "\n";
        cout << "Sports Expertise: ";
        for (int i = 0; i < expertiseCount; i++) {
            cout << sportsExpertise[i] << " ";
        }
        cout << "\n";
    }

    bool assignLearner(Student* s) {
        if (learnerCount < maxLearners) {
            assignedLearners[learnerCount++] = s;
            return true;
        }
        return false;
    }

    void removeLearner(Student* s) {
        for (int i = 0; i < learnerCount; i++) {
            if (assignedLearners[i] == s) {
                for (int j = i; j < learnerCount - 1; j++) {
                    assignedLearners[j] = assignedLearners[j + 1];
                }
                learnerCount--;
                cout << "Student removed from mentorship.\n";
                return;
            }
        }
        cout << "Student not found in mentor's list.\n";
    }

    void addExpertise(char* sport) {
        if (expertiseCount < 10) {
            strcpy(sportsExpertise[expertiseCount++], sport);
        } else {
            cout << "Maximum sports expertise reached.\n";
        }
    }

    void viewAssignedLearners() {
        cout << "Assigned Learners:\n";
        for (int i = 0; i < learnerCount; i++) {
            assignedLearners[i]->getDetails();
        }
    }

    void provideGuidance() {
        cout << "Providing guidance to assigned learners.\n";
    }
};

void Student::registerForMentorship(Mentor* m) {
    if (m->assignLearner(this)) {
        mentorAssigned = m;
    } else {
        cout << "Mentor has reached maximum capacity.\n";
    }
}

void Student::viewMentorDetails() {
    if (mentorAssigned) {
        mentorAssigned->getDetails();
    } else {
        cout << "No mentor assigned.\n";
    }
}

void Student::updateSportsInterest(char* sport) {
    if (sportsCount < 10) {
        strcpy(sportsInterests[sportsCount++], sport);
        cout << "Sports interest updated.\n";
    } else {
        cout << "Maximum sports interests reached.\n";
    }
}

int main() {
    Mentor mentor1(1, "Muhammad Soofiyan", 2);
    mentor1.addExpertise("Cricket");
    mentor1.addExpertise("Football");

    Mentor mentor2(2, "Muhammad Affan", 1);
    mentor2.addExpertise("Basketball");
    mentor2.addExpertise("Swimming");

    Student student1(101, "Ahmed", 20);
    Student student2(102, "Hamza", 21);
    Student student3(103, "Ali", 22);

    student1.registerForMentorship(&mentor1);
    student2.registerForMentorship(&mentor1);
    student3.registerForMentorship(&mentor2);

    cout << "-----------------------------------\n";
    cout << "Student 1 Details:\n";
    student1.viewMentorDetails();
    cout << "-----------------------------------\n";
    cout << "Student 2 Details:\n";
    student2.viewMentorDetails();
    cout << "-----------------------------------\n";
    cout << "Student 3 Details:\n";
    student3.viewMentorDetails();

    student1.updateSportsInterest("Basketball");
    student2.updateSportsInterest("Swimming");

    cout << "-----------------------------------\n";
    cout << "Mentor 1 Details:\n";
    mentor1.viewAssignedLearners();
    cout << "-----------------------------------\n";
    cout << "Mentor 2 Details:\n";
    mentor2.viewAssignedLearners();

    cout << "-----------------------------------\n";
    mentor1.provideGuidance();
    cout << "-----------------------------------\n";
    mentor2.provideGuidance();
    cout << "-----------------------------------\n";

    mentor1.removeLearner(&student1);
    cout << "-----------------------------------\n";
    mentor1.viewAssignedLearners();

    return 0;
}
