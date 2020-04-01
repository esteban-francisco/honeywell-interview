# Honeywell Interview Challenge

The original hacker rank challenge code can be seen below. I am fairly certain that was the original. Unfortunately, I do not have access to the problem descriptions. 

## Understanding the Shared Files
Am I embarassed, oh yes! However, it's worth working through my solutions and how I came to them.

### Submitted HackerRank code: interview-fail.cpp 
* O(n^3)!? If this every ran properlly, it would be terrible.
* Lesson Learned Mistake: NOT taking the time to think through the problem in advance. Forget the clock and kick anxiety to the curb!

### Second Version (emailed via Sonia): interview2.cpp 
* Time Complexity: O(n^2)
* Ate lunch and tried at it again (timed). Food solves many things. :-)
* Functional, but not within 45 minute limit.
* Took more time to think through BEFORE writing code.
* No access to original problem. Lingering question regardnig input/output requirements and space usage led me to aa manually coded sorted linked list data structure.

### Morning before Interview: interview-200401.cpp
* Time Complexity: O(n log(n))   (now that's more like it!)
* Perfect example taking time to approach a problem with a step by step plan. Left some of my thinking as comments.
* Used existing C++ map container, which is based on a BST (I believe). 
* Much faster now and didn't take much longer to code than previous versions.

## Hacker Rank Code
```
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
```

El Fin.

You need to step it up, Esteban!
