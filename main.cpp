#include <iostream>
using namespace std;

void insertData(int day[], int month[], int year[], string name[], int n){
    for (int i=0; i<n; i++){
        cout << "Enter your name!";
        cin >> name[i];
        cout << "Enter the date in which u were born!";
        cin >> day[i];
        cout << "Enter the month in which u were born!";
        cin >> month[i];
        cout << "Enter the year in which u were born!";
        cin >> year[i];
        cout << endl;

    }
}

void displayData(int dayOld[], int monthOld[], int yearOld[], string name[], int n){
    for (int i=0; i<n; i++){
        cout << name[i] << " is " << yearOld[i] << " years " << monthOld[i] << " months and " << dayOld[i] <<  " days old" <<   endl;
    }
}


void calculateAgeInDays(int ageInDays[], int dayOld[], int monthOld[], int yearOld[], int n){
    for (int i=0; i<n; i++){
        ageInDays[i] = dayOld[i] + monthOld[i] * 30 + yearOld[i] * 365;
    }
}

void sortArray(int ageInDays[], string name[], int x){
    for (int i=0; i < x - 1; i++){
        for (int j=0; j < x - 1 - i; j++){
            if (ageInDays[j] > ageInDays[i+1]){
                int temp1 = ageInDays[j];
                ageInDays[j] = ageInDays[j+1];
                ageInDays[j+1] = temp1;

                string temp2 = name[j];
                name[j] = name[j+1];
                name[j+1] = temp2;
            }
        }
    }
}

void oldestYoungest(string name[], int n){
    cout << "The youngest person is " << name[0] << endl;
    cout << "The oldest person is " << name[n-1] << endl;
}

int main() {
    int currentDay;
    int currentMonth;
    int currentYear;

    cout << "Enter the current date!";
    cin >> currentDay;
    cout << "Enter the current month!";
    cin >> currentMonth;
    cout << "Enter the current year!";
    cin >> currentYear;
    
    int n;
    cout << "How many people would you like to calculate?";
    cin >> n;
    int day[n];
    int month[n];
    int year[n];
    string name[n];
    
    int dayOld[n];
    int monthOld[n];
    int yearOld[n];

    insertData(day, month, year, name, n);

    for (int i=0; i<n; i++){
        if(currentDay >= day[i]){
            dayOld[i] = currentDay - day[i];
        } else {
            dayOld[i] = currentDay + 30 - day[i];
            currentMonth--;
        }
        if(currentMonth >= month[i]){
            monthOld[i] = currentMonth - month[i];
        } else {
            monthOld[i] = currentMonth + 12 - month[i];
            currentYear--;
        }

        yearOld[i] = currentYear - year[i];
    }

    displayData(dayOld, monthOld, yearOld, name, n);

    int ageInDays[n];
    calculateAgeInDays(ageInDays, dayOld, monthOld, yearOld, n);
    sortArray(ageInDays, name, n);
    oldestYoungest(name, n);
    
}