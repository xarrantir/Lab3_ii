#pragma once

#ifndef WEB_H
#define WEB_H

#include <vector>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>


using namespace std;
class Web
{
public:
    vector<vector<int>> mul; // Тут будем хранить отмасштабированные сигналы
    vector<vector<int>>weight= { {0, 0, 0}, //Давление вышележащих пород
                                    {0, 0, 0} , //Пластовое давление
                                    {0, 0, 0} , //Коэф.Пуассона
                                    {0, 0, 0} , // Плотность бурового раствора
                                    {0, 0, 0} , // Глубина
                                            };
    vector<vector<int>>input; // Входная информация
    int limit = 100; // Порог - выбран экспериментально, для быстрого обучения
    int sum; // Тут сохраним сумму масштабированных сигналов
    int count_era;
};
void    Weight_output(vector<vector<int>> weight);
void    Weight_input(vector<vector<int>>& weight);
void	Change_weight(vector<vector<int>>& weight, vector<vector<int>>& input, int flag);
bool	Good(Web* w, size_t sizex, size_t sizey);
bool    Bad(Web* w, size_t sizex, size_t sizey);
string	Get_name_file(string dir, int i);
void	fill_input(ifstream& fin, vector<vector<int>>& input);
void	Get_sum(Web* w, int sizex, int sizey);
void	Studying_era(Web* w, int sizex, int sizey);
#endif 
