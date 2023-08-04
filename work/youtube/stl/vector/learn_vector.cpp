#include<iostream>
#include<vector>
using namespace std;
void print(vector <int> v,int num){
   cout<<"-------------------------------------------------------\n";
   cout<<"v"<<num<<": ";
   for(auto i:v){
      cout<<i<<" ";
   }
   cout<<endl;
   cout<<"-------------------------------------------------------"<<endl;
}
int main(){
/*
//初始化------------------------------------------------------------------------------------------------------------------------------------
   //空的vector----------------------------------------------------------------------------
   //vector();
   vector <int> v1;
   print(v1,1);

   //使用v1的記憶體配置器初始化vector-----------------------------------------------------------------------
   //explicit vector(const Allocator& allocator);
   vector <int> v2( v1.get_allocator( ) );  
   print(v2,2);

   //空間大小為100的vector-----------------------------------------------------------------------
   //explicit vector(size_type count);
   vector <int> v3 (10);                        
   print(v3,3);

   //空間大小為100且每個元素都為21的vector-----------------------------------------------------------------------
   //vector(size_type count, const Type& value);
   vector <int> v4 (10,21);  
   print(v4,4);

   //空間大小為100且每個元素都為21且使用v1的記憶體配置器初始化的vector-----------------------------------------------------------------------
   //vector(size_type count, const Type& value, const Allocator& allocator);
   vector <int> v5 (10,21,v1.get_allocator( )); 
   print(v5,5);

   //複製一份v4至v6---------------------------------------------------------------------------------------------------------------------------------------------
   //vector(const vector& source);
   vector <int> v6 (v4);                         
   print(v6,6);

   //把v6移至v7--------------------------------------------------------------------------------------------------------------------------------------------
   //vector(vector&& source);
   vector <int> v7(move(v6));
   print(v6,6);
   print(v7,7);

   //使用{}將內容丟入--------------------------------------------------------------------------------------------------------------------------------------------
   //vector(initializer_list<Type> init_list, const Allocator& allocator);
   vector <int> v8 {1,2,4,3,5,6};
   print(v8,8);

   //將v8部分片段複製至v9--------------------------------------------------------------------------------------------------------------------------------------------
   //template <class InputIterator>
   //vector(InputIterator first, InputIterator last);
   vector <int> v9(v8.begin()+1,v8.end()-2);
   print(v8,8);
   print(v9,9);

//初始化結束--------------------------------------------------------------------------------------------------------------------------------------------
*/
//assign()-------------------------------------------------------------------------------------------
   vector <int> v10(10,5)
   //





/*
*/
/*





   vector<int, allocator<int> > v2 = vector<int, allocator<int> >(allocator<int>( )) ;

   // v3 will use the same allocator class as v1
   vector <int> v3( v1.get_allocator( ) );

   vector<int>::allocator_type xvec = v3.get_allocator( );
   // You can now call functions on the allocator class used by vec
   */
}