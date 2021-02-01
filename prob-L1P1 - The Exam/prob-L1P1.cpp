#include <iostream>
using namespace std;

typedef struct Exam_ {
    string fristname;
    string lastname;
    float score;
} Exam;

int main(){
    int i, n, count=0;
    float standard;
    cin >> n;
    Exam students[n];
    for(i=0; i<n; i++){
        cin >> students[i].fristname >> students[i].lastname >> students[i].score;
    }
    cin >> standard;
    for(i=0; i<n; i++){
        if(students[i].score >= standard){
            count++;
        }
    }
    cout << count << "\n";
    for(i=0; i<n; i++){
        if(students[i].score >= standard){
            cout << students[i].fristname << " " << students[i].lastname << "\n";
        }
    }
}