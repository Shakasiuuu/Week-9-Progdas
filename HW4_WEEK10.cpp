#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits>
#include <string>
using namespace std;

const int MAX = 20;

struct studentType{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

bool isDuplicate(studentType st[], int idx, string fn, string ln){
    for(int i=0; i<idx; i++){
        if(st[i].studentFName == fn && st[i].studentLName == ln){
            return true;
        }
    }
    return false;
}

void readData(studentType st[]){
    for(int i=0; i<MAX; i++){

        while(true){
            cout << "Masukkan first name mahasiswa ke-" << i+1 << ": ";
            getline(cin, st[i].studentFName);

            cout << "Masukkan last name mahasiswa ke-" << i+1 << ": ";
            getline(cin, st[i].studentLName);

            if(st[i].studentFName.empty() || st[i].studentLName.empty()){
                cout << "NAMA TIDAK BOLEH KOSONG!\n\n";
                continue;
            }

            if(isDuplicate(st, i, st[i].studentFName, st[i].studentLName)){
                cout << "NAMA SUDAH ADA ! tolong masukkan nama berbeda.\n\n";
            } else {
                break;
            }
        }

        while(true){
            cout << "Masukkan nilai (0-100): ";
            string temp;
            getline(cin, temp);

            bool allDigit = true;
            for(char c : temp){
                if(!isdigit(c)){
                    allDigit = false;
                    break;
                }
            }

            if(!allDigit){
                cout << "data tidak memenuhi syarat! nilai harus ANGKA 0-100\n";
                continue;
            }

            st[i].testScore = stoi(temp);

            if(st[i].testScore >= 0 && st[i].testScore <= 100){
                break;
            }
            else{
                cout << "data tidak memenuhi syarat! nilai harus 0-100\n";
            }
        }
        cout << endl;
    }
}

void assignGrade(studentType st[]){
    for(int i=0; i<MAX; i++){
        int score = st[i].testScore;
        if(score >= 90) st[i].grade = 'A';
        else if(score >= 80) st[i].grade = 'B';
        else if(score >= 70) st[i].grade = 'C';
        else if(score >= 60) st[i].grade = 'D';
        else st[i].grade = 'F';
    }
}

int highestScore(studentType st[]){
    int highest = st[0].testScore;
    for(int i=1; i<MAX; i++){
        if(st[i].testScore > highest)
            highest = st[i].testScore;
    }
    return highest;
}

void printHighest(studentType st[], int highest){
    cout << "\n\nMurid dengan nilai tertinggi ("<< highest <<"):\n";
    cout << "==========================================\n";
    cout << left << setw(30) << "FIRST LAST" << " | SCORE | GRADE\n";
    cout << "==========================================\n";
    for(int i=0; i<MAX; i++){
        if(st[i].testScore == highest){
            string nama = st[i].studentFName + " " + st[i].studentLName;
            cout << left << setw(30) << nama;
            cout << " | " << setw(5) << st[i].testScore;
            cout << " |   " << st[i].grade << endl;
        }
    }
}

void printData(studentType st[]){
    cout << "\n==============================================================\n";
    cout << left << setw(40) << "LAST NAME, FIRST NAME" << " | SCORE | GRADE\n";
    cout << "==============================================================\n";

    for(int i=0; i<MAX; i++){
        string nama = st[i].studentLName + ", " + st[i].studentFName;
        cout << left << setw(40) << nama;
        cout << " | " << setw(5) << st[i].testScore;
        cout << " |   " << st[i].grade << endl;
    }
}

int main(){

    studentType students[MAX];

    // buang newline sisa start program
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    readData(students);
    assignGrade(students);
    printData(students);

    int h = highestScore(students);
    printHighest(students, h);

    return 0;
}
