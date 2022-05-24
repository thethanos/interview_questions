#pragma once

#include <vector>

using std::vector;

bool has_cycle(const vector<vector<int>>& graph);

bool canFinish(int num, const vector<vector<int>>& preqs)
{
	vector<vector<int>> graph(num);
	for (int i(0); i < preqs.size(); ++i)
		graph[preqs[i][0]].push_back(preqs[i][1]);
	
	return !has_cycle(graph);
}

bool visit_vertex(const vector<vector<int>>& graph, int vertex, vector<bool>& visited, vector<bool>& res_stack)
{
	if (!visited[vertex])
	{
		visited[vertex] = true;
		res_stack[vertex] = true;

		for (const auto& adj_vert : graph[vertex])
		{
			if (!visited[adj_vert] && visit_vertex(graph, adj_vert, visited, res_stack))
				return true;
			else if (res_stack[adj_vert])
				return true;
		}
	}

	res_stack[vertex] = false;
	return false;
}

bool has_cycle(const vector<vector<int>>& graph)
{
	vector<bool> visited(graph.size());
	vector<bool> res_stack(graph.size());

	for (int vertex(0); vertex < graph.size(); ++vertex)
	{
		if (visit_vertex(graph, vertex, visited, res_stack))
			return true;
	}

	return false;
}