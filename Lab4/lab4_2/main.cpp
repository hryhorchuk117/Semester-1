#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void Calculation_of_permutations (vector<int> v, map<int, vector<int>>& m);

bool Check(vector<int> v);

void Print_vector(vector<int> v);

void Print_permutations(map<int, vector<int>> m);


int main() {

    map<int, vector<int>> Permutations;
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 1; i <= n; ++i) {
        numbers.push_back(i);
    }

    Calculation_of_permutations(numbers, Permutations);

    for (auto item:Permutations) {
        if (!Check(item.second)) {
            Permutations.erase(item.first);
        }
    }

    Print_permutations(Permutations);
    return 0;
}


void Calculation_of_permutations (vector<int> v, map<int, vector<int>>& m) {
    int i = 0;
    while (next_permutation(v.begin(), v.end() ) )
    {
        m[i] = v;
        ++i;
    }
}

bool Check(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) {
        if (i == v[i]-1) {
            return false;
        }
    }
    return true;
}

void Print_vector(vector<int> v) {
    for (auto item:v) {
        cout << item << " ";
    }
    cout << endl;
}

void Print_permutations(map<int, vector<int>> m) {
    for (auto item:m) {
        Print_vector(item.second);
    }
}



