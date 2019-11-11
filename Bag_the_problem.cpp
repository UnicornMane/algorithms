#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

int main()
{
	int n, k;
	std::cin >> n >> k;
	std::vector <int> m(n), p(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> m[i];
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> p[i];
	}
	std::vector<std::vector<int>> F(n + 1, std::vector <int>(k + 1, 0));
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < k + 1; j++)
		{
			if (j >= m[i - 1])
			{
				F[i][j] = std::max(F[i - 1][j], F[i - 1][j - m[i - 1]] + p[i - 1]);
			}
			else
			{
				F[i][j] = F[i - 1][j];
			}
		}
	}
	std::cout << "matrix: " << std::endl;
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < k + 1; j++)
			std::cout << F[i][j] << " ";
		std::cout << std::endl;
	}
	int tmp = k;
	std::vector <int> ans;
	for (int i = n; i > 0; i--)
	{
		if (F[i][tmp] != F[i - 1][tmp])
		{
			ans.push_back(i);
			tmp -= m[i - 1];
		}
	}
	std::cout << "items that had been taken: ";
	for (auto s : ans)
		std::cout << s << " ";
	std::cout << std::endl;
	std::cout << "answer: " << std::endl;
	std::cout << F[n][k];
	
}