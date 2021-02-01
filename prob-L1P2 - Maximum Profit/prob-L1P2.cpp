#include <iostream>
using namespace std;

typedef struct Profitperday_ {
    int buy_index, sell_index;
    float profit;
} Profitperday;

int main(){
    int i, j, n, profit_index, p=0, max_profit=0;

    cin >> n;

    int pair = (n*(n-1))/2;
    float price[n];
    Profitperday data[pair];
    
    for(i=0; i<n; i++){
        cin >> price[i];
    }

    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++)
        {
            data[p].buy_index = i;
            data[p].sell_index = j;
            data[p].profit = price[j]-price[i];
            p++;
        }
    }

    for(i=0; i<pair; i++){
        if(data[i].profit>max_profit){
            max_profit = data[i].profit;
            profit_index = i;
        }
    }

    if(max_profit>0){
        cout << data[profit_index].buy_index+1 << " " << data[profit_index].sell_index+1 << " " << data[profit_index].profit;
    }

    else{
        cout << "No profit";
    }
}