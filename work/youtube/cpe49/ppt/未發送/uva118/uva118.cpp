#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool find_str(string &s,char &g){
    for(char i:s)
        if(i==g)
            return 1;
    return 0;
}
char rorientation(int &x,int &y){
    if(x==1&&y==0)
        return 'E';
    if(x==0&&y==1)
        return 'N';
    if(x==-1&&y==0)
        return 'W';
    if(x==0&&y==-1)
        return 'S';

}
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int rux,ruy;
    cin>>rux>>ruy;
    vector<vector<bool>> vec(rux+1,vector<bool>(ruy+1,0));
    int x,y,face_x,face_y;
    char face;
    while(cin>>x>>y>>face){
        if(face=='E'){
            face_x=1;
            face_y=0;
        }else if(face=='W'){
            face_x=-1;
            face_y=0;
        }else if(face=='N'){
            face_x=0;
            face_y=1;
        }else if(face=='S'){
            face_x=0;
            face_y=-1;
        }
        string s;
        getline(cin,s);
        getline(cin,s);
        bool lost=0;
        for(char i:s){
            //cout<<i<<" ";
            if(i=='R'){
                face_x=-face_x;
                swap(face_x,face_y);
            }else if(i=='L'){
                face_y=-face_y;
                swap(face_x,face_y);
            }else if(i=='F'){
                if(x+face_x>rux||x+face_x<0||y+face_y<0||y+face_y>ruy){
                    char t=rorientation(face_x,face_y);
                    if(vec[x][y]){
                        continue;
                    }else{
                        lost =1;
                        break;
                    }
                    
                }else{
                    x+=face_x;
                    y+=face_y;
                }

            }
            //cout<<face_x<<" "<<face_y<<" "<< x<<" "<<y<<endl;
        }
        char ansc=rorientation(face_x,face_y);
        cout<<x<<" "<<y<<" "<<ansc;
        if(lost){
            cout<<" LOST";
            vec[x][y]=1;
        }
        
        cout<<endl;

    }
    
}

