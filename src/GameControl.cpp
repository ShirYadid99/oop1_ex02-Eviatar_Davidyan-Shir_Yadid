#include "GameControl.h"

//this func satrats the game and  does 3 levels
void GameControl::StartGame()
{
     m_file = std::ifstream("Board.txt");

   for (int level = 0; level < LEVELS ; level++)
    {
        ClearSteps();
        m_board.ReadLevel(m_file);
        m_row = m_board.GetRow();// get the row from the board
        
        
        m_pacman.SetPLocation(m_board.GetPlocation('a'));
        m_pacman.SetPStartLocation();

        int DemonsCounter = m_board.DeamonsCounter();
        m_deamons.resize(DemonsCounter);
        for (int counter = 0; counter < DemonsCounter; counter++)
        {
            m_deamons[counter].SetDLocation(m_board.Get_location('&'));
            m_deamons[counter].SetStartDLocation();
        }

        m_cookies = m_board.CookiesCounter();

        m_board.ClearBoard();// clean the board from & and put ' '
        m_board.Printboard();
        PrintDeamon();
        PrintLevelAndLife(level);
      

        //in the level - reads the move from player 
        while (true)
        {
            if (m_life == 0)
            {   
                exit(EXIT_SUCCESS);
            }
            CheckSteps();
            if (CheckCookies())
            {
                system("cls");
                CalculateScore();
                m_board.ClearMatrix();
                break;
            }
            GetKey();
            UpdateAfterMove();
            MoveDeamon();

            system("cls");
            m_board.Printboard(); 
            PrintDeamon();
            PrintLevelAndLife(level);
        }
    }
}

//move the deamons on the board 
void GameControl::MoveDeamon()
{
    char ObjectsAround[4];
    for (int deamon = 0; deamon < m_deamons.size(); deamon++)
    {
     
        Location l = m_deamons[deamon].GetLocation();
        l.col++;
        ObjectsAround[0] = m_board.GetChar(l);
        l.col -= 2;
        ObjectsAround[1] = m_board.GetChar(l);
        l.col++;
        l.row++;
        ObjectsAround[2] = m_board.GetChar(l);
        l.row -= 2;
        ObjectsAround[3] = m_board.GetChar(l);
        
        m_deamons[deamon].UpdateLocation(m_pacman.GetLocation(), ObjectsAround, m_pacman.GetIsSuper());

        if (!m_pacman.GetIsSuper() && m_pacman.GetLocation().col == m_deamons[deamon].GetLocation().col &&
            m_pacman.GetLocation().row == m_deamons[deamon].GetLocation().row)
        {
            PacmanEatten();
        }
    } 
}

//this function clears the steps - if we are in a new level 
void GameControl::ClearSteps()
{
    m_CurrSteps = 0;
    m_steps = 0;
    m_pacman.UnSetSuper();
}


//this function prints the deamons with for loop
void GameControl::PrintDeamon() const 
{
    for (int counter = 0; counter < m_deamons.size(); counter++)
    {
        m_deamons[counter].PrintDeamon(m_row);
    }

}

//checks if the steps above 20 for the superpacman if so returns to normal
void GameControl::CheckSteps()
{
    m_steps++;
    if (m_steps - m_CurrSteps == 20)
    {
        m_pacman.UnSetSuper();
    }
}


//the pacman is eatten by the deamons put  ' ' instead and decrease the life
void GameControl::PacmanEatten()
{
    m_life--;
    m_board.InsertObject(m_pacman.GetLocation(), ' ');
    m_pacman.SetPLocation(m_pacman.GetPStartLocation());
    for (int counter = 0; counter < m_deamons.size(); counter++)
    {
        m_deamons[counter].SetDLocation(m_deamons[counter].GetStartDLocation());
    }
}



void GameControl::CalculateScore()
{
    m_score += FiftyPoints + 2 * m_deamons.size();

}

//checks num of cookies if 0 - level is over
bool GameControl::CheckCookies() const
{
    if (m_cookies == 0)
        return true;
    return false;
}



