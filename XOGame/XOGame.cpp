#include <iostream>

bool check_format(std::string);
char won_in_line(std::string);
char won_in_column(std::string, std::string, std::string);

int main()
{
    std::string line0, line1, line2;
    std::cout << "Lets play Noughts and Crosses!\n";
    while (check_format(line0) || check_format(line1) || check_format(line2))
    {
        std::cout << "Enter 3x3 square:\n";
        std::cin >> line0;
        std::cin >> line1;
        std::cin >> line2;
    }
    

    std::cout << "Line0: " << won_in_line(line0) << std::endl;
    std::cout << "Line1: " << won_in_line(line1) << std::endl;
    std::cout << "Line2: " << won_in_line(line2) << std::endl;
}

bool check_format(std::string line)
{
    if (line.length() > 3)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != 'X' || line[i] != 'O' || line[i] != '.')
            {
                return false;
            }
        }
    }
    return true;
}

char won_in_line(std::string line)
{
    int amountX = 0; 
    int amountO = 0;
    int amountPunkt = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == 'X')
        {
            amountX++;
        }
        else if (line[i] == 'O')
        {
            amountO++;
        }
        else if (line[i] == '.')
        {
            amountPunkt++;
        }
    }
    if (amountX == 3)
    {
        return 'X';
    }
    else if (amountO == 3)
    {
        return 'O';
    }
    else if (amountPunkt == 3)
    {
        return '.';
    }
    else return 'N';
}
