#include <iostream>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::stringstream;
using std::string;
using std::numeric_limits;
using std::streamsize;
using std::ofstream;
using std::ifstream;

template <typename T>
void check_vector_size(const vector<T>&);

template <typename T>
void count_member_apperances(const vector <T>&);

template <typename T>
void print_members(const vector <T>&);

template <typename T>
void menu(vector <T>&);

template <typename T>
void add_member(vector <T>&);

template <typename T>
void members_mean(const vector <T>&);

template <typename T>
void smallest_member(const vector <T>&);

template <typename T>
void largest_member(const vector <T>&);

template <typename T>
void find_member(const vector <T>&);

template <typename T>
void delete_member(vector <T>&);

template <typename T>
void sort_members(vector <T>&);

template<typename T>
void write_to_file(const vector<T>&);

template<typename T>
void write_from_file(vector<T>&);

template<typename T>
bool validate_input(stringstream&&, T&);

void clear_screen();



void clear_screen(){
system("cls");}



template<typename T>
bool validate_input(stringstream &&stream,T &input){


return static_cast<bool>(stream >> input);

}


template<typename T>
void check_vector_size(const vector<T> &vec){
if(vec.size()==1)
    cout<<"Vector has 1 member"<<endl;
else
    cout<<"Vector has "<<vec.size()<<" members"<<endl;



}


template <typename T>
void find_member(const vector <T> &vec){

  string input;
  T member{};

  cout<<"Enter the member you wish to find:";
  cin>>input;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');


  if(validate_input(stringstream{input},member)){

    auto it = find(vec.begin(),vec.end(),member);
       if(it == vec.end()){
        cout<<"No such member exists"<<endl;
       }
       else{
        cout<<"Member found at index: "<<distance(vec.begin(),it)<<endl;
       }

  }



  else{cout<<"Invalid input"<<endl;}



}

template <typename T>
void smallest_member(const vector <T> &vec){

auto it = min_element(vec.begin(),vec.end());

cout<<"Smallest member is:"<<*it<<endl;


}






template <typename T>
void largest_member(const vector <T> &vec){

auto it =max_element(vec.begin(),vec.end());

cout<<"Largest member is: "<<*it<<endl;


}

template <typename T>
void members_mean(const vector <T> &vec){
T members_mean {};

for(const T &x:vec){
    members_mean+=x;
}
cout<<"Mean of the members is:"<<members_mean<<endl;
}



template <typename T>
void add_member(vector <T> &vec){

T new_member {};
string input;
cout<<"Type in the member you would like to add:";
cin>>input;
cin.ignore(numeric_limits<streamsize>::max(),'\n');

if(validate_input(stringstream{input},new_member)){

   vec.push_back(new_member);
   cout<<"Member added succesfully"<<endl;
   print_members(vec);
   cout<<endl;}

else{cout<<"Invalid input"<<endl;}


}










template <typename T>
void print_members(const vector <T> &vec){
    cout<<"Printing out members: [ ";

for(const T &member:vec){
    cout<<member<<" ";
}

cout<<"]"<<endl;}



template <typename T>
void delete_member(vector <T> &vec){
    string input;
    T member {};
    cout<<"Enter a member you want to delete: ";
    cin>>input;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(validate_input(stringstream{input},member)){

       auto it = find(vec.begin(),vec.end(),member);

       if(it==vec.end()){
          cout<<"No such member exists"<<endl;
    }

      else{
         vec.erase(it);
         cout<<"Member succesfully deleted"<<endl;
         print_members(vec);
    }

}

    else{cout<<"Invalid input\n";}



}


template<typename T>
void sort_members(vector <T> &vec){

char choice {};
cout<<"Do you wish to sort members by descending or ascending order(A/D)";
cin>>choice;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
choice = toupper(choice);




   if(choice=='A'){
      sort(vec.begin(),vec.end());
      cout<<"Members have been succesfully sorted by ascending order\n";
      print_members(vec);
      cout<<endl;}


   else if(choice=='D'){
      sort(vec.begin(),vec.end(),[](T a,T b){return a > b;});
      cout<<"Members have been succesfully sorted by descending order\n";
      print_members(vec);
      cout<<endl;
}

   else{cout<<"Invalid choice\n";}}


template <typename T>
void count_member_apperances(const vector <T> &vec){

string input;
T member;
cout<<"Enter a member you would like to check for: ";
cin>>input;
cin.ignore(numeric_limits<streamsize>::max(),'\n');

if(validate_input(stringstream{input},member)){
    int apperances = count(vec.begin(),vec.end(),member);
      if(apperances==1)
        cout<<"Member appears 1 time"<<endl;
      else{
        cout<<"Member appears "<<apperances<<" times"<<endl;
      }
}
else{
    cout<<"Invalid input"<<endl;
}



}



template<typename T>
void write_to_file(const vector<T> &vec){

    string file_name;
    cout<<"Type the file name that you want to write to: ";
    cin>>file_name;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    ofstream out_file{file_name};

    if(out_file.is_open()){

       for(const T &member:vec){
          out_file <<member;}}

    else{
        cout<<"There was an error opening a file"<<endl;}

    out_file.close();


    }


template<typename T>
void write_from_file(vector<T> &vec){

string file_name;
T new_member;
string file_input;
int member_counter {0};

cout<<"Enter the name of the file you want to write members from:";
cin>>file_name;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
ifstream in_file{file_name};
if(in_file.is_open()){





while(!in_file.eof()){

    in_file >> file_input;
    if(validate_input(stringstream{file_input},new_member)){
        vec.push_back(new_member);
    }

    else{cout<<"There was an error with the member in a provided file at the index of: "<<member_counter<<endl;}
    member_counter++;

}

in_file.close();

}

else{
    cout<<"There was an error opening this file,please make sure the file you are providing exists"<<endl;
}


}









template<typename T>
void menu(vector<T> &vec){



    char choice{};

    do{
    cout <<"\nP - print all members" << endl;
    cout<<"V - check how many members vector has"<<endl;
    cout <<"A - add a member" << endl;
    cout <<"M - display means of the members" << endl;
    cout <<"S - display the smalest member" << endl;
    cout <<"L - display the largest member" << endl;
    cout<<"F - find member"<<endl;
    cout<<"D - delete a member"<<endl;
    cout<<"X - sort members"<<endl;
    cout<<"R - Check how many times member appears"<<endl;
    cout<<"W - Write members to a file"<<endl;
    cout<<"I - Write members from a file"<<endl;
    cout<<"C- clear screen"<<endl;
    cout <<"Q - quit:" << endl<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    choice = toupper(choice);






    switch(choice){

   case'P':
       print_members(vec);
        break;


   case'A':{
      add_member(vec);
       break;}


   case'M':
        members_mean(vec);
        break;

   case'L':
        largest_member(vec);
        break;

   case'S':
        smallest_member(vec);
        break;

   case'F':
        find_member(vec);
        break;

   case'D':
       delete_member(vec);
       break;

   case'X':
      sort_members(vec);
      break;

   case'R':
      count_member_apperances(vec);
      break;

   case'V':
      check_vector_size(vec);
      break;

   case 'W':
      write_to_file(vec);
      break;

   case 'I':
       write_from_file(vec);
       break;

   case 'C':
       clear_screen();
       break;


   case'Q':
       cout<<"Goodbye";
       break;


   default:
     cout<<"Invalid choice\n";}





    }while(choice!='Q');


}


int main()
{

    vector <int> vec {1,2,3,4,5};

    menu(vec);
    return 0;
}
