#include <iostream>
#include <string>
using namespace std;
class FitnessTracker{
    private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    double caloriesBurned;
    public:
    void setUserName(string name){
        userName = name;
    }
    void setGoal(int goal){
        dailyStepGoal = goal;
    }
    void setSteps(int steps){
        stepsTaken =+ steps;
    }
    void calculateCalories(){
        caloriesBurned = (stepsTaken) * 0.5;
    }
    void display(){
        cout << "-----------------------------------\n";
        cout << "User Name : " << userName << endl;
        cout << "Daily Step Goal : " << dailyStepGoal << endl;
        cout << "Steps Taken : " << stepsTaken << " out of " << dailyStepGoal <<endl;
        cout << "Calories Burned : " << caloriesBurned << endl;
        stepsTaken >= dailyStepGoal ? cout << "Congratulations! You have achieved your goal\n" : cout << "You are " << dailyStepGoal - stepsTaken << " steps away from your goal\n";
    }


};
int main(){
    FitnessTracker user;
    cout << "Enter user name : ";
    string userName;
    getline(cin,userName);
    user.setUserName(userName);
    cout << "Enter daily step goal : ";
    int goal;
    cin >> goal;
    user.setGoal(goal);
    cout << "Enter steps taken : ";
    int steps;
    cin >> steps;
    user.setSteps(steps);
    user.calculateCalories();
    user.display();
    return 0;
}