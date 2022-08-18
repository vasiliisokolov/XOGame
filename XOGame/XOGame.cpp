#include <iostream>

bool check_format(std::string);
char won_in_line(std::string);
std::string get_column(std::string&, std::string&, std::string&, int);
char search_one_element(std::string&, std::string&, std::string&, int, int);
int search_won(std::string&, std::string&, std::string&);
std::string get_diagonal(std::string&, std::string&, std::string&, int);

int main()
{
    std::string line0, line1, line2;
    std::string column0, column1, column2;
    bool valid = true;
    std::cout << "Lets play Noughts and Crosses!\n";
    while (check_format(line0) || check_format(line1) || check_format(line2))
    {
        std::cout << "Enter 3x3 square:\n";
        std::cin >> line0;
        std::cin >> line1;
        std::cin >> line2;
    }
    std::cout << search_won(line0, line1, line2) << std::endl;

    if (search_won(line0, line1, line2) > 1) valid = false;

    
    column0 = get_column(line0, line1, line2, 0);
    column1 = get_column(line0, line1, line2, 1);
    column2 = get_column(line0, line1, line2, 2);


    //std::cout << "Line0: " << won_in_line(line0) << std::endl;
    //std::cout << "Line1: " << won_in_line(line1) << std::endl;
    //std::cout << "Line2: " << won_in_line(line2) << std::endl;
    //std::cout << "column0: " << won_in_line(column0) << std::endl;
    //std::cout << "column1: " << won_in_line(column1) << std::endl;
    //std::cout << "column2: " << won_in_line(column2) << std::endl;
    std::cout << (valid ? "Valid\n" : "Invalid\n");
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

std::string get_column(std::string &line0, std::string &line1, std::string &line2, int columnNumber)
{
    std::string result = "";
    result += line0[columnNumber];
    result += line1[columnNumber];
    result += line2[columnNumber];
    return result;
}

char search_one_element(std::string &line0, std::string &line1, std::string &line2, int x, int y)
{
    std::string line;
    switch (y)
    {
    case 0:
        line = line0;
        break;
    case 1:
        line = line1;
        break;
    case 2:
        line = line2;
        break;
    }
    char result{};
    switch (x)
    {
    case 0:
        result = line[0];
        break;
    case 1:
        result = line[1];
        break;
    case 2:
        result = line[2];
        break;
    }
    return result;
}

int search_won(std::string &line0, std::string &line1, std::string &line2)
{
    int count = 0;
    int lineNumer = 0;
    std::string line;
    
    for (int lineNumer = 0; lineNumer < 8; lineNumer++)
    {
        switch (lineNumer)
        {
        case 0:
            line = line0;
                break;
        case 1:
            line = line1;
                break;
        case 2:
            line = line2;
                break;
        case 3:
            line = get_column(line0, line1, line2, 0);
                break;
        case 4:
            line = get_column(line0, line1, line2, 1);
                break;
        case 5:
            line = get_column(line0, line1, line2, 2);
                break;
        case 6:
            line = get_diagonal(line0, line1, line2, 0);
                break;
        case 7:
            line = get_diagonal(line0, line1, line2, 1);
                break;
        }
        if (won_in_line(line) == 'X' || won_in_line(line) == 'O')
        {
            count++;
        }
    }
    return count;
}

std::string get_diagonal(std::string &line0, std::string &line1, std::string &line2, int diagonalNumber)
{
    std::string line = "";
    int x, y;
    if (diagonalNumber == 0)
    {
        x = 0;
        for (y = 0; y < 3; y++)
        {

            line += search_one_element(line0, line1, line2, x, y);
            x++;
        }

    }
    else if (diagonalNumber == 1)
    {
        x = 2;
        for (y = 0; y < 3; y++)
        {

            line += search_one_element(line0, line1, line2, x, y);
            x--;
        }
    }
    
    return line;
}
