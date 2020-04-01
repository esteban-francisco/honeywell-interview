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


/* EXAMPLE DATASETS

INPUT FORMAT:
    NUM_OF_OPERATIONS
    OP_1
    OP_N
    NUM_OF_OP_VALUES
    VAL_1
    VAL_X

OUTPUT FORMAT:
    PROD_1
    PROD_N


EXPECT INPUT/OUTPUT EXAMPLES:
I:  
4
push
push
push
pop
4
1
2
3
1

O:  1
    2
    3
    6

I:  
2
push
push
2
3
2

O:  9
    6

I:
0
4
1
2
3
4

O:  (nothing)

I:
3
push
push
pop
0

O:  (nothing)

I:  
3
push
push
pop
3
2
1

O:  9
    6
    6 // because nothing was popped




2
push
push
2
3
4

2
push
push
0

0
2
3
4



6
push
push
pop
push
push
pop
6
2
3
1
4
5
2


6
push
push
push
pop
pop
pop
6
100
200
300
100
200
300

0
0
*/