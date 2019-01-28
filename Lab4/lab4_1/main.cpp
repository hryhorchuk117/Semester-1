#include <iostream>
#include <vector>
#include <map>

using namespace std;

void Initialization (map<int, vector<bool>>& Possible_letter, vector<int>& lane, int n);

void Step_backward(map<int, vector<bool>>& Possible_letter, int& i, vector<int>& lane);

void Step_forward(map<int, vector<bool>>& Possible_letter, int i, vector<int>& lane);

void Check(int n, int k, vector<bool>& v, const vector<int>& l);

void Print(const vector<int>& lane, int n);


int main()
{
    int n;
    cin >> n;
    vector<int> lane;
    map<int, vector<bool>> Possible_letter;
    Initialization(Possible_letter, lane, n);

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i / 2; ++j) {
            Check(i, j, Possible_letter[i], lane);
        }

        if (!Possible_letter[i][0] && !Possible_letter[i][1] && !Possible_letter[i][2]) {
            Step_backward(Possible_letter, i, lane);
        }
        else {
            Step_forward(Possible_letter, i, lane);
        }

    }

    Print(lane, n);
    return 0;
}


void Initialization(map<int, vector<bool>> &Possible_letter, vector<int> &lane, int n) {
    for (int i = 1; i <= n; ++i) {
        Possible_letter[i] = { true, true, true };
    }
    lane.push_back(0);
}

void Step_backward(map<int, vector<bool>>& Possible_letter, int& i, vector<int>& lane){
    Possible_letter[i] = { true, true, true };
    if (Possible_letter[i - 1][0]) {
        Possible_letter[i - 1][0] = false;
    }
    else {
        if (Possible_letter[i - 1][1]) {
            Possible_letter[i - 1][1] = false;
        }
        else {
            Possible_letter[i - 1][2] = false;
        }
    }
    lane.pop_back();
    i -= 2;
}

void Step_forward(map<int, vector<bool>>& Possible_letter, int i, vector<int>& lane){
    if (Possible_letter[i][0]) {
        lane.push_back(0);
    }
    else {
        if (Possible_letter[i][1]) {
            lane.push_back(1);
        }
        else {
            lane.push_back(2);
        }
    }
}

void Check(int n, int k, vector<bool>& v, const vector<int>& l) {
    bool flag = true;
    for (int i = n - 2 * k + 1; i < (n - 2 * k + 1) + (k - 1); ++i) {
        if (l[i - 1] != l[i + k - 1]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        v[l[(n - 2 * k + 1) + (k - 1) - 1]] = false;
    }
}

void Print(const vector<int>& lane, int n){

    for (int i = 0; i < n; ++i) {
        if (lane[i] == 0) {
            cout << "a";
        }
        else {
            if (lane[i] == 1) {
                cout << "b";
            }
            else {
                cout << "c";
            }
        }
    }
    cout << endl;
}