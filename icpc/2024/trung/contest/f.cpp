#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, nA, nB, nC;
    cin >> n >> nA >> nB >> nC;
    
    set<int> prefA, prefB, prefC; 
    int mA, mB, mC;
    

    cin >> mA;
    for (int i = 0; i < mA; ++i) {
        int x;
        cin >> x;
        prefA.insert(x);
    }
    cin >> mB;
    for (int i = 0; i < mB; ++i) {
        int x;
        cin >> x;
        prefB.insert(x);
    }
    cin >> mC;
    for (int i = 0; i < mC; ++i) {
        int x;
        cin >> x;
        prefC.insert(x);
    }


    set<int> assigned;
    int assignedA = 0, assignedB = 0, assignedC = 0;

    
    for (int worker : prefA) {
        if (prefB.find(worker) == prefB.end() && prefC.find(worker) == prefC.end()) {
            if (assignedA < nA) {
                assigned.insert(worker);
                assignedA++;
            }
        }
    }
    for (int worker : prefB) {
        if (prefA.find(worker) == prefA.end() && prefC.find(worker) == prefC.end()) {
            if (assignedB < nB) {
                assigned.insert(worker);
                assignedB++;
            }
        }
    }
    for (int worker : prefC) {
        if (prefA.find(worker) == prefA.end() && prefB.find(worker) == prefB.end()) {
            if (assignedC < nC) {
                assigned.insert(worker);
                assignedC++;
            }
        }
    }




    for (int worker : prefA) {
        if (assigned.find(worker) == assigned.end()) {
            if (assignedA < nA) {
                assigned.insert(worker);
                assignedA++;
            }
        }
    }
    for (int worker : prefB) {
        if (assigned.find(worker) == assigned.end()) {
            if (assignedB < nB) {
                assigned.insert(worker);
                assignedB++;
            }
        }
    }
    for (int worker : prefC) {
        if (assigned.find(worker) == assigned.end()) {
            if (assignedC < nC) {
                assigned.insert(worker);
                assignedC++;
            }
        }
    }
    cout << assigned.size() << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
