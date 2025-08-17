#include <iostream>
#include <iomanip>

using namespace std;

// Преферанс с Ленинградской пулькой//




    class player
    {
    private:
        string name;
        int score;
        int bullet;
    public:
        string name;
        int score;
        player()
        {
            name = "player";
            score = 0;
        }

        player(string playername)
        {
            name = playername;
            score = 0;
        }
        void set_name(string s)
        {
            name = s;
        }
        void print_name()
        {
            cout << name << "     ";
        }
        void get_score (int a)
        {
            score +=a;
        }
        void print_score()
        {
            cout.width(6);
            cout << score;
        }
        void bullet-score(player *left, player *right)      // Перераспределение очков в пуле при переборе//
        {
                            if (bullet > lim)
                    {

                        if (left->bullet < lim and left->bullet >= right->bullet)
                        {
                            left->bullet += (bullet - lim);
                            score += 10 * (bullet - lim);
                            left->score -= 10 * (bullet - lim);
                            bullet = lim;
                            if (left->bullet >lim)
                            {
                                right->bullet += (left->bullet - lim);
                                left->score += 10 * (left->bullet - lim);
                                right->score -= 10 * (left->bullet - lim);
                                left->bullet = lim;
                            }
                        }
                        else  if ((right->bullet < lim) and (right->bullet > left->bullet))
                        {
                            right->bullet += (bullet - lim);
                            right->score += 10 * (bullet - lim);
                            right->score -= 10 * (bullet - lim);
                            bullet = lim;
                            if (right->bullet >lim)
                            {
                                left-> bullet += (right->bullet - lim);
                                right->score += 10 * (right->bullet - lim);
                                left->score -= 10 * (right->bullet - lim);
                                right->bullet = lim;
                            }
                        }
                    }
        }
    };

