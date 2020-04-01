#include <bits/stdc++.h>
#include <limits>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


class Node
{
private:
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value): value(value) {
        this->next = NULL;
        this->prev = NULL;
    }
};

class SortedLinkedList
{
private:
    Node *head = NULL;
    Node *tail = NULL;

public:
    SortedLinkedList(): head(NULL), tail(NULL) {}
    ~SortedLinkedList() {
        if (head && tail) return;

        Node *index = head;
        while (index != NULL) {
            index = index->next;
            delete index->prev;
        }
    }

    int getMin() { return (head != NULL) ? this->head->value : 0; }
    int getMax() { return (tail != NULL) ? this->tail->value : 0; }

    // O(n)
    void insert (int value) {
        Node *node = new Node(value);

        if (head == NULL) {
            head = tail = node;
            node->prev = node->next = NULL;
            return;
        }

        // insert at head
        if (node->value <= head->value) {
            head->prev = node;
            node->next = head;
            head = node;
            return;
        }

        // insert at end
        if (node->value >= tail->value) {
            tail->next = node;
            node->prev = tail;
            tail = node;
            return;
        }

        // insert within
        Node *index = head->next;
        while (index != tail) {
            if (node->value >= index->value) {
                node->prev = index;
                node->next = index->next;
                
                node->next->prev = node;
                index->next = node;
                return;
            }

            index = index->next;
        }

    }

    // O(n)
    void remove (int value) {
        if (head == NULL || tail == NULL) return;

        Node *index;

        // remove head
        if (value == head->value) {
            if (head->next == NULL) {
                delete head;
                head = NULL;
                return;
            }
            else {
                index = head;
                head->next->prev = NULL;
                head = index->next;
                delete index;
                return;
            }
        }

        // remove tail
        if (value == tail->value) {
            if (tail->prev == NULL) {
                delete tail;
                tail = NULL;
                return;
            }
            else {
                index = tail;
                tail->prev->next = NULL;
                tail = index->prev;
                delete index;
                return;
            }
        }

        // find and remove
        index = head;
        while (index != NULL) {
            if (index->value == value) {
                index->prev = index->next;
                delete index;
                return;
            }

            index = index->next;
        }
    }
}; // class SortedLinkedList


/*
 * Complete the 'maxMin' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY operations
 *  2. INTEGER_ARRAY x
 */

// start time: 2:17
// don't forget to test edge cases

// O(n^2)
vector<long> maxMin(vector<string> operations, vector<int> x) {
    vector<long> products;
    SortedLinkedList elements;

    if (operations.size() == 0 || x.size() == 0) return products;

    // O(n)
    for (int i=0; i<operations.size(); i++) {
        
        // O(n)
        if (operations[i] == "push") elements.insert(x[i]);
        else elements.remove(x[i]);

        products.push_back(elements.getMin() * elements.getMax());
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

    cout << "\nOUTPUT" << endl;
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;


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


/*
2
push
push
2
3
2


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