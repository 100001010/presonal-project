#include<iostream>
#include <fstream>
#include <string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;
class Time{
    public:
        int y,m,d,h,min,s;
        void acelin_input(string str){
            stringstream string_to_int;
            int i;
            for(char &c:str){
                if(c=='-'||c==':')
                    c=' ';
            }
            str+=" ";
            string_to_int<<str;
            string_to_int>>y;
            string_to_int<<str;
            string_to_int>>m;
            string_to_int<<str;
            string_to_int>>d;
            string_to_int<<str;
            string_to_int>>h;
            string_to_int<<str;
            string_to_int>>min;
            string_to_int<<str;
            string_to_int>>s;
                
            
        }
        void aaeon_input(string str){
            stringstream string_to_int;
            int i;
            for(char &c:str){
                if(c=='/'||c==':'||c==',')
                    c=' ';
            }
            str+=" ";

            string_to_int<<str;
            string_to_int>>d;
            string_to_int<<str;
            string_to_int>>m;
            string_to_int<<str;
            string_to_int>>y;
            string_to_int<<str;
            string_to_int>>h;
            string_to_int<<str;
            string_to_int>>min;
            string_to_int<<str;
            string_to_int>>s; 
        }
        void print(){
            cout<<"y:"<<y<<"m:"<<m<<"d:"<<d<<"h:"<<h<<"min:"<<min<<"s:"<<s<<endl;
            
        }
};
class Plate_data{
    public:
        Time time;
        vector <string> plate;
        bool white;
        bool direction;//in=1,out=0
};
class Final_plate_data{
    public:
        Plate_data acelin;
        Plate_data aaeon;
        Plate_data dvr;
};

void push_acelin_data(queue <Plate_data> &que){
    ifstream acelin;
    acelin.open("../../ch1/acelin.txt");
    string line;
    while (getline(acelin, line)) {
        Plate_data temp;
        que.push(temp);
        string s_t;
        que.back().plate.push_back(s_t);
        int semicolon_num=0;
        string str_time;
        for(char c:line){
            if(c=='\"'){
                semicolon_num++;
                continue;
            }
            if(semicolon_num==1){
                if(c!='-')
                    que.back().plate[0]+=c;
            }
            if(semicolon_num==3){
                str_time+=c;
            }
            if(semicolon_num==5){
                if(c=='E')
                    que.back().white=1;
                else
                    que.back().white=0;
            }
        }
        que.back().time.acelin_input(str_time);
    }
}
string get_aaeon_plate(string targat){
    string r;
    int brackets_num=0;
    for(char i:targat){
        if(i=='['||i==']'){
            brackets_num++;
            continue;
        }
        if(brackets_num==3){
            if(i==',')
                break;
            if(i!='\'')
            r+=i;
        }
    }
    return r;
}
void push_aaeon_data(queue <Plate_data> &que){
    ifstream aaeon;
    aaeon.open("../../ch1/event_log_1.txt");
    string line;
    long int time_total,next_time_total=0;
    bool find_white=0;
    while(getline(aaeon,line)){
         
        if(line[23]=='r')
            continue;

        time_total=(line[13]*10+line[14])*3600+(line[16]*10+line[17])*60+(line[19]*10+line[20]);
        if(time_total-next_time_total>30||time_total-next_time_total<0){
            if(find_white)
                que.back().white=1;
            find_white=0;
            Plate_data temp;
            que.push(temp);
            que.back().time.aaeon_input(line.substr(1, 20));
            
        }
        next_time_total=time_total;

        
        if(line[23]=='w'){
            find_white=1;
            que.back().plate.assign(1,get_aaeon_plate(line));

        }else{
            if(!find_white)
                que.back().plate.push_back(get_aaeon_plate(line));
        }
            
        
        
    }
    if(find_white)
        que.back().white=1;
}
void push_dvr_data(queue <Plate_data> &que){
    ifstream acelin;
    acelin.open("../../ch1/event_log_1(2).csv");
    string line;
    while (getline(acelin, line)) {
        Plate_data temp;
        que.push(temp);
        string s_time,s_plate,s_direction;
        int semicolon_num=0;
        for(char c:line){
            if(c==','){
                semicolon_num++;
                continue;
            }
            if (semicolon_num<2)
            {
            }else if(semicolon_num<3)
                s_plate+=c;
            else if(semicolon_num<4)
                s_direction+=c;
            
        }
        s_time=line.substr(1,20);
        //cout<<s_time<<endl;
        que.back().time.aaeon_input(s_time);
        que.back().plate.push_back(s_plate);
        que.back().direction=s_direction[0]-'0';


    }
}
void print_queue_data(queue <Plate_data> que){
    while(!que.empty()){
        que.front().time.print();
        for(auto i:que.front().plate)
            cout<<i<<" ";
        cout<<endl;
        cout<<que.front().direction<<endl;
        cout<<que.front().white<<endl<<"---------------"<<endl;
        que.pop();
        
    }
}
void unify(queue <Plate_data> acelin,queue <Plate_data> aaeon,queue <Plate_data> dvr,queue <Final_plate_data> &final){
    while(!acelin.empty()&&!aaeon.empty()&&!dvr.empty()){
        Final_plate_data temp_push;
        final.push(temp_push);
    }
}
int main(){
    queue <Plate_data> acelin_data;
    queue <Plate_data> aaeon_data;
    queue <Plate_data> dvr_data;
    queue <Final_plate_data> final_data;
    //freopen("aaeon_test.txt","w",stdout);
    push_acelin_data(acelin_data);
    push_aaeon_data(aaeon_data);
    push_dvr_data(dvr_data);
    //print_queue_data(acelin_data);
    //print_queue_data(aaeon_data);
    //print_queue_data(dvr_data);
    unify(acelin_data,aaeon_data,dvr_data,final_data);

    

}