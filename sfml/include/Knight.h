#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include<set>
#include<utility>

class Knight:public Piece
{
    public:
         Knight()
        {
            type="knight";
        }

        Piece* Clone()
        {
            return new Knight(*this);
        }

        Knight& operator=(const Knight &ob)
        {
        x=ob.x;
        y=ob.y;
        color=ob.color;
        type=ob.type;
        return *this;
       }

       //Aceeasi observatie si aici

        /*Knight& operator=(Knight &&ob)
        {
        x=std::exchange(ob.x,-100);
        y=std::exchange(ob.y,-100);
        color=ob.color;
        type=ob.type;
        std::string s("Default");
        ob.set_type(s);
        ob.set_color("Gray");
        return *this;
       }*/

        std::set< std::pair< int,int > > get_moves(int p,int q,int mat[8][8],std::vector<Piece*>&f,bool turn)
        {
            std::set< std::pair< int,int > > h;

            int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
            int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
             for (int i = 0; i < 8; i++) {
                int a = p + dx[i];
                int b = q + dy[i];
                if (a >= 0 && b >= 0 && a < 8 && b < 8 && (!mat[a][b] || mat[a][b]*mat[p][q]<0))
                    h.insert(std::make_pair(a,b));
                }
            return h;
        }
        ~Knight()
        {

        }
};

#endif // KNIGHT_H
