#pragma once
#include <vector>
#include <fstream>
#include <conio.h>
#include "io.h"
#include "Location.h"
#include "Pacman.h"
#include "board.h"
#include "Deamon.h"
#include <io.h>

const int FiftyPoints = 50;
const int LEVELS = 3;
enum Keys
{
    KB_Escape = 27,
    SpecialKey = 224,
};

enum SpecialKeys
{
    KB_Up = 72,
    KB_Down = 80,
    KB_Left = 75,
    KB_Right = 77,
    KB_Space = 32,
};


class GameControl
{
public:
	void StartGame();
    void GetKey();
    bool handleRegularKey( const int c);
    bool handleSpecialKey();
    void UpdateAfterMove();
    void CheckSteps();
    void PacmanEatten();
    void CalculateScore();
    bool CheckCookies()const; 
    void MoveDeamon();
    void ClearSteps();
    void PrintDeamon() const;
    void PrintLevelAndLife(const int level)const;
    

private:
	Board m_board;
    int m_row = 0, m_col = 0;
    Pacman m_pacman;
    std::ifstream m_file;
    int m_life = 3, m_score = 0;
    std::vector <Deamon> m_deamons;
    int m_steps = 0;
    int m_CurrSteps=0;
    int m_cookies = 0;
};