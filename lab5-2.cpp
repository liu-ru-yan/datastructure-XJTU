
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int hashFunction(int key, int tableSize) {
    return key % tableSize;
}


void linearProbing(vector<int>& table, int key, int& ASL) {
    int index = hashFunction(key, table.size());
    while (table[index] != -1) {
        index = (index + 1) % table.size();
        ASL++; 
    }
    table[index] = key;
}


void quadraticProbing(vector<int>& table, int key, int& ASL) {
    int index = hashFunction(key, table.size());
    int i = 1;
    while (table[index] != -1) {
        index = (index + i * i) % table.size();
        ASL++;
        i++;
    }
    table[index] = key;
}


void chaining(vector<list<int>>& table, int key) {
    int index = hashFunction(key, table.size());
    table[index].push_back(key);
}


double calculateASL(const vector<int>& table, const vector<int>& keys) {
    int ASL = 0;
    for (int key : keys) {
        int index = hashFunction(key, table.size());
        int count = 0;
        while (table[index] != key) {
            index = (index + 1) % table.size();
            count++;
        }
        ASL += count;
    }
    return (double)ASL / keys.size();
}

int main() {
    vector<int> keys = {5, 88, 12, 56, 71, 28, 33, 43, 93, 17};
    int tableSize = 13;


    vector<int> linearTable(tableSize, -1);
    vector<int> quadraticTable(tableSize, -1);
    vector<list<int>> chainingTable(tableSize);


    int linearASL = 0, quadraticASL = 0;
    for (int key : keys) {
        linearProbing(linearTable, key, linearASL);
        quadraticProbing(quadraticTable, key, quadraticASL);
        chaining(chainingTable, key);
    }


    double linearASLAvg = calculateASL(linearTable, keys);
    double quadraticASLAvg = calculateASL(quadraticTable, keys);

    cout << "Linear Probing ASL: " << linearASLAvg << endl;
    cout << "Quadratic Probing ASL: " << quadraticASLAvg << endl;


    for (int i = 0; i < chainingTable.size(); ++i) {
        cout << "Index " << i << ": ";
        for (int key : chainingTable[i]) {
            cout << key << " ";
        }
        cout << endl;
    }

    return 0;
}