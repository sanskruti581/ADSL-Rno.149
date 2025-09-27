#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

int main()
{
    int k, s;
    cout << "Enter number of persons (k): ";
    cin >> k;
    cout << "Enter number of shops (s): ";
    cin >> s;

    vector<pair<string, pair<int, int>>> shops;

    for (int i = 0; i < s; i++)
    {
        string name;
        int start, end;
        cout << "Enter name, start time and end time: ";
        cin >> name >> start >> end;
        shops.push_back({name, {start, end}});
    }

    // Sort shops by end time
    sort(shops.begin(), shops.end(), [](auto &a, auto &b)
         { return a.second.second < b.second.second; });

    // Track last end time for each person, initialized as 0 (no shop visited yet)
    vector<int> last_end_time(k, 0);

    // Store final assignment
    vector<pair<string, int>> assignment; // {shop_name, person_id}
    int total_visited = 0;

    for (auto shop : shops)
    {
        for (int i = 0; i < k; i++)
        {
            if (shop.second.first >= last_end_time[i])
            { // can person i visit this shop?
                last_end_time[i] = shop.second.second;
                assignment.push_back({shop.first, i + 1}); // assign shop to person i+1
                total_visited++;
                break; // shop assigned, move to next shop
            }
        }
    }

    cout << "\nTotal shops visited: " << total_visited << endl;
    cout << "Assignments (Shop -> Person):\n";
    for (auto a : assignment)
    {
        cout << a.first << " -> Person " << a.second << endl;
    }
}

