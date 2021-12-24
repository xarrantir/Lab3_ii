#include "Web.h"
void	fill_input(ifstream& fin, vector<vector<int>>& input)
{
	char	num;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 2; j++)
		{
			fin >> num;
			input[i][j] = static_cast<int>(num) - 48;
		}
}

void Weight_input(vector<vector<int>>& weight)
{
	string line{};
	string number{};
	int	i = 0;
	ifstream fin("Weight.txt");
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			int j = 0;
			std::stringstream strStream(line);
			while (getline(strStream, number, ' '))
			{
				weight[i][j] = atoi(number.c_str());
				j++;
			}
			i++;
		}
		fin.close();
	}
}

void	Get_sum(Web* w, int sizex, int sizey)
{
	w->sum = 0;
	for (int i = 0; i < sizex; i++)
	{
		for (int j = 0; j < sizey; j++)
		{
			w->mul[i][j] = w->input[i][j] * w->weight[i][j];
			w->sum += w->mul[i][j];
		}
	}
}
