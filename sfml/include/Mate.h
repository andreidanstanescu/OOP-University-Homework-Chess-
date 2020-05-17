#ifndef MATE_H
#define MATE_H
#include "table.h"

//Observer Pattern pentru sah mat

class Mate: public Observer
{
    public:
        Mate(table* t,int _denom):Observer(t,_denom){}
        void update(bool white)
        {
    //creez o copie pentru tabla de joc
    int viz2[8][8];
    table& S=getSubject();
    S.copy_table(viz2);

    bool is_chess=0;
    bool is_mat=1;
    //cout<<white;
    std::vector<Piece* >p=S.get_p();
    if(!white)
    {
        for(int i=0;i<16;++i)
        {
            int x=p[i]->get_x();
            int y=p[i]->get_y();
            //cout<<i<<endl;
            //cout<<i<<' '<<x<<' '<<y<<endl;
            for(auto& it: (p[i]->get_moves(x,y,viz2,p,white)) )
            {
                //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                if(viz2[it.first][it.second]==6)
                {
                    //cout<<"Sah la "<<(!white ? "Alb" : "Negru")<<'\n';
                    is_chess=1;
                    break;
                }
            }
        }
        is_mat=is_chess;
        if(is_chess)
        {
            for(int i=16;i<32;++i)
            {
                int x=p[i]->get_x();
                int y=p[i]->get_y();
                int tip=viz2[x][y];
                //cout<<i<<' '<<x<<' '<<y<<endl;
                //cout<<i<<' '<<x<<' '<<y<<endl;
                for(auto& it: (p[i]->get_moves(x,y,viz2,p,!white)) )
                {
                    //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                    if(!viz2[it.first][it.second])
                    {
                        //spot liber si incerc mutarea
                        viz2[it.first][it.second]=viz2[x][y];
                        viz2[x][y]=0;
                        p[i]->set_pos(it.first,it.second);
                        if(!is_in_chess(S,white))
                        {
                            //cout<<"Nu e sah\n";
                            is_mat=0;
                            viz2[it.first][it.second]=0;
                            viz2[x][y]=tip;
                            p[i]->set_pos(x,y);
                            break;
                        }
                        viz2[it.first][it.second]=0;
                        viz2[x][y]=tip;
                        p[i]->set_pos(x,y);
                    }
                    else
                    if(viz2[it.first][it.second]<0)
                    {
                        int before=viz2[it.first][it.second];
                        viz2[it.first][it.second]=viz2[x][y];
                        viz2[x][y]=0;
                        p[i]->set_pos(it.first,it.second);
                        int j;
                        for(int idx=16;idx<32;++idx)
                            if(p[idx]->get_x()==it.first && p[idx]->get_y()==it.second)
                        {
                            j=idx;
                            break;
                        }
                        p[j]->set_pos(-100,-100);
                        if(!is_in_chess(S,white))
                        {
                            is_mat=0;
                            viz2[it.first][it.second]=before;
                            viz2[x][y]=tip;
                            p[i]->set_pos(x,y);
                            p[j]->set_pos(it.first,it.second);
                            break;
                        }
                        viz2[it.first][it.second]=before;
                        viz2[x][y]=tip;
                        p[i]->set_pos(x,y);
                        p[j]->set_pos(it.first,it.second);

                    }
                }
            }

        }

    }
    if(white)
    {
        for(int i=16;i<32;++i)
        {
            int x=p[i]->get_x();
            int y=p[i]->get_y();
            //cout<<i<<endl;
            //cout<<i<<' '<<x<<' '<<y<<endl;
            for(auto& it: (p[i]->get_moves(x,y,viz2,p,white)) )
            {
                //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                if(viz2[it.first][it.second]==-6)
                {
                    //cout<<"Sah la "<<(!white ? "Alb" : "Negru")<<'\n';
                    is_chess=1;
                    break;
                }
            }
        }
        is_mat=is_chess;
        if(is_chess)
        {
            for(int i=0;i<16;++i)
            {
                int x=p[i]->get_x();
                int y=p[i]->get_y();
                int tip=viz2[x][y];
                //cout<<i<<' '<<x<<' '<<y<<endl;
                //cout<<i<<' '<<x<<' '<<y<<endl;
                for(auto& it: (p[i]->get_moves(x,y,viz2,p,!white)) )
                {
                    //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                    if(!viz2[it.first][it.second])
                    {
                        //spot liber si incerc mutarea
                        viz2[it.first][it.second]=viz2[x][y];
                        viz2[x][y]=0;
                        p[i]->set_pos(it.first,it.second);
                        if(!is_in_chess(S,white))
                        {
                            //cout<<"Nu e sah\n";
                            is_mat=0;
                            viz2[it.first][it.second]=0;
                            viz2[x][y]=tip;
                            p[i]->set_pos(x,y);
                            break;
                        }
                        viz2[it.first][it.second]=0;
                        viz2[x][y]=tip;
                        p[i]->set_pos(x,y);
                    }
                    else
                    if(viz2[it.first][it.second]>0)
                    {
                        int before=viz2[it.first][it.second];
                        viz2[it.first][it.second]=viz2[x][y];
                        viz2[x][y]=0;
                        p[i]->set_pos(it.first,it.second);
                        int j;
                        for(int idx=0;idx<16;++idx)
                            if(p[idx]->get_x()==it.first && p[idx]->get_y()==it.second)
                        {
                            j=idx;
                            break;
                        }
                        p[j]->set_pos(-100,-100);
                        if(!is_in_chess(S,white))
                        {
                            is_mat=0;
                            viz2[it.first][it.second]=before;
                            viz2[x][y]=tip;
                            p[i]->set_pos(x,y);
                            p[j]->set_pos(it.first,it.second);
                            break;
                        }
                        viz2[it.first][it.second]=before;
                        viz2[x][y]=tip;
                        p[i]->set_pos(x,y);
                        p[j]->set_pos(it.first,it.second);

                    }
                }
            }

        }

    }

    //cout<<"Este sah mat:"<<is_mat<<endl;
    if(is_mat)
        S.add_update(this);
        }

        virtual ~Mate();

};

#endif // MATE_H