int main()
{
    cout << "Enter players names" << endl;
    string name1, name2, name3;
    cin >> name1 >> name2 >> name3;
    cout << endl << "Enter bullet limit" << endl;
    int lim;
    cin >> lim;
    cout << endl;
    player p1(name1);
    player p2(name2);
    player p3(name3);
    p1.print_name();
    p2.print_name();
    p3.print_name();
    char game;
    int v1,v2,v3;
    string plname;
    while (p1.bullet < lim and p2.bullet < lim and p3.bullet < lim)
    {
        cout << "Enter bullet type(number(10 = 0), m, or p"<< endl;
        cin >> game;
        // МИЗЕР //
        if (game == 'm')
        {
            cout << "Enter players name" << endl;
            cin >> plname;
            cout << endl << "Enter number of vzyatka" << endl;
            cin >> v1;
            if (p1.name == plname)  // player 1 мизер//
            {
                if (v1 == 0)
                {
                    p1.bullet += 10;
                    if (p1.bullet > lim)// Перераспределение очков в пуле при переборе//
                    {

                        if (p2.bullet < lim and p2.bullet >= p3.bullet)
                        {
                            p2. bullet += (p1.bullet - lim);
                            p1.score += 10 * (p1.bullet - lim);
                            p2.score -= 10 * (p1.bullet - lim);
                            p1.bullet = lim;
                            if (p2.bullet >lim)
                            {
                                p3. bullet += (p2.bullet - lim);
                                p2.score += 10 * (p2.bullet - lim);
                                p3.score -= 10 * (p2.bullet - lim);
                                p2.bullet = lim;
                            }
                        }
                        else  if ((p3.bullet < lim) and (p3.bullet > p2.bullet))
                        {
                            p3. bullet += (p1.bullet - lim);
                            p1.score += 10 * (p1.bullet - lim);
                            p3.score -= 10 * (p1.bullet - lim);
                            p1.bullet = lim;
                            if (p3.bullet >lim)
                            {
                                p2. bullet += (p3.bullet - lim);
                                p3.score += 10 * (p3.bullet - lim);
                                p2.score -= 10 * (p3.bullet - lim);
                                p3.bullet = lim;
                            }
                        }
                    }
                }

                else  // Если есть хотя бы 1 взятка//
                {
                      p1.score -= v1*200;
                      p2.score += v1*100;
                      p3.score += v1*100;
                }

            }

            if (p2.name == plname)  // player 2 Мизер//
            {
                if (v1 == 0)
                {
                    p2.bullet += 10;
                    if (p2.bullet > lim)// Перераспределение очков в пуле при переборе//
                    {

                        if (p3.bullet < lim and p3.bullet >= p1.bullet)
                        {
                            p3. bullet += (p2.bullet - lim);
                            p2.score += 10 * (p2.bullet - lim);
                            p3.score -= 10 * (p2.bullet - lim);
                            p2.bullet = lim;
                            if (p3.bullet >lim)
                            {
                                p1. bullet += (p3.bullet - lim);
                                p3.score += 10 * (p3.bullet - lim);
                                p1.score -= 10 * (p3.bullet - lim);
                                p3.bullet = lim;
                            }
                        }
                        else  if ((p1.bullet < lim) and (p1.bullet > p3.bullet))
                        {
                            p1. bullet += (p2.bullet - lim);
                            p2.score += 10 * (p2.bullet - lim);
                            p1.score -= 10 * (p2.bullet - lim);
                            p2.bullet = lim;
                            if (p1.bullet >lim)
                            {
                                p3.bullet += (p1.bullet - lim);
                                p1.score += 10 * (p1.bullet - lim);
                                p3.score -= 10 * (p1.bullet - lim);
                                p1.bullet = lim;
                            }
                        }
                    }
                }

                else  // Если есть хотя бы 1 взятка//
                {
                      p2.score -= v1*200;
                      p3.score += v1*100;
                      p1.score += v1*100;
                }

            }

            if (p2.name == plname)  // player 3 Мизер//
            {
                if (v1 == 0)
                {
                    p3.bullet += 10;
                    if (p3.bullet > lim)// Перераспределение очков в пуле при переборе//
                    {

                        if (p1.bullet < lim and p1.bullet >= p2.bullet)
                        {
                            p1. bullet += (p3.bullet - lim);
                            p3.score += 10 * (p3.bullet - lim);
                            p1.score -= 10 * (p3.bullet - lim);
                            p3.bullet = lim;
                            if (p1.bullet >lim)
                            {
                                p2. bullet += (p1.bullet - lim);
                                p1.score += 10 * (p1.bullet - lim);
                                p2.score -= 10 * (p1.bullet - lim);
                                p1.bullet = lim;
                            }
                        }
                        else  if ((p2.bullet < lim) and (p2.bullet > p1.bullet))
                        {
                            p2. bullet += (p3.bullet - lim);
                            p3.score += 10 * (p3.bullet - lim);
                            p2.score -= 10 * (p3.bullet - lim);
                            p3.bullet = lim;
                            if (p2.bullet >lim)
                            {
                                p1.bullet += (p2.bullet - lim);
                                p2.score += 10 * (p2.bullet - lim);
                                p1.score -= 10 * (p2.bullet - lim);
                                p2.bullet = lim;
                            }
                        }
                    }
                }

                else  // Если есть хотя бы 1 взятка//
                {
                      p3.score -= v1*200;
                      p1.score += v1*100;
                      p2.score += v1*100;
                }

            }
        }
        if (game == p)                     //   Распасы //
        {
               cout << " Enter the vzyatka's quantity of ";
               p1.printname();
               p2.printname();
               p3.printname();
               count << endl;
               cin >>  v1 >> v2 >> v3;
               p1.getscore(5*(v2 + v3 - 2*v1));
               p2.getscore(5*(v3 + v1 - 2*v2));
               p3.getscore(5*(v1 + v2 - 2*v3));
               if (v1 == 0) p1.bullet += 1;
               if (v2 == 0) p2.bullet += 1;
               if (v3 == 0) p3.bullet += 1;





        }


    }
    return 0;
}
