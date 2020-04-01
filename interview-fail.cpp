#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'maxMin' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY operations
 *  2. INTEGER_ARRAY x
 */

vector<long> maxMin(vector<string> operations, vector<int> x) {
    vector<long> products;

    int pushes = 0;
    int count = 0;
    for (string op : operations)
        if (op == "push") pushes++;

    vector<int> elements(pushes);


    for (int i=0; i<operations.size(); i++) {
  
        if (operations[i] == "push") {
            if(!count) {
                elements[0] = x[i];
                count++;
            }
            else {
                for (int j=count; j>=0; j--) {
                    if (x[i] < elements[j]) {
                        elements[j+1] = elements[j];
                    }
                    else {
                        elements[j] = x[i];
                        count++;
                    }
                }
            }
        }            
        else {
            for (int j=count; j>=0; j--) {
                if (x[i] != elements[j]) {
                    elements[j-1] = elements[j];
                }
                else {
                    count--;
                }
            }

        }

        cout << ">> " << endl;
        for (int e : elements)
            cout << e << " " << flush;        

        products.push_back(elements[0] * elements[elements.size()-1]);
    }

    for (long prod : products)
        cout << prod << endl;

    return products;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string operations_count_temp;
    getline(cin, operations_count_temp);

    int operations_count = stoi(ltrim(rtrim(operations_count_temp)));

    vector<string> operations(operations_count);

    for (int i = 0; i < operations_count; i++) {
        string operations_item;
        getline(cin, operations_item);

        operations[i] = operations_item;
    }

    string x_count_temp;
    getline(cin, x_count_temp);

    int x_count = stoi(ltrim(rtrim(x_count_temp)));

    vector<int> x(x_count);

    for (int i = 0; i < x_count; i++) {
        string x_item_temp;
        getline(cin, x_item_temp);

        int x_item = stoi(ltrim(rtrim(x_item_temp)));

        x[i] = x_item;
    }

    vector<long> result = maxMin(operations, x);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
