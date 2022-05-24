#pragma once

#include <fstream>
#include <vector>
#include <set>
#include <queue>

using std::vector;
using std::set;

size_t get_dist(const std::pair<int, int>& city1, const std::pair<int, int>& city2)
{
	return (abs(city2.first - city1.first) + abs(city2.second - city1.second));
}

int get_count(const vector<int>& parents, int cur_vert, int& count)
{
	if (parents[cur_vert] == -1) return count;

	count++;
	return get_count(parents, parents[cur_vert], count);
}

int calculate_rout()
{
	std::fstream fst("c:/users/origi/onedrive/desktop/input.txt", std::ios_base::in);

	int count(0);
	fst >> count;

	int x(0), y(0);
	vector<std::pair<int, int>> cities(count);
	for (int i(0); i < count; ++i)
	{
		fst >> x >> y;
		cities[i] = std::make_pair(x, y);
	}

	int max_dist(0);
	fst >> max_dist;

	vector<set<int>> graph(count);
	for (int i(0); i < count; ++i)
	{
		for (int j(0); j < count; ++j)
		{
			if (i == j) continue;

			size_t temp_dist = get_dist(cities[i], cities[j]);
			if (temp_dist <= max_dist)
				graph[i].insert(j);
		}
	}

	int from(0), to(0), counter(0);
	fst >> from >> to;

	from--;
	to--;

	std::queue<int> que;
	que.push(from);

	vector<bool> visited(graph.size());
	visited[from] = true;

	vector<int> parents(graph.size());
	parents[from] = -1;

	int cur_vert(0);
	while (!que.empty())
	{
		cur_vert = que.front();
		que.pop();
		
		if (cur_vert == to) return get_count(parents, to, counter);

		for (auto& adj_vert : graph[cur_vert])
		{
			if (!visited[adj_vert])
			{
				parents[adj_vert] = cur_vert;
				visited[adj_vert] = true;
				que.push(adj_vert);
			}
		}
	}

	return -1;
}

