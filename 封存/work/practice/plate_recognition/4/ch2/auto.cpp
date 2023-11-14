#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
#include<cmath>
#include<set>
using namespace std;


//note-------------------------------------------------------------
/*
    1.因為車牌不一定會在白名單裡，所以將肉眼辨識的車牌當成真正的白名單
*/
//const------------------------------------------------------------
const char cha='2';
const string acelin_csv="license_export-20230804.csv";
const string aaeon_txt="event_log_1.txt";
const string dvr_csv="dvr.csv";
const string out_csv="ch2.csv";
//class------------------------------------------------------------
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
        string fprint(){
            string r,t;
            stringstream itos;
            itos<<y;
            itos>>t;
            r+=t+"/";
            t="";
            itos.clear();
            itos<<d;
            itos>>t;
            r+=t+"/";
            t="";
            itos.clear();
            itos<<m;
            itos>>t;
            r+=t+",";
            t="";
            itos.clear();
            itos<<h;
            itos>>t;
            r+=t+":";
            t="";
            itos.clear();
            itos<<min;
            itos>>t;
            r+=t+":";
            t="";
            itos.clear();
            itos<<s;
            itos>>t;
            r+=t;
            return "\""+r+"\"";
        }
        long long int time_to_sec(){
            return ((((m*32+d)*24+h)*60+min)*60+s);
        }
        int operator-(Time t2){
            return time_to_sec()-t2.time_to_sec();
        }
        void operator=(Time t2){
            y=t2.y;
            m=t2.m;
            d=t2.d;
            h=t2.h;
            min=t2.min;
            s=t2.s;
        }
        bool operator==(Time t2){
            int time_1_total=this->time_to_sec();
            int time_2_total=t2.time_to_sec();
            return time_1_total==time_2_total;
        }
        bool operator>(Time t2){
            int time_1_total=this->time_to_sec();
            int time_2_total=t2.time_to_sec();
            return time_1_total>time_2_total;
        }
        bool operator<(Time t2){
            int time_1_total=this->time_to_sec();
            int time_2_total=t2.time_to_sec();
            return time_1_total<time_2_total;
        }
};
class Plate_data{
    public:
        Time time;
        vector <string> plate;
        bool white;
        bool vague;
        bool have_data;
        bool direction;//in=1,out=0
    void operator=(Plate_data p2){
        time=p2.time;
        plate=p2.plate;
        white=p2.white;
        direction=p2.direction;
        vague=p2.vague;
        have_data=p2.have_data;
    }
};
class Final_plate_data{
    public:
        Plate_data acelin;
        Plate_data aaeon;
        Plate_data dvr;
};
class Aaeon_delay{

