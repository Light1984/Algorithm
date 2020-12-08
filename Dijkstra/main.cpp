// DijkstraAnalysis.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <vector>
#include <chrono>
#include "GraphGenerate.h"
#include "DijkstraImplement.h"


const int TEST_SIZE = 100;
const int MIN_V = 5;
const int MAX_V = 100;
const int STEP = 5;

std::vector<std::vector<int>> result((MAX_V - MIN_V + STEP)/STEP, std::vector<int>(TEST_SIZE,0));

int main()
{
    for (int VS = MIN_V; VS <= MAX_V; VS += STEP)
    {
        for (int test = 0; test < TEST_SIZE; test++)
        {
            //Генерация тестового случая
            generate_sample(VS);

            //Чтение тестового случая
            int V, E;
            std::ifstream sample;
            sample.open("sample.in");
            sample >> V >> E;
            std::vector<std::vector<std::pair<int, int>>> graph;
            graph.resize(V);

            int v, u, w;
            for (int i = 0; i < E; i++)
            {
                sample >> v >> u >> w;
                graph[v].emplace_back(u, w);
            }
            int s;
            sample >> s;

            //Алгоритм Дейкстры
            auto start_time = std::chrono::high_resolution_clock::now();
            Dijkstra(graph, s, V);
            auto end_time = std::chrono::high_resolution_clock::now();
            result[(VS - MIN_V) / STEP][test] = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
        }
    }

    std::ofstream data;
    data.open("data.out");
    for (int i = 0; i < (MAX_V - MIN_V + STEP) / STEP; i++)
    {
        data << (i + 1) * STEP << ", ";
        for (int j = 0; j < TEST_SIZE; j++)
            data << result[i][j] << ", ";
        data << "\n";
    }
}
