#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <math.h>
#include <utility>

using namespace std;

class OPI {
public:

    vector<string> Finding_variables(stringstream& ss) {
        vector<string> variables{};
        string s = ss.str();
        int i = 0;
        while (i < static_cast<int>(s.size())) {

            if (ss.peek() - 48 < 10 && ss.peek() > -1) {
                int n{};
                ss >> n;
            }

            else if (ss.peek() != '(' || ss.peek() != ' ') {
                string s1{};
                ss >> s1;
                if (!Is_exp(s1) && !s1.empty()) {
                    variables.push_back(s1);
                }
            }
            ++i;
            ss.ignore(1);
        }
        return variables;
    }

    void Reading_variables(vector<string> &vector_of_variables) {
        for (const auto& item : vector_of_variables) {
            cout << item << " = ";
            double q{};
            cin >> q;
            variables[item] = q;
        }
    }

    double Number_in_the_brackets(stringstream &ss) {
        vector<double> numbers{};
        int stop = 0;
        int i = 0;
        string s = ss.str();
        while (i < static_cast<int>(s.size())) {
            if (ss.peek() == ')') {
                if (numbers.size() > 1) {
                    stringstream ss_ex{};
                    ss_ex << "Error";
                    throw runtime_error(ss_ex.str());
                }
                ss.ignore(1);
                return numbers[0];
            }

            if (ss.peek() == ' ') {
                ss.ignore(1);
            }

            else if (ss.peek() == '+') {
                Plus(ss, numbers);
            }

            else if (ss.peek() == '-') {
                Minus(ss, numbers, variables);
            }

            else if (ss.peek() == '/') {
                ss.ignore(1);
                pair<double, double> last_two = Last_two_numbers(numbers);
                numbers.push_back(last_two.first / last_two.second);
            }

            else if (ss.peek() - 48 < 10 && ss.peek() - 48 > -1) {
                Add_number(ss, numbers);
            }

            else if (ss.peek() == '(') {
                ss.ignore(1);
                numbers.push_back(Number_in_the_brackets(ss));
            }

            else {
                Add_variable_or_exp(ss, numbers);
            }

            ++i;
        }

        stringstream ss_ex{};
        ss_ex << "Error";
        throw runtime_error(ss_ex.str());
    }

private:
    map<string, double> variables;


    void Plus(stringstream& ss, vector<double>& numbers) {
        ss.ignore(1);
        if (ss.peek() == ' ' || ss.peek() == ')') {
            pair<double, double> last_two = Last_two_numbers(numbers);
            numbers.push_back(last_two.first + last_two.second);
        }
    }

    void Minus(stringstream& ss, vector<double>& numbers, map<string, double>& variables) {
        ss.ignore(1);
        if (ss.peek() == ' ' || ss.peek() == ')') {
            pair<double, double> last_two = Last_two_numbers(numbers);
            numbers.push_back(last_two.first - last_two.second);
        }
        else {
            if (ss.peek() == '(') {
                ss.ignore(1);
                numbers.push_back(Number_in_the_brackets(ss) * -1);
            }
            else if (ss.peek() - 48 < 10 && ss.peek() - 48 > -1) {
                double n;
                ss >> n;
                numbers.push_back(n * -1);
            }

            else {
                string s{};
                ss >> s;
                if (s == "exp") {
                    Add_exp(ss, numbers);
                    Change_last(numbers);
                }
                else {
                    numbers.push_back(variables[s] * -1);
                }
            }
        }
    }

    pair<double, double> Last_two_numbers(vector<double>& numbers) {
        double first_number  = numbers[numbers.size()-2];
        double second_number = numbers[numbers.size()-1];
        numbers.pop_back();
        numbers.pop_back();
        return {first_number, second_number};
    }

    bool Is_exp(const string &s) {
        return (s[0] == 'e' && s[0 + 1] == 'x' && s[0 + 2] == 'p' && s[0 + 3] == '(');
    }

    double Exp(double n) {
        const double e = 2.71828;
        return pow(e, n);
    }

    void Change_last (vector<double>& numbers) {
        double n = numbers[numbers.size()];
        numbers.pop_back();
        numbers.push_back(n * -1);
    }

    void Add_variable_or_exp(stringstream& ss, vector<double>& numbers) {
        string s{};
        ss >> s;
        if (Is_exp(s)) {
            Add_exp(ss, numbers);
        }
        else {
            numbers.push_back(variables[s]);
        }
    }

    void Add_exp(stringstream& ss, vector<double> &numbers) {
        double n = Number_in_the_brackets(ss);
        numbers.push_back(Exp(n));
    }

    void Add_number(stringstream& ss, vector<double>& numbers) {
        double n;
        ss >> n;
        numbers.push_back(n);
    }
};


int main() {
    string s{};
    getline(cin, s);
    s = s + " )";
    stringstream ss{s};
    OPI opi;
    vector<string> vector_of_variables = opi.Finding_variables(ss);
    opi.Reading_variables(vector_of_variables);

    try {
        stringstream ss_new{s};
        cout << opi.Number_in_the_brackets(ss_new) << endl;
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}
