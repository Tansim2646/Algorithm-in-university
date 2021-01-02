#include <iostream>

using namespace std;
int a, b, c, d, e, f;
int arr[1000] = {0};

int fn(int n) {
    for (int i = 6; i <= n; i++) {


        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4] + arr[i - 5] + arr[i - 6];


    }

    return arr[n];
}


int main() {
    int n, caseno = 0, cases, results[1000];
    cout << "Enter the number of cases:" << endl;
    cin >> cases;
    cout << "Enter the values:" << endl;


    while (cases--) {


        cin >> a >> b >> c >> d >> e >> f >> n;
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        arr[3] = d;
        arr[4] = e;
        arr[5] = f;
        results[caseno] = fn(n);
        caseno++;


    }
    for (int i = 0; i < caseno; i++) {
        cout << results[i] << endl;
    }


    return 0;
}
