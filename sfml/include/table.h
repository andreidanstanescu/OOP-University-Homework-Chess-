#ifndef TABLE_H
#define TABLE_H
#include "kinig.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include<iostream>
#include<memory>
#include<vector>

//Observer Pattern la sah mat
class Observer;

class table
{
private:
    int tabla[8][8]={
     {-4,-2,-3,-5,-6,-3,-2,-4},
     {-1,-1,-1,-1,-1,-1,-1,-1},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {4, 2, 3, 5, 6, 3, 2, 4}
    };
    std::vector< std::shared_ptr< Piece > >sp;
    std::vector< Piece* >p; //toate piesele
    std::vector<Observer*> views;
    std::vector< std::string > move_count;
    bool turn;
    int nr_moves;
    public:
        table();

        int spot(int x,int y)
        {
            return tabla[x][y];
        }

        void copy_table(int a[8][8])
        {
            for(int i=0;i<8;++i)
                for(int j=0;j<8;++j)
                    tabla[i][j]=a[i][j];
        }

        void set_spot(int x,int y,int a,int b)
        {
            tabla[x][y]=tabla[a][b];
        }

        void set_spot(int x,int y)
        {
            tabla[x][y]=0;
        }

        void add_update(Observer* o)
        {
            views.push_back(o);
        }

        void set_piece(int idx,int _x,int _y)
        {
            p[idx]->set_pos(_x,_y);
        }

        void attach(Observer *obs)
        {
            views.push_back(obs);
        }

        std::vector< std::shared_ptr< Piece > >& get_sp()
        {
            return sp;
        }
        std::vector< Piece* > get_p()
        {
            return p;
        }

        std::string& operator[](int);

        table& operator=(const table&);

        table& operator=(table &&rhs)
        {
        if(this!=&rhs)
        {
        for(int i=0;i<8;++i)
            for(int j=0;j<8;++j)
            this->tabla[i][j]=std::exchange(rhs.tabla[i][j],0);

        this->p.reserve(rhs.p.size());
        for(std::size_t i=0;i<rhs.p.size();++i)
        {
            //Piece* x;
            this->p[i]=rhs.p[i]->Clone();
            //sau, clasic, cum e mai jos comentat (merg ambele variante)
            /*if(dynamic_cast<Pawn*>(rhs.p[i]))
                this->p[i]=Piece::Create(Pion);
            else
                if(dynamic_cast<Knight*>(rhs.p[i]))
                    this->p[i]=Piece::Create(Cal);
            else
                if(dynamic_cast<kinig*>(rhs.p[i]))
                    this->p[i]=Piece::Create(Rege);
            else
                if(dynamic_cast<Rook*>(rhs.p[i]))
                    this->p[i]=Piece::Create(Turn);
            else
                if(dynamic_cast<Queen*>(rhs.p[i]))
                    this->p[i]=Piece::Create(Regina);
            else
                if(dynamic_cast<Bishop*>(rhs.p[i]))
                    this->p[i]=Piece::Create(Nebun);*/

        }
        rhs.p.clear();

        this->turn=rhs.turn;
        this->nr_moves=rhs.nr_moves;
        this->move_count.reserve(rhs.nr_moves);
        for(const auto& it:rhs.move_count)
            this->move_count.emplace_back(it);
        rhs.move_count.clear();

        this->views.reserve(rhs.views.size());
        for(const auto& it:rhs.views)
            this->views.emplace_back(it);

        rhs.views.clear();
        rhs.sp.clear();
        }
        return *this;
        }

        void new_move(const std::string& type)
        {
            ++nr_moves;
            //de implementat aici move assignment
            move_count.push_back(type);
        }

        void notify();


        std::pair<int,int> curr_pieces();

        friend bool is_in_chess(const table&,bool);
        friend bool is_chess_Mate(table&,bool);
        friend bool is_chess_Mate(table&,int viz[8][8],std::vector<Piece*>& p,bool white);

        friend void initializing_1pieces(table& t);
        friend std::ostream& operator<<(std::ostream&,const table&);

        std::vector<Piece*> create_copy(const std::vector<Piece*>& p);

        ~table();
};


class Observer{
private:
    table* subject;
    int denom;
public:
    Observer(table* t,int _denom)
    {
        subject=t;
        denom=_denom;
    }
    virtual void update()=0;
    virtual ~Observer();
protected:
    table& getSubject() {
        return *subject;
    }
    int getDivisor() {
        return denom;
    }

};


#endif // TABLE_H
