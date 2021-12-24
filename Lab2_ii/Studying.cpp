#include "Web.h"
void	Studying_era(Web* w, int sizex, int sizey)
{
	bool	good;
	bool	bad;

	w->count_era = 0;
	while (1)
	{
		good = Good(w, sizex, sizey);
		bad = Bad(w, sizex, sizey);
		w->count_era++;
		if (!good && !bad)
			break;
	}
	Weight_output(w->weight);
}

string Get_name_file(string dir, int i)
{
	string dot;
	string name;
	string res;
	dot = ".txt";
	name = to_string(i);
	res = dir + name + dot;
	return res;
}

void	Weight_output(vector<vector<int>> weight)
{
	ofstream fout("Weight.txt");
	if (fout.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				fout << weight[i][j];
				if (j != 3)
					fout << " ";
			}
			fout << "\n";
		}
	}
}

void	Change_weight(vector<vector<int>>& weight, vector<vector<int>>& input, int flag)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 2; j++)
			weight[i][j] = weight[i][j] + flag * input[i][j];

}

bool	Good(Web* w, size_t sizex, size_t sizey)
{
	bool	flag;
	flag = 0;
	for (int file_count = 1; file_count <= 33; file_count++)
	{
		ifstream fin(Get_name_file("Good\\", file_count));
		if (fin.is_open())
		{
			fill_input(fin, w->input);
			Get_sum(w, sizex, sizey);
			if (w->sum < w->limit)
			{
				Change_weight(w->weight, w->input, 1);
				flag = 1;
			}
			//Weight_output(w->weight);
			fin.close();
		}
	}
	return flag;
	//Weight_output(w->weight);
}

bool	Bad(Web* w, size_t sizex, size_t sizey)
{
	bool	flag;

	flag = 0;
	for (int file_count = 1; file_count <= 45; file_count++)
	{
		ifstream fin(Get_name_file("Bad\\", file_count));
		if (fin.is_open())
		{
			fill_input(fin, w->input);
			Get_sum(w, sizex, sizey);
			if (w->sum >= w->limit)
			{
				Change_weight(w->weight, w->input, -1);
				flag = 1;
			}
			fin.close();
		}
	}
	return flag;
	//Weight_output(w->weight);
}