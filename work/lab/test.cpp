#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>
using namespace std;
vector<vector<double>> input_data(){

    ifstream file("distance.csv"); // 替換為你的 CSV 文件名稱或路徑

    if (!file) {
        cerr << "無法打開文件。" << endl;
    }

    vector<vector<string>> str_data; // 存儲解析後的 CSV 數據

    string line;
    while (getline(file, line)) {
        vector<string> row;
        stringstream ss(line);
        string cell;

        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        str_data.push_back(row);
    }

    file.close();
    vector<vector<double>> douData;
    for (const auto& row : str_data) {
        vector<double> douRow;

        for (const auto& cell : row) {
            double number = stod(cell);
            douRow.push_back(number);
        }

        douData.push_back(douRow);
    }

    return douData;
}




int main(){
    vector<vector<double>> data=input_data();
    int a[52];
    int j=0;
    for(int i:a){
        i=j++;
    }
    

} 