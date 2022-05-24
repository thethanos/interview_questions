#include "solution.hpp"

#include <iostream>

using std::cin;
using std::cout;

// add obstacles to the grid
void TestCase::add_obstacles(vector<vector<int>>& grid, int x1, int x2, int y1, int y2)
{
    for (int i(x1); i <= x2; i++)
    {
        for (int j(y1); j <= y2; j++)
            grid[i][j] = -1;
    }
}

// check if we did not step back or on an obstacle
bool check_step(const vector<vector<int>>& grid, const int cur_x, const int cur_y)
{   
    if (cur_y < 0 || cur_y >= grid.size())
        return false;

    if (cur_x < 0 || cur_x >= grid[cur_y].size())
        return false;

    if (grid[cur_x][cur_y] == -1 || grid[cur_x][cur_y] == 1)
        return false;

    return true;
}

// make steps
void count_hops(vector<vector<int>>& grid, int cur_x, int cur_y, int& res, int& best_res, const int fin_x, const int fin_y)
{
    if (cur_x == fin_x && cur_y == fin_y)
    {   
        best_res = std::min(res, best_res);
        return;
    }

    for (int x(-1); x <= 1; x++)
    {
        for (int y(-1); y <= 1; y++)
        {
            if (check_step(grid, cur_x + x, cur_y + y)) {

                res++;
                grid[cur_x + x][cur_y + y] = 1;
                
                count_hops(grid, cur_x + x, cur_y + y, res, best_res, fin_x, fin_y);
                
                res--;
                grid[cur_x +x][cur_y+y] = 0;
            }
        }
    }
}

// read input from stdin
vector<TestCase> read_input()
{   
    int test_cases_count(0);
    cin >> test_cases_count;

    vector<TestCase> data;
    for (int i(0); i < test_cases_count; ++i)
    {
        TestCase test_case;

        int size_x(0), size_y(0), obstacles(0);

        cin >> size_x >> size_y;
        test_case.make_grid(size_x, size_y);

        cin >> test_case.start.first >> test_case.start.second;
        cin >> test_case.finish.first >> test_case.finish.second;

        cin >> obstacles;
        for (int j(0); j < obstacles; j++)
        {
            int x1(0), x2(0), y1(0), y2(0);
            cin >> x1 >> x2 >> y1 >> y2;

            test_case.add_obstacles(test_case.grid, x1, x2, y1, y2);
        }

        data.push_back(test_case);
    }

    return data;
}

void print_results(const vector<int>& results)
{
    for (auto result : results)
    {
        if (result == INT32_MAX)
            cout << "No solution.\n";
        else if (result >= 2)
            cout << result - 2 << '\n';
        else
            cout << result << '\n';
    }
}

// execute the whole algorithm
void process_data() 
{
    auto data = read_input();

    vector<int> results;
    for (auto test_case : data)
    {   
        int res(0), best_res(INT32_MAX);
        count_hops(test_case.grid, test_case.start.first, test_case.start.second, res, best_res, test_case.finish.first, test_case.finish.second);
        
        results.push_back(best_res);
    }

    print_results(results);
}