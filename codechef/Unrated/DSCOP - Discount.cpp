
  #include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string N;
        cin >> N;

        string best;
        for (int i = 0; i < static_cast<int>(N.size()); ++i) {
            string candidate = N.substr(0, i) + N.substr(i + 1);

            // Remove leading zeros for comparison and output.
            size_t firstNonZero = candidate.find_first_not_of('0');
            if (firstNonZero == string::npos) {
                candidate = "0";
            } else {
                candidate = candidate.substr(firstNonZero);
            }

            if (best.empty() ||
                candidate.size() < best.size() ||
                (candidate.size() == best.size() && candidate < best)) {
                best = candidate;
            }
        }

        cout << best << '\n';
    }

    return 0;
}
   
