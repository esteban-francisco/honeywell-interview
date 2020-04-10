# Honeywell Interview Challenge

The original hacker rank challenge code can be seen below. I am fairly certain that was the original. Unfortunately, I do not have access to the problem descriptions. 

## Understanding the Shared Files
Am I embarassed, oh yes! However, it's worth working through my solutions and how I came to them.

### Submitted HackerRank code: interview-fail.cpp 
* **Time Complexity: O(n^3)!?** If this every ran properlly, it would be terribly slow.
* Lesson Learned: Override those nerves, ignore the clock and take more time to think through the solution before coding.

### Second Version (emailed via Sonia): interview2.cpp 
* **Time Complexity: O(n^2)**
* Ate lunch and tried at it again (timed). Food solves many problems. :-) Also, took more time to think through BEFORE writing code.
* Functional, but not complted within 45 minute limit.
* Without access to the original problem, some lingering questions persisted regarding input/output requirements and space usage. This led me to a sorted-linked-list data structure solution.

### Morning before Interview: interview-200401.cpp
* **Time Complexity: O(n log(n))**   (now that's more like it!)
* Perfect example taking time to approach a problem with a step by step plan. Left some of my thinking as comments.
* Used existing STL map container, which is based on a BST (I believe).
* Much faster now and didn't take much longer to think through and code than previous versions (70 min). Practice and more experience will do wonders for my speed.

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

## Solution
```
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

    // original data always stored

    // do we need to store any information?
    // could work with orginal dataset copied in, but that means multiple loops 
    
    // if using a new data structure, dups must be stored in order to pop dups
        
    // c++ containers
    // working with ints only
    
    // multiset allows dups and always sorts. product is simply first and last.
    //  find: Logarithmic in size.
    //  erase(val): logarithmic in container size, plus linear in the number of elements removed. (always removes ALL of same val)

    // map<val,count>: storted like set, but counter maintained
    //  insert: logarithmic in size in general, returns iterator if exists, so i can count++
    //  find: logarithmic in size. not found, map::end. if found, count--
    //  erase: (erase(position)), amortized constant. or (erase(val)), logarithmic in container size.
    //  cpp ref says "Maps are typically implemented as binary search trees" which means log(n) averages

    // solution decision, map<val,count>. complexit is logorithmic  which is decent

// O(n log(n))
vector<long> maxMin(vector<string> operations, vector<int> x) {
    std::vector<long> products;
    
    if (operations.empty() || x.empty()) return products;
    
    std::map<int,int> map;
    std::map<int,int>::iterator it;
    size_t maxIterations = (operations.size() >= x.size()) ? operations.size() : x.size();

    // O(n) 
    for (size_t i = 0; i < maxIterations; i++) {
        
        // O(log(n))
        if (operations[i] == "push") {
            if (map.find(x[i]) != map.end()) map[x[i]]++;
            else map[x[i]] = 1;        
        }
        else if (operations[i] == "pop") {
            it = map.find(x[i]);

            if (it != map.end()) {
                if (it->second > 1) it->second--;
                else map.erase(it);
            }
        }

        // get and store products
        products.push_back( map.begin()->first * (--map.end())->first);
    }

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

    // output to console for testing
    cout << endl;
    for (int num : result)
        cout << num << endl;

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
