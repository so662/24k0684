#include <iostream>
#include <string>
using namespace std;

void Task_01(string city[4], int AQI[][28])
{
    int avg[4] = {0}, max = 0, max_avg_city = 0;

    cout << "\n----- Weekly AQI Averages -----\n";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            avg[i] += AQI[i][j];
        }
        avg[i] /= 7;

        cout << "Average AQI for " << city[i] << ": " << avg[i] << endl;

        if (avg[i] > max)
        {
            max = avg[i];
            max_avg_city = i;
        }
    }

    cout << "\nThe city with the worst air quality this week is **" << city[max_avg_city]
         << "** with an AQI of " << max << ".\n";
}

void Task_02(int AQI[][28], string city[])
{
    cout << "\n----- Critical Pollution Days (AQI > 150) -----\n";

    bool found = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (AQI[i][j] > 150)
            {
                cout << "**" << city[i] << "** had a critical pollution level on Day " << j + 1
                     << " (AQI: " << AQI[i][j] << ")\n";
                found = true;
            }
        }
    }

    if (!found)
        cout << "Good news! No city had an AQI above 150 this week.\n";
}

void Task_03(int AQI[][28], string city[])
{
    cout << "\n----- AQI Visualization (Bar Chart) -----\n";

    for (int i = 0; i < 4; i++) 
    {
        cout << "\n**" << city[i] << "** AQI Graph:\n";

        for (int j = 0; j < 7; j++)
        {
            cout << "Day " << j + 1 << ": ";
            int bars = AQI[i][j] / 5;
            for (int k = 0; k < bars; k++)
            {
                cout << "*";
            }
            cout << " (" << AQI[i][j] << ")\n";
        }
    }
}

void Task_04(string city[4], int AQI[][28])
{
    int monthlyAvg[4] = {0}, firstWeekAvg[4] = {0}, lastWeekAvg[4] = {0}, maxDropCity = 0;
    int maxDrop = 0;

    cout << "\n----- Monthly AQI Comparison -----\n";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            monthlyAvg[i] += AQI[i][j];
            if (j < 7)
            {
                firstWeekAvg[i] += AQI[i][j];
            }
            if (j >= 21)
            {
                lastWeekAvg[i] += AQI[i][j];
            }
        }
        monthlyAvg[i] /= 28;
        firstWeekAvg[i] /= 7;
        lastWeekAvg[i] /= 7;

        cout << "Monthly AQI of " << city[i] << " is " << monthlyAvg[i] << endl;

        int drop = firstWeekAvg[i] - lastWeekAvg[i];
        if (drop > maxDrop)
        {
            maxDrop = drop;
            maxDropCity = i;
        }
    }
    cout << "City with most improved air quality: " << city[maxDropCity] << " with AQI drop of " << maxDrop << endl;
}

void Task_05(string city[4], int AQI[][28])
{
    int monthlyAvg[4] = {0}, highestAQI = 0, lowestAQI = 1000, highestCity = 0, lowestCity = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            monthlyAvg[i] += AQI[i][j];
        }
        monthlyAvg[i] /= 28;

        if (monthlyAvg[i] > highestAQI)
        {
            highestAQI = monthlyAvg[i];
            highestCity = i;
        }
        if (monthlyAvg[i] < lowestAQI)
        {
            lowestAQI = monthlyAvg[i];
            lowestCity = i;
        }
    }

    cout << "\n---- AQI Report ----\n";
    cout << "Weekly AQI Averages:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << city[i] << ": " << monthlyAvg[i] << endl;
    }

    cout << "City with highest AQI: " << city[highestCity] << " (AQI " << highestAQI << ")\n";
    cout << "City with lowest AQI: " << city[lowestCity] << " (AQI " << lowestAQI << ")\n";
}

int main()
{
    int AQI[4][28];
    string city[4];
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter city " << i + 1 << " : ";
        cin >> city[i];
    }
    cout << endl
         << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter details for city " << i + 1 << endl;
        for (int j = 0; j < 28; j++)
        {
            cout << "Enter temp for Day " << j + 1 << " : ";
            cin >> AQI[i][j];
        }
    }
    int choice;
    do
    {
        cout << "\n------------ Modded By Soofiyan Imran -------------\n";
        cout << "1. Calculate 1st Week AQI Average\n";
        cout << "2. Identify Critical Pollution Days in first week \n";
        cout << "3. AQI Visualization for 1st week\n";
        cout << "4. Monthly AQI Comparison\n";
        cout << "5. Generate AQI Repor(Monthly)t\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Task_01(city, AQI);
            break;
        case 2:
            Task_02(AQI, city);
            break;
        case 3:
            Task_03(AQI, city);
            break;
        case 4:
            Task_04(city, AQI);
            break;
        case 5:
            Task_05(city, AQI);
            break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
