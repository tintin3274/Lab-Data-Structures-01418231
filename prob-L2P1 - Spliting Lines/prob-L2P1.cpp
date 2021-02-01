#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 
using namespace std;

typedef struct Student_ {
string name;
int height;
} Student;

bool compareTwoStudents(Student s1, Student s2) 
{ 
    return (s1.height < s2.height); 
} 

int main(){
    int i, n, row, count;
    cin >> n;
    Student student[n];
    for(i=0; i<n; i++){
        cin >> student[i].name >> student[i].height;
    }
    cin >> row;
    sort(student, student+n, compareTwoStudents);
    cout << int(ceil(float(n)/row)) << endl;
    for(i=0; i<n; i++){
        if(i%row == 0){
            cout << student[i].name << endl;
        }
    }
}