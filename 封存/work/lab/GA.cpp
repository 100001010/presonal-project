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
//-----------------------------------------------------------------------------------------------
int const group_number=100;
int const stand_number=52;
int const checker_number=3;
int const generations_number=100;
//-----------------------------------------------------------------------------------------------

class Gene{
    public:
        vector<int> gene;

        Gene(int length){
            gene.resize(length);
        }
};

class Checkpoint:public Gene{
    public:

        Checkpoint():Gene(stand_number){
            for(int j=0;j<stand_number;j++){
                   gene[j]=j;
            }
            // 使用隨機數引擎來生成隨機數
            std::random_device rd;
            std::mt19937 rng(rd());

            // 使用 std::shuffle() 函數對陣列進行隨機排序
            std::shuffle(gene.begin(), gene.end(), rng);
        }

};

class Checker:public Gene{
    private:
        double max_distance;
        double distance[checker_number];
    public:
        Checker():Gene(checker_number),max_distance(0){
            int remain_checkpoint_count=stand_number;
            
                for(int &i:gene){
                
                if(remain_checkpoint_count){
                    i=rand()%remain_checkpoint_count+1;
                    remain_checkpoint_count-=i;
                }
            }
            gene[2]+=remain_checkpoint_count;
            cout<<remain_checkpoint_count;

            max_distance=0;
            for(double &i: distance)
                i=0;
            
            
        }
};

class individual{
    public:
        int adaptability_ranking;
        Checkpoint check_point;
        Checker checker;

        individual():adaptability_ranking(-1),checker(),check_point(){}
};

class Group{
    public:
        individual checker[group_number];
        Group(){
            for(individual &i:checker){
                i=individual();
            }
        }

};

//-----------------------------------------------------------------------------------------------
vector<vector<double>> input_data();
void adaptability_rank(Group &group);

//-----------------------------------------------------------------------------------------------
int main() {
    srand(time(NULL));
    vector<vector<double>> data=input_data();
    Group group;

    return 0;
}
//-----------------------------------------------------------------------------------------------

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

void adaptability_rank(Group &group){
    for(individual &i:group.checker){
        int visited_stations_number;
        for(int &j:i.checker.gene){
            for(int )
        }
    }
}
