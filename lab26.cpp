#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;
using namespace std::chrono;

const int RUNS = 15;
const int OPS = 4;
const int TYPE = 3;
const int LAYER = 2;

//READING
int readVector(string& filename, vector<string>& vec){
vec.clear();
    string line;

    auto start = high_resolution_clock::now();
    ifstream fin("codes.txt");
   while 
    (getline(fin, line)){
       vec.push_back(line);
    }
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end-start).count();
   // cout << "TIME: " << duration.count();

}

int readList(string& filename, list<string>& lst){
    lst.clear();
    string line;

    auto start = high_resolution_clock::now();
    ifstream fin2("codes.txt");
   while 
    (getline(fin2, line)){
       lst.push_back(line);
    }
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end-start).count();

}

int readSet(string& filename, set<string>& st){
    st.clear();
    string line;

    auto start = high_resolution_clock::now();
    ifstream fin3("codes.txt");
   while 
    (getline(fin3, line)){
       st.insert(line);
    }
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end-start).count();

}

//SORTING
int sortVector(vector<string>& vec) {
auto start = high_resolution_clock::now();
sort(vec.begin(), vec.end());
auto end = high_resolution_clock::now();

return duration_cast<microseconds>(end-start).count();
}

int sortList(list<string>& lst) {
auto start = high_resolution_clock::now();
lst.sort();
auto end = high_resolution_clock::now();

return duration_cast<microseconds>(end-start).count();
}

int sortSet(set<string>& st) {
auto start = high_resolution_clock::now();
//automatic sorting
auto end = high_resolution_clock::now();

return duration_cast<milliseconds>(end-start).count();
} 

//INSERT
int insertVector(vector<string>& vec, const string& val) {
    auto start = high_resolution_clock::now();
    int mid = vec.size()/ 2;
    vec.insert(vec.begin() + mid, val);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();

}
int insertList(list<string>& lst, const string& val) {
    auto start = high_resolution_clock::now();
    list<string>::iterator it = lst.begin();
    int mid = lst.size()/ 2;
    for (int i = 0; i < mid; i++){
        it++;
    }
    lst.insert(it, val);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();

}
int insertSet(set<string>& st, const string& val) {
    auto start = high_resolution_clock::now();
    set<string>::iterator it = st.begin();
    int mid = st.size()/2;
    for (int i = 0; i < mid; i++){
        it++;
    }
    st.insert(val);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();

}
//DELETE
int deleteVector(vector<string>& vec) {
    auto start = high_resolution_clock::now();
    int mid = vec.size()/ 2;
    vec.erase(vec.begin() + mid);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();

}
int deleteList(list<string>& lst) {
    auto start = high_resolution_clock::now();
    list<string>::iterator it = lst.begin();
    int mid = lst.size()/ 2;
    for (int i = 0; i < mid; i++){
        it++;
    }
    lst.erase(it);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();

}
int deleteSet(set<string>& st) {
    auto start = high_resolution_clock::now();
    set<string>::iterator it = st.begin();
    int mid = st.size()/2;
    for (int i = 0; i < mid; i++){
        it++;
    }
    st.erase(it);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();

}

int main() {

string file = "codes.txt";

int times[LAYER][OPS][TYPE] = {0};

cout << "Number of Simulations: " << RUNS << "\n";

for (int i = 0; i < RUNS; i++){
vector<string> vec;
list<string> lst;
set<string> st;



times[0][0][0] = readVector(file, vec);
times[0][0][1] = readList(file, lst);
times[0][0][2] = readSet(file, st);

times[0][1][0] = sortVector(vec);
times[0][1][1] = sortList(lst);
times[0][1][2] = sortSet(st);

string insert = "HI";
times[0][2][0] = insertVector(vec, insert);
times[0][2][1] = insertList(lst, insert);
times[0][2][2] = insertSet(st, insert);
   
times[0][3][0] = deleteVector(vec);
times[0][3][1] = deleteList(lst);
times[0][3][2] = deleteSet(st);

//into average layer
for (int i = 0; i < OPS; i++){
    for (int j = 0; j < TYPE; j++){
        times[1][i][j] += times[0][i][j];
    }
}
}

int avg;

    //output
    /* cout << left << setw(8) << "Operation" << setw(8) << "Vector" << setw(8) << "List" << setw(8) << "Set" << endl;

    cout << setw(8) << "Read" << setw(8) << vecRead << setw(8) << listRead << setw(8) << setRead << endl;
    cout << setw(8) << "Sort" << setw(8) << vecSort << setw(8) << listSort << setw(8) << setSort << endl;
    cout << setw(8) << "Insert" << setw(8) << vecInsert << setw(8) << listInsert << setw(8) << setInsert << endl;
    cout << setw(8) << "Delete" << setw(8) << vecDelete << setw(8) << listDelete << setw(8) << setDelete << endl; */

    
/* cout << " vec Read time: " << vecRead << endl;
cout << " list Read time: " << listRead << endl;
cout << " set Read time: " << setRead << endl;

cout << " vec sort time: " << vecSort << endl;
cout << " list sort time: " << listSort << endl;
//cout << " set Read time: " << setSort;

cout << " vec insert time: " << vecInsert << endl;
cout << " list insert time: " << listInsert << endl;
cout << " set insert time: " << setInsert << endl;

cout << " vec delete time: " << vecDelete << endl;
cout << " list delete time: " << listDelete << endl;
cout << " set delete time: " << setDelete << endl; */



    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/