#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> Vector();

void Binary_writing(const string& path);

int Size(const string& path);


int main() {
    const string path = "~/CLionProjects/lab6.txt";

    Binary_writing(path);

    ifstream input(path, ios::binary);
    int n{};
    int size = Size(path);
    double average{};
    while (input.read((char*) &n, sizeof(n))) {
        average += static_cast<double>(n) / size;
    }

    cout << average << endl;

    return 0;
}


vector<int> Vector() {
    vector<int> numbers{};
    int vector_size{};
    cin >> vector_size;
    for (int i = 0; i < vector_size; ++i) {
        int a{};
        cin >> a;
        numbers.push_back(a);
    }
    return numbers;
}

void Binary_writing(const string &path) {
    vector<int> numbers = Vector();
    ofstream output(path, ios::binary);
    for (auto item : numbers) {
        output.write((char*) &item, sizeof(item));
    }
    output.close();

}

int Size(const string &path) {
    ifstream input(path, ios::binary);
    int n{}, size{};
    while (input.read((char*) &n, sizeof(n))) {
        ++size;
    }
    input.close();
    return size;
}
