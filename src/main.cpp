#define _USE_MATH_DEFINES

#include <algorithm>    // shuffle_random()
#include <ctime>        // time()
#include <cstdlib>      // srand()
#include <cmath>        // M_E
#include <iomanip>      // setprecision()
#include <ios>          // precision, streamsize
#include <iostream>     // cin, cout, endl
#include <string>       // string
#include <vector>       // vector

using namespace std;

void fill(vector<int>&, vector<int>::size_type);
void shuffle(vector<int>&);
bool isDerangement(const vector<int>&);

int main()
{
    // get # of trials
    cout << "How many trials would you like to run? More trials gives results\n"
        << "closer to the expected win rate of 1/e as a percent, where winning\n"
        << "is defined as a permutation being classified as a derangement." << endl;

    int trials;
    while (true) {
        cout << "# of trials: ";
        cin >> trials;

        if (!cin.good() || trials < 1) {
            cin.clear();
            cin.ignore();
            cout << "ERROR: Trials must be a positive integer. \n" << endl;
        } else {
            cout << endl;
            break;
        }
    }

    int derangements[2] = {0, 0};

    // number of elements to arrange
    const vector<int>::size_type elements = 10;
    vector<int> numbers;

    // pseudo random seed for shuffle
    srand( unsigned(time(0)) );

    for (unsigned i = 0; i != trials; ++i) {
        numbers.clear();

        // fill vector with numbers in range [1, elements]
        fill(numbers, elements);

        shuffle(numbers);

        bool derangement = isDerangement(numbers);

        derangements[derangement]++;
    }

    double winRate = double(derangements[true]) / trials * 100;

    streamsize prec = cout.precision();
    cout << "===== DERANGEMENTS =====\n" << setprecision(3)
        << "Count: " << derangements[true] << '\n'
        << "Occurance: " << winRate << "%"
        << "\n\n";

    cout << "===== NON-DERANGEMENTS =====\n" << setprecision(3)
        << "Count: " << derangements[false] << '\n'
        << "Occurance: " << 100 - winRate << "%"
        << "\n\n";

    cout << "% Error from expected: " << abs(1/(M_E)*100 - winRate) << "%"
        << setprecision(prec) << endl;

    return 0;
}

void fill(vector<int> &v, vector<int>::size_type elements)
{
    for (decltype(v.size()) i = 0; i != elements; ++i) {
        v.push_back(i + 1);
    }
    return;
}

void shuffle(vector<int> &v)
{
    random_shuffle(v.begin(), v.end());
    return;
}

bool isDerangement(const vector<int> &v)
{
    for (vector<int>::size_type i = 0; i != v.size(); ++i) {
        int pos = i + 1;

        //cout << pos << ": " << v[i] << endl;

        if (v[i] == pos)
            return false;
    }
    return true;
}
