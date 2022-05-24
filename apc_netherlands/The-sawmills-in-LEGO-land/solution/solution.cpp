#include "solution.hpp"

// returns profit of the certain trunc
int get_profit(int trunc_len)
{
    switch(trunc_len)
    {
        case 1:
            return -1;
        case 2:
            return 3;
        case 3:
            return 1;
        default:
            return 0;
    }
}

// calculate profit of a bunch of truncs
int calculate_profit(const vector<int>& data)
{
    int profit(0);
    int sum_len(0);

    list<int> trunc_list{data.begin(), data.end()};
    list<int> bunch;

    while (!trunc_list.empty())
    {
        auto trunc_len = trunc_list.front();
        trunc_list.pop_front();

        sum_len += trunc_len;
        bunch.push_back(trunc_len);

        if (sum_len >= 3)
        {
            sum_len = 0;
            int max_len = 3;
            while (!bunch.empty())
            {   
                auto trunc_len = bunch.front();
                bunch.pop_front();

                if (max_len - trunc_len < 0)
                {
                    trunc_list.push_front(abs(max_len - trunc_len));
                    trunc_len = max_len;
                } else {
                    max_len -= trunc_len;
                }

                profit += get_profit(trunc_len);
            }
        }
    }

    for (auto trunc_len : bunch)
        profit += get_profit(trunc_len);

    return profit;
}

// generate all trunc combinations
void generate(const vector<int>& input, vector<int>& temp, unordered_set<int>& st, set<pair<int, vector<int>>, cmp>& res, int& max_profit)
{
    if (temp.size() == input.size())
    {
        int profit = calculate_profit(temp);
        if (max_profit <= profit)
            max_profit = profit;
        else
            return;

        res.insert(make_pair(profit, temp));
        return;
    }

    for (int i(0); i < input.size(); i++)
    {
        if (!st.insert(i).second)
            continue;

        temp.push_back(input[i]);
        generate(input, temp, st, res, max_profit);
        temp.pop_back();

        st.erase(i);
    }
}

// read input from stdin
auto read_input()
{
    vector<vector<vector<int>>> input;
    while(true)
    {
        int sawmills(0);
        cin >> sawmills;

        if (sawmills == 0)
            break;

        vector<vector<int>> input_case;
        for (int i(0); i < sawmills; ++i)
        {
            int trunks(0);
            cin >> trunks;

            vector<int> river;
            for (int j(0); j < trunks; ++j)
            {
                int trunc(0);
                cin >> trunc;
                river.push_back(trunc);
            }
            input_case.push_back(river);
        }
        input.push_back(input_case);
    }

    return move(input);
}

// process data read from stdin
void process()
{   
    auto input = read_input();

    for (int i(0); i < input.size(); i++)
    {   
        vector<vector<vector<int>>> to_print;

        int total_max_profit(0);
        for (auto row : input[i])
        {
            int max_profit(0);
            vector<int> temp;
            unordered_set<int> st;
            set<pair<int, vector<int>>, cmp> res;

            generate(row, temp, st, res, max_profit);

            vector<vector<int>> max_res;
            for (auto pair : res)
            {
                if (pair.first == max_profit)
                    max_res.push_back(pair.second);
            }

            to_print.push_back(max_res);
            total_max_profit += max_profit;
        }

        cout << "Case " << i + 1 << '\n';
        cout << "Max profit: " << total_max_profit << '\n';
        cout << "Order: ";
        for (int i(0); i < to_print.size(); ++i)
        {
            print(to_print[i]);

            if (i != to_print.size()-1)
                cout << ", ";
        }
        cout << '\n';
    }
}  

// print a sawmill output
void print(vector<vector<int>>& data)
{
    for (auto row : data)
    {
        cout << "[ ";
        for (auto trunc : row)
        {
            cout << trunc << ' ';
        }
        cout << "]";
    }
}