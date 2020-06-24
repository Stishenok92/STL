#include<algorithm>
#include<fstream>
#include<functional>
#include<iostream>
#include<iterator>
#include<list>
#include<numeric>
#include<set>
#include<string>
#include<vector>

int main()
{
    std::cout << "STL\n";
    
    while (true)
    {
        int choice;
        std::cout << "\nChoose vector to test:\n"
        << "1. Vector <char>\n"
        << "2. Vector <std::string>\n"
        << "3. Vector <int>\n"
        << "0. Exit\n"
        << "\nEnter number: ";
        std::cin >> choice;
        
        switch (choice)
        {
            case 0:
            {
                return 0;
            }
            case 1: //vector <char>
            {
                std::cout << "\nTask 1. Vector <char>\n";
                std::vector<char> letters; //создаем вектор типа char
                
                for (size_t i = 65; i < 91; i++) //заносим заглавные буквы алфавита в вектор
                {
                    letters.push_back(i);
                }
                
                std::ostream_iterator<char> out(std::cout, " "); //потоковый итератор вывода на консоль
                bool flag = false;
                
                while (true)
                {
                    int choise;
                    std::cout << "\nCommands:\n"
                    << "1. Print in direct order\n"
                    << "2. Print in reverse order\n"
                    << "0. Exit\n"
                    << "\nEnter number: ";
                    std::cin >> choise;
                    
                    switch (choise)
                    {
                        case 0:
                        {
                            flag = true;
                            break;
                        }
                        case 1:
                        {
                            if (letters.size())
                            {
                                std::copy(letters.begin(), letters.end(), out); //выводит буквы в алфавитном порядке
                                std::cout << "\n";
                            }
                            else
                            {
                                std::cout << "Vector is empty!\n";
                            }
                            
                            break;
                        }
                        case 2:
                        {
                            if (letters.size())
                            {
                                std::reverse_copy(letters.begin(), letters.end(), out); //выводим буквы в обратном алфавитном порядке
                                std::cout << "\n";
                            }
                            else
                            {
                                std::cout << "Vector is empty!\n";
                            }
                            
                            break;
                        }
                        default:
                        {
                            std::cout << "Not number!\n";
                        }
                    }
                    
                    if (flag)
                    {
                        break;
                    }
                }
                
                break;
            }
            case 2: //vector <std::string>
            {
                std::cout << "\nTask 2. Vector <std::string>\n";
                std::ifstream fin("task2.txt"); //создаем поток для чтения файла
                
                if (!fin)
                {
                    std::cout << "Error open file\n";
                    return 0;
                }
                
                std::vector<std::string> words; //создаем вектор типа std::string
                std::istream_iterator<std::string> itIn(fin), itInCur; //создаем два итератора: первый указывает на начало потока чтения файла, второй как temp
                std::copy(itIn, itInCur, back_inserter(words)); //копируем все из файла в вектор
                fin.close(); //закрываем поток чтения файла
                std::ostream_iterator<std::string> out(std::cout, "\n"); //потоковый итератор вывода на консоль
                bool flag = false;
                
                while (true)
                {
                    int choise;
                    std::cout << "\nCommands:\n"
                    << "1. Print\n"
                    << "2. Sort\n"
                    << "3. Print words by letter\n"
                    << "4. Erase words by letter\n"
                    << "0. Exit\n"
                    << "\nEnter number: ";
                    std::cin >> choise;
                    
                    switch (choise)
                    {
                        case 0:
                        {
                            flag = true;
                            break;
                        }
                        case 1: //print
                        {
                            std::copy(words.begin(), words.end(), out);
                            break;
                        }
                        case 2: //sort
                        {
                            std::sort(words.begin(), words.end());
                            std::cout << "Sort done!\n";
                            break;
                        }
                        case 3: //print words by letter
                        {
                            char letter;
                            std::cout << "Enter letter: ";
                            std::cin >> letter;
                            std::vector<std::string>::iterator p1 = find_if(words.begin(), words.end(), [letter](std::string str) { return str[0] == letter ? true : false; }); //лямбда функция
                            
                            if (p1 != words.end())
                            {
                                std::vector<std::string>::iterator p2 = find_if_not(p1, words.end(), [letter](std::string str) { return str[0] == letter ? true : false; });
                                std::copy(p1, p2, out);
                            }
                            else
                            {
                                std::cout << "No words on this letter!\n";
                            }
                            
                            break;
                        }
                        case 4: //erase words by letter
                        {
                            char letter;
                            std::cout << "Enter letter: ";
                            std::cin >> letter;
                            std::vector<std::string>::iterator p1 = find_if(words.begin(), words.end(), [letter](std::string str) { return str[0] == letter ? true : false; });
                            
                            if (p1 != words.end())
                            {
                                std::vector<std::string>::iterator p2 = find_if_not(p1, words.end(), [letter](std::string str) { return str[0] == letter ? true : false; });
                                words.erase(p1, p2);
                                std::cout << "Erase done!\n";
                            }
                            else
                            {
                                std::cout << "No words on this letter!\n";
                            }
                            
                            break;
                        }
                        default:
                        {
                            std::cout << "Not number!\n";
                        }
                    }
                    
                    if (flag)
                    {
                        break;
                    }
                }
                
                break;
            }
            case 3:
            {
                std::cout << "\nTask 3. Vector <int>\n";
                std::ifstream fin("task3.txt");
                
                if (!fin)
                {
                    std::cout << "Error open file\n";
                    return 0;
                }
                
                std::vector<int> numbers; //создаем вектор типа int
                std::istream_iterator<int> itIn(fin), itInCur; //создаем два итератора: первый указывает на начало потока чтения файла, второй как temp
                std::copy(itIn, itInCur, back_inserter(numbers)); //копируем все из файла в вектор
                fin.close(); //закрываем поток чтения файла
                std::ostream_iterator<int> out(std::cout, "\n"); //потоковый итератор вывода на консоль
                bool flag = false;
                
                while (true)
                {
                    int choise;
                    std::cout << "\nCommands:\n"
                    << "1. Print\n"
                    << "2. Sort\n"
                    << "3. Amount of given numbers\n"
                    << "4. Amount numbers greater than number x\n"
                    << "5. Amount all numbers\n"
                    << "6. Sum of all numbers\n"
                    << "7. Arithmetic mean of all numbers\n"
                    << "0. Exit\n"
                    << "\nEnter number: ";
                    std::cin >> choise;
                    
                    switch (choise)
                    {
                        case 0:
                        {
                            flag = true;
                            break;
                        }
                        case 1: //print
                        {
                            std::copy(numbers.begin(), numbers.end(), out);
                            break;
                        }
                        case 2: //sort
                        {
                            std::sort(numbers.begin(), numbers.end());
                            std::cout << "Sort done!\n";
                            break;
                        }
                        case 3: //amount of given numbers
                        {
                            int num;
                            std::cout << "Enter number to find: ";
                            std::cin >> num;
                            long p1 = std::count(numbers.begin(), numbers.end(), num);
                            std::cout << "Amount: " << p1 << "\n";
                            break;
                        }
                        case 4: //amount numbers greater than number x
                        {
                            int num;
                            std::cout << "Enter number x: ";
                            std::cin >> num;
                            long p1 = std::count_if(numbers.begin(), numbers.end(), [num](int i) { return i > num; });
                            std::cout << "Amount: " << p1 << "\n";
                            break;
                        }
                        case 5: //amount all numbers
                        {
                            std::cout << "Amount: " << numbers.size() << "\n";
                            break;
                        }
                        case 6:
                        {
                            int count = std::accumulate(numbers.begin(), numbers.end(), 0);
                            std::cout << "Sum: " << count << "\n";
                            break;
                        }
                        case 7: //arithmetic mean of all numbers
                        {
                            float mean = std::accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
                            std::cout << "Arithmetic mean: " << std::fixed << std::setprecision(2) << mean << "\n";
                            break;
                        }
                        default:
                        {
                            std::cout << "Not number!\n";
                        }
                    }
                    
                    if (flag)
                    {
                        break;
                    }
                }
                
                break;
            }
            default:
            {
                std::cout << "Eror number task!\n";
            }
        }
    }
    
    return 0;
}
