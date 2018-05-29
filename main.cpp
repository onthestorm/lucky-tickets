#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long long> getNewArray(vector<unsigned long long> & mas);

int main()
{
    int N;
    unsigned long long answer = 0;
    vector<unsigned long long> mas(10);
    for (int i = 0; i < 10; i++) {
        mas[i] = 1;
    }
    cout << "Enter N:";
    cin >> N;
    for (int i = 1; i < N; i++) {
        getNewArray(mas);
    }
    for (int k = 0; k < mas.size(); k++) {
        answer = answer + mas[k]*mas[k];
    }
    cout << "Answer : " << answer << endl;
    return 0;
}

vector<unsigned long long> getNewArray(vector<unsigned long long> & mas)
{
    mas.resize(mas.size() + 9);
    vector<unsigned long long> buf(mas.size());
    buf = mas;
    for (int k = 0; k < mas.size(); k++) {
        int fr = k - 10;
        for(int pos = k - 1; pos > fr; pos--) {
            if(pos < 0) {
                break;
            }
            mas[k] = mas[k] + buf[pos];
        }
    }
    return mas;
}
