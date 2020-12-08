#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>

//Генератор тестовых случаев
inline void generate_sample(int N)
{
	//Иницилизация рандома
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(int(pow(N, 1.5)), int(pow(N, 2)));
	std::uniform_int_distribution<> weight(1, 10);

	int M = dist(gen);

	//Генерация М ребер
	std::vector<int> range(N*N);
	for (int i = 0; i < N*N; i++)
		range[i] = i;
	std::shuffle(range.begin(), range.end(), gen);
	range = std::vector<int>(range.begin(), range.begin() + M);

	//Вывести в файл 
	std::ofstream sample;
	sample.open("sample.in");
	sample << N << " " << M << "\n";
	for (auto v : range)
		sample << v / N << " " << v % N << " " << weight(gen) << "\n";
	sample << gen() % N;
	sample.close();
}
