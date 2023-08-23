#include<iostream>
#include<set>
using namespace std;
template <typename a> void print(a s,int n){
    cout<<n<<":";
    for(auto i:s)
        cout<<i<<" ";
    cout<<endl;
}
bool big(int a,int b){
    return a>b;
}
int main(){
/*
// 建構式============================================================================================================
    //set()--------------------------------------------------------------------------------------------------------
    set <int> s1;
  
    //explicit set(const Traits& Comp);----------------------------------------------------------------------------
    //傳入排序的function
    set <int> s2(less<int>());//由小到大排序

    //set(const set& Right);----------------------------------------------------------------------------
    //set(set&& Right);
    //將要複製的set複製一份
    set <int> s3_1({1,2,3,4,5});
    set <int> s3(s3_1);
    print(s3_1,31);
    print(s3,3);

    //set(initializer_list<Type> IList);--------------------------------------------------------------------
    set <int> s4({1,2,3,4,5});

    //set(initializer_list<Type> IList,const Compare& Comp);--------------------------------------------------------------------
    set<int,greater<int>> s5({1,3,2,4,5,2});      
    print(s5,5);

    //template <class InputIterator>--------------------------------------------------------------------
    //set(InputIterator First,InputIterator Last);
    set<int> s6_1({1,2,4,3,7,6});
    set<int> s6(s6_1.begin(),s6_1.end());
    print(s6,6);

    //template <class InputIterator>
    //set(InputIterator First,InputIterator Last,const Traits& Comp);
// 建構式結束============================================================================================================

// begin() & end():傳回迭代器的第一個跟帝最後一個一個跟帝最後一個位置===========================================================
    //iterator begin();
    //iterator end();
    set <int> s7({5,3,72,4,2,-100});
    set <int>::iterator b7=s7.begin();
    set <int>::iterator e7=s7.end();
    cout<<"e7:";
    for(;b7!=e7;b7++){
        cout<<*b7<<" ";
    }
    cout<<endl;
// begin() & end()結束==================================================================================================

// cbegin() & cend():傳回迭代器的第一個跟帝最後一個一個跟帝最後一個位置===========================================================
    //const_iterator cbegin() const;
    //const_iterator cend() const;

    //用法與begin() & end()一樣，但cbegin() & cend()得、的值無法更改

// cbegin() & cend()結束=================================================================================================
 
// clear():清除set裡的元素=================================================================================================
    //void clear();
    set<int> s8={1,2,3,4,3,7,1,33,-193};
    print(s8,8);
    s8.clear();
    print(s8,8);


// clear():結束=================================================================================================

//count():在set裡查找目標元素出現的個數（但因為）set的特性，最多就是出現一次==========================================================================================
    //size_type count(const Key& key) const;

    set <int> s9={1,1,2,3,4,5,6,7,8,9};
    cout<<s9.count(1)<<endl;
    cout<<s9.count(2)<<endl;
    cout<<s9.count(-100)<<endl;
//count()結束====================================================================================================================================================================================

//crbegin() & crend():反向迭代器=================================================================================================================================================================
    //const_reverse_iterator crbegin() const;
    //const_reverse_iterator crend() const;
    set<int> s10={9,8,4,6,2,1};
    auto crb10=s10.crbegin();
    auto cre10=s10.crend();
    cout<<*crb10<<endl;
    cout<<*cre10<<endl; //segmentation fault會往後多踩一位
//crbegin() & crend():結束=================================================================================================================================================================

//emplace():插入元素============================================================================================================================
    //通常set都是使用insert()比較不會用emplace()
    //template <class... Args>
    //pair<iterator, bool>
    //emplace(Args&&... args);
    
    set<int> s11 = {1,3,2};
    auto ret=s11.emplace(3);
    bool r_b=ret.second;
    set<int>:: iterator r_i=ret.first;
    cout<<r_b<<endl;
    cout<<*r_i<<endl;

    ret=s11.emplace(4);
    r_b=ret.second;
    r_i=ret.first;
    cout<<r_b<<endl;
    cout<<*r_i<<endl;
//

//empty():判斷set是否是空的=====================================================================================
    //bool empty() const;
    set <int> s12;
    cout<<s12.empty()<<endl;
    s12={1,3,2};
    cout<<s12.empty()<<endl;


//


//erase():移除特定位置的元素或指定的元素=========================================================================
    //iterator erase(const_iterator Where);----------------------------------------------------
    set <int> s13={9,3,7,11,-8};
    print(s13,13);
    auto it=s13.begin();
    advance(it, 2);
    s13.erase(it);//因為set是樹，不是陣列，無法直接寫:s13.being()+2;
    print(s13,13);

    //iterator erase(const_iterator First,const_iterator Last));----------------------------------------------------
    set <int> s14={5,1,3,6,2,3};
    print(s14,14);
    auto itb=s14.begin();
    auto ite=s14.end();
    advance(itb,2);
    advance(ite,-1);
    s14.erase(itb,ite);
    print (s14,14);

 
    //size_type erase(const key_type& Key);-----------------------------------------------------------
    set <int> s15={1,5,2,3,-8};
    print(s15,15);
    s15.erase(3);
    print(s15,15);

//

//find():尋找key所在的位置==============================================================================
    //iterator find(const Key& key);
    //const_iterator find(const Key& key) const;
    set <int> s16={6,1,3,2,9,4};
    auto it1=s16.find(6);
    cout<<*it1<<endl;
    auto it2=s16.find(100);
    if(it2==s16.end())
        cout<<"no fine"<<endl;
//

//?????????????????????????????????????????????????????????????????//insert:插入資料======================================================================================
    //pair<iterator, bool> insert(const value_type& Val);
    set <int>s17({1,2,4,1,3,2});
    print(s17,17);
    const int a=10;
    s17.insert(a);
    print(s17,17);

    //template <class ValTy>
    //pair<iterator, bool>insert(ValTy&& Val);
    set <int>s18({5,1,3,15,13});
    print(s18,18);
    s18.insert(9);
    print(s18,18);

    //iterator insert(const_iterator Where,const value_type& Val);
    //基本上，指定位置是沒有意義的，因為會重新排序
    set <int>s19({5,24,1,2,34,1});
    print(s19,19);
    s19.insert(s19.begin(),{4,1,3,2,32,14,1});
    print(s19,19);

    //iterator insert(const_iterator Where,const value_type& Val);
    //基本上，指定位置是沒有意義的，因為會重新排序
    set <int>s20({4,14,3});
    print(s20,20);
    s20.insert(s20.begin(),2);
    print(s20,20);
    
    //
//
*/
//lower_bound():傳回迭代器，指向集合中索引鍵等於或大於特定索引鍵的第一個項目=============================================
    //const_iterator lower_bound(const Key& key) const;
    //iterator lower_bound(const Key& key);
    set <int> s31({1,3,7,5,9});
    print (s31,31);
    if(s31.lower_bound(6)==s31.end()){
        cout<<"沒有大於等於6的元素\n";
    }

























}