void GameControl::PrintLevelAndLife(const int level) const 
{
    std::cout << "Score: " << m_score << "   " << "Life: " << m_life << "   " << "Level: " << level + 1 << std::endl;
}

//gets the key from user
void GameControl::GetKey()
{
    for (auto exit = false; !exit; )
    {
        auto c = _getch();
        switch (c)
        {
        case SpecialKey:
           exit = handleSpecialKey();
            break;
        case KB_Space:
            exit = true;
            break;
        default:
            exit = handleRegularKey(c);
            break;
        }
    }
}

//if the key is regular 
bool GameControl::handleRegularKey(const int c)
{
    switch (c)
    {
    case KB_Escape:
        std::cout << "Escape pressed. Exiting...\n";
        exit(EXIT_SUCCESS);
        return true;
        break;
    }

    return false;
}


//if the key is arraow check which side to move, if the move isnt valid - gets another one
bool GameControl::handleSpecialKey()
{
    auto c = _getch();
    char objectToBe=' ';
    
    switch (c)
    {

    case KB_Up:
        Location up(-1, 0);
        if (m_board.CheckValidPacLocation(up, m_pacman.GetLocation(), m_pacman.GetAppearance() ,objectToBe ))
        {
            m_board.InsertObject(m_pacman.GetLocation(), ' ');
            m_pacman.UpdateLocation(up);
    
            return true;
        }
        else
            GetKey();
        break;

    case KB_Down:
        Location down(1, 0);
        if (m_board.CheckValidPacLocation(down, m_pacman.GetLocation(), m_pacman.GetAppearance(), objectToBe))
        {
            m_board.InsertObject(m_pacman.GetLocation(), ' ');
            m_pacman.UpdateLocation(down);
      

            return true;
        }
        else
        {
            GetKey();
        }
        break;

    case KB_Left:
        Location left(0,-1);
        if (m_board.CheckValidPacLocation(left, m_pacman.GetLocation(), m_pacman.GetAppearance(), objectToBe))
        {
            m_board.InsertObject(m_pacman.GetLocation(), ' ');
            m_pacman.UpdateLocation(left);
          
         
            return true;
        }
        else
        {
            GetKey();
        }
        break;

    case KB_Right:
        Location right(0, 1);
        if (m_board.CheckValidPacLocation(right, m_pacman.GetLocation(), m_pacman.GetAppearance(), objectToBe))
        {
            m_board.InsertObject(m_pacman.GetLocation(), ' ');
            m_pacman.UpdateLocation(right);
            
            return true;
        }
        else
        {
            GetKey();
        }
        break;
 /*   default:
        std::cout << "Unknown special key pressed (code = " << c << ")\n";
        return false;
        break;*/
    }
}

//checks what is in the new cell - and behave as it should
void GameControl::UpdateAfterMove()
{
    char object = (m_board.GetChar(m_pacman.GetLocation()));

    switch (object)
    {
    case 'D': // can only be when superpac
        m_board.InsertObject(m_pacman.GetLocation(), m_pacman.GetAppearance());

        break;

    case ' ':
        m_board.InsertObject(m_pacman.GetLocation(), m_pacman.GetAppearance());
        break;

    case '*':
        m_board.InsertObject(m_pacman.GetLocation(), m_pacman.GetAppearance());
        m_score += 2;
        m_cookies--;
        break;

    case '$':
        m_board.InsertObject(m_pacman.GetLocation(), m_pacman.GetAppearance());
        m_pacman.SetSuper();
        m_CurrSteps = m_steps;
        m_score += 5;
        break;

    case '%':
        m_score += 7;
        m_board.InsertObject(m_pacman.GetLocation(), m_pacman.GetAppearance());
        m_board.DeleteChar(m_board.Get_location('D'));
        break;
    }
    
    //check if it location equal to one of the deamons
    for (int i = 0; i < m_deamons.size(); i++)
    {
        if (!m_pacman.GetIsSuper() && m_pacman.GetLocation().col == m_deamons[i].GetLocation().col &&
            m_pacman.GetLocation().row == m_deamons[i].GetLocation().row)
        {
            PacmanEatten();
        }
    }
}

