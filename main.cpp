#include <bits/stdc++.h>

using namespace std;

long long sum = 0;
vector <vector<int>>c;

class Op{
    int x;
public:
    Op(int x);
    Op operator+(int);
};

Op::Op(int x) {
    c.resize(x);
    int k;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cin >> k;
            c[i].push_back(k);
        }
    }
    /*for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }*/
}

Op Op::operator+(int x) {
    int p;
    /*for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout << sum << " ";*/
    for (int i = 0; i < x; i++) {
        p = 1;
        for (int j = 0; j < x; j++) {
            p *= c[(i+j)%x][j];
            //cout << "i: " << (i+j)%x << " j: " << j << " p: " << p << endl;
        }
        sum += p;
        //cout << " sum: " << sum << endl;
    }
    //cout << endl;
    for (int i = 0; i < x; i++) {
        p = 1;
        for (int j = x-1; j >= 0; j--) {
            p *= c[(x+i-j-1)%x][j];
            //cout << "i: " << (x+i-j-1)%x << " j: " << j << " p: " << p << endl;
        }
        sum -= p;
        //cout << " sum: " << sum << endl;
    }
};

int main() {
    int x;
    cin >> x;
    Op c(x);
    c + x;
    cout << sum;
}
