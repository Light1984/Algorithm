#pragma once
#include <iostream>
#include <vector>

//Данная имплементация не требует связности графа, т.к. останавливается просмотрев все вершины одной компоненты связности
inline void Dijkstra(std::vector<std::vector<std::pair<int, int>>> graph, int s, int N)
{
	const int INF = (int)1e9;
	std::vector<int> d(N, INF), p(N);
	d[s] = 0;
	std::vector<char> u(N);
	for (int i = 0; i < N; ++i) {
		int v = -1;
		for (int j = 0; j < N; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == INF)
			break;
		u[v] = true;

		for (size_t j = 0; j < graph[v].size(); ++j) {
			int to = graph[v][j].first,
				len = graph[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
}