    public:
    Time dvr_time;
    Time aaeon_time;
    int delay_s;
    int count_30;
    int count_60;
    int count_90;
};
//function---------------------------------------------------------
int editdistance(const string& word1, const string& word2) {
    int m = word1.size();
    int n = word2.size();
    
    // Create a 2D DP table to store edit distances
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Initialize base cases
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }
    
    // Fill in the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    
    return dp[m][n];
}
void push_acelin_data(queue <Plate_data> &que,set <string> &dvr_white_list){
    
    ifstream acelin;
    acelin.open(acelin_csv);
    string line;
    stack <Plate_data> sta;//因為acelin的資料是反的，所以先用stack裝，再依序放入queue
    bool sta_pop=0;//因為acelin的資料有ch1跟ch2，所以不需要的資料要刪掉

    while (getline(acelin, line)) {

        Plate_data temp;
        sta.push(temp);

        string plate_push_temp;
        sta.top().plate.push_back(plate_push_temp);

        int semicolon_num=0;//分號出現的次數

        string str_time;//時間資料
        bool find_white=0;

        for(char c:line){
            if(c=='\"'){
                semicolon_num++;
                continue;
            }

            if(semicolon_num==1){//記錄車牌
                if(c!='-')
                    sta.top().plate[0]+=c;

            }else if(semicolon_num==3){//記錄時間
                str_time+=c;
                
            }else if(semicolon_num==7){//判斷是哪個ch
                if(!(c=='C'||c=='H'||c=='-'||c==cha)){//如果不是我要的ch，這筆資料就丟掉
                    sta.pop();
                    sta_pop=1;
                }
                    
            }
        }

        if(sta_pop){
            sta_pop=0;
            continue;
        }

        if(dvr_white_list.count(sta.top().plate[0])){//在白名單裡找這台車
            sta.top().white=1;
            sta.top().vague=1;

        }else {//跟所有的白名單比較，判斷這是否是模糊資料
            sta.top().white=0;
            bool vague=0;
            for (const auto &s : dvr_white_list) {
                if(editdistance(s,sta.top().plate[0])<=2)//編輯距離小於二定義為模糊資料
                    vague=1;
            }
            sta.top().vague=vague;
        }
        
        sta.top().time.acelin_input(str_time);

        sta.top().have_data=1;
        
    }
    while(!sta.empty()){
        que.push(sta.top());
        sta.pop();
    }


    acelin.close();
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
void push_aaeon_data(queue <Plate_data> &que,set <string> &dvr_white_list){
    ifstream aaeon;
    aaeon.open(aaeon_txt);
    string line;
    long int time_total,next_time_total=0;
    bool find_white=0,find_vague=0;
    while(getline(aaeon,line)){
         
        if(line[23]=='r')
            continue;

        time_total=(line[13]*10+line[14])*3600+(line[16]*10+line[17])*60+(line[19]*10+line[20]);
        if(time_total-next_time_total>30||time_total-next_time_total<0){
            if(find_white){
                que.back().white=1;
                que.back().vague=1;
                //cout<<que.back().vague;
            }else if(find_vague){
                que.back().white=0;
                que.back().vague=1;

            }else if(!que.empty()){
                que.back().white=0;
                que.back().vague=0;
            }
                
            find_white=0;
            find_vague=0;
            Plate_data temp;
            que.push(temp);
            que.back().have_data=1;
            que.back().time.aaeon_input(line.substr(1, 20));
            
        }
        next_time_total=time_total;

        
        bool vague=0,white=0;
        for (const auto &s : dvr_white_list) {
            if(editdistance(s,get_aaeon_plate(line))==0){
                if(!find_white){
                    que.back().time.aaeon_input(line.substr(1, 20));
                }
                white=1;   
                vague=1;
                break; 
            }else if(editdistance(s,get_aaeon_plate(line))<=2){
                if(!find_white&&!find_vague){
                    que.back().time.aaeon_input(line.substr(1, 20));
                }
                vague=1;
            }
                
        }

        if(white){
            find_white=1;
            
            que.back().plate.assign(1,get_aaeon_plate(line));

        }else if(vague){
            if(!find_white){
                find_vague=1;
                que.back().plate.assign(1,get_aaeon_plate(line));
            }
                
        }else{
            if(!find_white&&!find_vague){
                
                que.back().plate.push_back(get_aaeon_plate(line));
            }
        }
            
        
        
    }
    if(find_white)
        que.back().white=1,que.back().direction=1;
    else
        que.back().white=0,que.back().direction=0;
    aaeon.close();
}
void push_dvr_data(queue <Plate_data> &que,set <string> &dvr_white_list){
    ifstream dvr;
    dvr.open(dvr_csv,ifstream::in);
    string line=" ";
    
    while (getline(dvr, line)) {//cout<<1;
        //cout<<line<<endl;
        Plate_data temp;
        que.push(temp);
        string s_time=" ",s_plate,s_direction;
        int semicolon_num=0;
        for(char c:line){
            //cout<<int(c);
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
        //  cout<<endl;
        //cout<<line<<endl;
        //cout<<line[0]<<endl;
        if(int(line[1])==-69){
            s_time=line.substr(4,20);
        }else
            s_time=line.substr(1,20);
        //cout<<s_time<<"  "<<int(line[1])<<endl;
        que.back().time.aaeon_input(s_time);
        que.back().plate.push_back(s_plate);
        dvr_white_list.insert(s_plate);
        que.back().direction=s_direction[0]-'0';


    }
}
void print_queue_data(queue <Plate_data> que){
    while(!que.empty()){
        que.front().time.print();
        for(auto i:que.front().plate)
            cout<<i<<" ";
        cout<<endl;
        cout<<"direction:"<<que.front().direction<<endl;
        cout<<"vague:"<<que.front().vague<<endl;
        cout<<"white:"<<que.front().white<<endl<<"---------------"<<endl;
        que.pop();
        
    }
}
void unify(queue <Plate_data> acelin,queue <Plate_data> aaeon,queue <Plate_data> dvr,queue <Final_plate_data> &final,set <string> &dvr_white_list,queue <Aaeon_delay> &aaeon_delay){
    queue <Plate_data> not_push_aaeon_data_misjudgment;
        queue <Plate_data> not_push_acelin_data_misjudgment;
    while(!dvr.empty()){
        
        while(!aaeon.empty()&&(aaeon.front().white==0&&aaeon.front().vague==0)){
            //cout<<aaeon.front().plate[0]<<" 411 pop"<<endl;

            int best_editdistance_num=100000;
            string best_plate;
            for(string str_aaeon_plate:aaeon.front().plate){
                for (const auto &s : dvr_white_list) {
                    if(editdistance(s,str_aaeon_plate)<best_editdistance_num){
                        best_editdistance_num=editdistance(s,str_aaeon_plate);
                        best_plate=str_aaeon_plate;
                    }
                        
                }
                
            }


            aaeon.front().plate[0]=best_plate;
            not_push_aaeon_data_misjudgment.push(aaeon.front());
            //cout<<not_push_aaeon_data_misjudgment.size();
            //cout<<not_push_aaeon_data_misjudgment.front().plate[0]<<endl;
            aaeon.pop();
            //Final_plate_data temp_push;
            //final.push(temp_push);
            
        }
        while(!acelin.empty()&&(acelin.front().white==0&&acelin.front().vague==0)){
            //cout<<acelin.front().plate[0]<<" 437 pop"<<endl;
            not_push_acelin_data_misjudgment.push(acelin.front());
            acelin.pop();
            //Final_plate_data temp_push;
            //final.push(temp_push);
        }
        while(!not_push_aaeon_data_misjudgment.empty()&&(not_push_aaeon_data_misjudgment.front().time<dvr.front().time||dvr.front().plate[0]==aaeon.front().plate[0])||!not_push_aaeon_data_misjudgment.empty()&&(not_push_aaeon_data_misjudgment.front().time<dvr.front().time||dvr.front().plate[0]==aaeon.front().plate[0])){
            
            if(!not_push_aaeon_data_misjudgment.empty()&&(not_push_aaeon_data_misjudgment.front().time<dvr.front().time||dvr.front().plate[0]==aaeon.front().plate[0])){
                Final_plate_data temp_push;
                final.push(temp_push);
                final.back().aaeon=not_push_aaeon_data_misjudgment.front();
                //cout<<not_push_aaeon_data_misjudgment.back().plate[0]<<endl;
                not_push_aaeon_data_misjudgment.pop();
            }
            if(!not_push_acelin_data_misjudgment.empty()&&(not_push_acelin_data_misjudgment.front().time<dvr.front().time||dvr.front().plate[0]==acelin.front().plate[0])){
                Final_plate_data temp_push;
                final.push(temp_push);
                final.back().acelin=not_push_acelin_data_misjudgment.front();
                not_push_acelin_data_misjudgment.pop();
            }
            
        }
        
        Final_plate_data temp_push;
        final.push(temp_push);
        final.back().dvr=dvr.front();
        dvr.pop();
        
        if(!aaeon.empty()&&aaeon.front().plate[0]==final.back().dvr.plate[0]){
            //cout<<aaeon.front().plate[0]<<" 466 add final"<<endl<<aaeon.front().vague;
            if(!dvr.empty()&&dvr.front().plate[0]==final.back().dvr.plate[0]&&abs(aaeon.front().time-dvr.front().time)<abs(aaeon.front().time-final.back().dvr.time))
                continue;
            aaeon.front().time.print();
            final.back().dvr.time.print();
            cout<<endl;
            Aaeon_delay temp_aaeon_delay_push;
            aaeon_delay.push(temp_aaeon_delay_push);
            aaeon_delay.back().aaeon_time=aaeon.front().time;
            aaeon_delay.back().dvr_time=final.back().dvr.time;
            final.back().aaeon=aaeon.front();
            //cout<<final.back().aaeon.vague;
            aaeon.pop();    
        }else if(!aaeon.empty()&&editdistance(aaeon.front().plate[0],final.back().dvr.plate[0])<=2){
            //cout<<aaeon.front().plate[0]<<" 472 add final"<<endl<<aaeon.front().vague;
            aaeon.front().time.print();
            final.back().dvr.time.print();
            cout<<endl;
            final.back().aaeon=aaeon.front();
            Aaeon_delay temp_aaeon_delay_push;
            aaeon_delay.push(temp_aaeon_delay_push);
            aaeon_delay.back().aaeon_time=aaeon.front().time;
            aaeon_delay.back().dvr_time=final.back().dvr.time;
            aaeon.pop(); 
        }

        if(!acelin.empty()&&acelin.front().plate[0]==final.back().dvr.plate[0]){
            //cout<<acelin.front().plate[0]<<" 408 add final"<<endl<<acelin.front().vague;
            if(!dvr.empty()&&dvr.front().plate[0]==final.back().dvr.plate[0]&&abs(acelin.front().time-dvr.front().time)<abs(acelin.front().time-final.back().dvr.time))
                continue;
            final.back().acelin=acelin.front();
            //cout<<final.back().acelin.vague;
            acelin.pop();    
        }else if(!acelin.empty()&&editdistance(acelin.front().plate[0],final.back().dvr.plate[0])<=2){
            final.back().acelin=acelin.front();
            //cout<<acelin.front().plate[0]<<" 415 pop"<<endl;
            acelin.pop(); 
        }


        while(!aaeon.empty()&&final.back().dvr.plate[0]==aaeon.front().plate[0]&&dvr.front().plate[0]!=aaeon.front().plate[0]){
            cout<<aaeon.front().plate[0]<<" 422 pop"<<endl;
            aaeon.pop();
        }
        while(!acelin.empty()&&editdistance( final.back().dvr.plate[0],acelin.front().plate[0])<2&&dvr.front().plate[0]!=acelin.front().plate[0]){
            //cout<<acelin.front().plate[0]<<" 426 pop"<<endl;
            acelin.pop();
        }
            
        
    }
}
void print_final_data_csv(queue <Final_plate_data> final){
    ofstream out_file;
    out_file.open(out_csv);
    out_file<<",,aaeon,,,,acelin,,,,方向(0:出/1:進),備註\n";
    out_file<<"時間,肉眼辨識車牌,完全正確,模糊,辨識結果,是否有資料,完全正確,模糊,辨識結果,是否有資料\n";
    while(!final.empty()){
        
        bool dvr_empty=final.front().dvr.plate.empty();
        bool aaeon_empty=final.front().aaeon.plate.empty();
        bool acelin_empty=final.front().acelin.plate.empty();

        if(!dvr_empty)
            out_file<<final.front().dvr.time.fprint()<<",";
        else if(!aaeon_empty)
            out_file<<final.front().aaeon.time.fprint()<<",";
        else 
            out_file<<final.front().acelin.time.fprint()<<",";


        if(!final.front().dvr.plate.empty()){
            out_file<<final.front().dvr.plate[0]<<",";
        }else{
            out_file<<",";
        }
        if(!final.front().aaeon.plate.empty()){
                
            out_file<<final.front().aaeon.white<<",";
            out_file<<final.front().aaeon.vague<<",";
            out_file<<final.front().aaeon.plate[0]<<",";
            out_file<<final.front().aaeon.have_data<<",";
        }else{
            out_file<<",,,,";
        }
        if(!final.front().acelin.plate.empty()){
                
            out_file<<final.front().acelin.white<<",";
            out_file<<final.front().acelin.vague<<",";
            out_file<<final.front().acelin.plate[0]<<",";
            out_file<<final.front().acelin.have_data<<",";
        }else{
            out_file<<",,,,";
        }
        
        if(!final.front().dvr.plate.empty()){
            out_file<<final.front().dvr.direction<<",";
        }
        out_file<<endl;
        
        final.pop();

    }


    out_file.close();
}
void print_delay_aaeon(queue <Aaeon_delay> &aaeon_delay){
    ofstream out_file;
    out_file.open("delay.csv");
    out_file<<"dvr_time,aaeon_time,延遲秒數"<<endl;
    int delay_time[100]={};
    while(!aaeon_delay.empty()){
        out_file<<aaeon_delay.front().dvr_time.fprint()<<","<<aaeon_delay.front().aaeon_time.fprint()<<",";
        //out_file<<aaeon_delay.front().aaeon_time.time_to_sec()<<","<<aaeon_delay.front().dvr_time.time_to_sec()<<",";
        out_file<<aaeon_delay.front().aaeon_time.time_to_sec()-aaeon_delay.front().dvr_time.time_to_sec()<<",";
        delay_time[abs(aaeon_delay.front().aaeon_time.time_to_sec()-aaeon_delay.front().dvr_time.time_to_sec())/60]++;
        out_file<<endl;
        aaeon_delay.pop();
        
    }
    out_file<<"延遲級距,個數"<<endl;
    for(int i=0;i<100;i++){
        out_file<<"延遲"<<i<<"分鐘,";
        out_file<<delay_time[i]<<endl;
    }
}
//main--------------------------------------------------------------
int main(){
    queue <Plate_data> acelin_data;
    queue <Plate_data> aaeon_data;
    queue <Plate_data> dvr_data;
    queue <Final_plate_data> final_data;
    set   <string> dvr_white_list;
    queue <Aaeon_delay> aaeon_delay;

    freopen("aaeon_test.txt","w",stdout);
    push_dvr_data(dvr_data,dvr_white_list);
    push_acelin_data(acelin_data,dvr_white_list);
    push_aaeon_data(aaeon_data,dvr_white_list);
    
    //print_queue_data(acelin_data);
    //cout<<"======================================================================\n";
    //print_queue_data(aaeon_data);
    //cout<<"======================================================================\n";
    //print_queue_data(dvr_data);
    //return 0;
    unify(acelin_data,aaeon_data,dvr_data,final_data,dvr_white_list,aaeon_delay);
    
    print_final_data_csv(final_data);
    

    print_delay_aaeon(aaeon_delay);
    return 0;

}