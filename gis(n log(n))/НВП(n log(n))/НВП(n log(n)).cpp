#include <iostream>
#include <vector>
int main()
{
	int k;
	std::cout << "Enter the number of gis: " << std::endl;
	std::cin >> k;
	std::vector<int> sequence(k);
	std::cout << "Enter the sequence: " << std::endl;
	for (int i = 0; i < k; i++)
	{
		std::cin >> sequence[i];
	}
	
	//для ответа
	std::vector <int> prev(k, -1), last(k + 1, -1);

	int inf = std::numeric_limits<int>::max();
	std::vector<int> F(k + 1, inf);
	F[0] = -inf;
	for (int i = 0; i < k; i++)
	{
		//используем бинарный поиск
		int left = 0;
		int right = k;
		while (right - left > 1)
		{
			int middle = (left + right) / 2;
			if (F[middle] >= sequence[i])
				right = middle;
			else
				left = middle;
		}
		F[right] = sequence[i];
		last[right] = i;
		prev[i] = last[right - 1];
	}
	int i = k;
	while (F[i] == inf)
		i--;
	int safe = i;
	i = last[i];
	std::vector<int> ans = { sequence[i] };
	while (prev[i] != -1)
	{
		i = prev[i];
		ans.push_back(sequence[i]);
	}
	std::cout << "so, gis is: " << safe << std::endl;
	std::cout << "and here is subsequence: ";
	for (int i = ans.size() - 1; i >= 0; i--)
		std::cout << ans[i] << " ";
}