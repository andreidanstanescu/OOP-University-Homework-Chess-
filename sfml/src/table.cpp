#include "table.h"
#include "My_Exception.h"
#include<assert.h>

table::table()
{
    nr_moves=0;
    sp.reserve(32);
    for(int i=0;i<32;i++)
    {
        if(i==0 || i==7 || i==24 || i==31)
        {
            Piece* x=Piece::Create(Turn);
            sp.emplace_back(std::shared_ptr<Piece>(x));
        }
        else if(i==1 || i==6 || i==30 || i==25)
        {
            Piece* x=Piece::Create(Cal);
            //std::unique_ptr<Piece> ptr2x(x);
            //nu stiu daca face conversie implicita
            sp.emplace_back(std::shared_ptr<Piece>(x));
        }
        else if(i==3 || i==27)
        {
            Piece* x=Piece::Create(Regina);
            sp.emplace_back(std::shared_ptr<Piece>(x));
        }
        else if(i==4 || i==28)
        {
            Piece* x=Piece::Create(Rege);
            sp.emplace_back(std::shared_ptr<Piece>(x));
        }
        else if(i==2 || i==5 || i==29 || i==26)
        {
            Piece *x=Piece::Create(Nebun);
            sp.emplace_back(std::shared_ptr<Piece>(x));
        }
        else{
       Piece* x=Piece::Create(Pion);
       sp.emplace_back(std::shared_ptr<Piece>(x));
        }
    }

    p.reserve(32);
    for(int i=0;i<32;i++)
    {
        if(i==0 || i==7 || i==24 || i==31)
        {
            Piece* x=Piece::Create(Turn);
            p.emplace_back(x);
        }
        else if(i==1 || i==6 || i==30 || i==25)
        {
            Piece* x=Piece::Create(Cal);
            p.emplace_back(x);
        }
        else if(i==3 || i==27)
        {
            Piece* x=Piece::Create(Regina);
            p.emplace_back(x);
        }
        else if(i==4 || i==28)
        {
            Piece* x=Piece::Create(Rege);
            p.emplace_back(x);
        }
        else if(i==2 || i==5 || i==29 || i==26)
        {
            Piece *x=Piece::Create(Nebun);
            p.emplace_back(x);
        }
        else{
       Piece* x=Piece::Create(Pion);
       p.emplace_back(x);
        }
    }
    sf::Texture piese;
    piese.loadFromFile("figures.png");
    for(int i=0;i<32;i++)
    {
       p[i]->get_s().setTexture(piese);
    }
    int index=0;
    p[index]->get_s().setTextureRect(sf::IntRect(0,0,56,56));
    p[index]->get_s().setPosition(0,0);
    p[index]->set_pos(0,0);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(56,0,56,56));
    p[index]->get_s().setPosition(75,0);
    p[index]->set_pos(0,1);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(56*2,0,56,56));
    p[index]->get_s().setPosition(75*2,0);
    p[index]->set_pos(0,2);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(56*3,0,56,56));
    p[index]->get_s().setPosition(75*3,0);
    p[index]->set_pos(0,3);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(56*4,0,56,56));
    p[index]->get_s().setPosition(75*4,0);
    p[index]->set_pos(0,4);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(56*2,0,56,56));
    p[index]->get_s().setPosition(75*5,0);
    p[index]->set_pos(0,5);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(56*1,0,56,56));
    p[index]->get_s().setPosition(75*6,0);
    p[index]->set_pos(0,6);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(0,0,56,56));
    p[index]->get_s().setPosition(75*7,0);
    p[index]->set_pos(0,7);
    index++;


    index=8;
    for(int i=0;i<8;i++)
    {
       p[index]->get_s().setTextureRect(sf::IntRect(56*5,0,56,56));
       p[index]->get_s().setPosition(75*i,70);
       p[index]->set_pos(1,i);
       index++;
    }

    index=16;
    for(int i=0;i<8;i++)
    {
       p[index]->get_s().setTextureRect(sf::IntRect(56*5,56,56,56));
       p[index]->get_s().setPosition(75*i,68*6);
       p[index]->set_pos(6,i);
       index++;
    }

    p[index]->get_s().setTextureRect(sf::IntRect(0,56,56,56));
    p[index]->get_s().setPosition(0,68*7);
    p[index]->set_pos(7,0);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(56,56,56,56));
    p[index]->get_s().setPosition(75,68*7);
    p[index]->set_pos(7,1);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(56*2,56,56,56));
    p[index]->get_s().setPosition(75*2,68*7);
    p[index]->set_pos(7,2);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(56*3,56,56,56));
    p[index]->get_s().setPosition(75*3,68*7);
    p[index]->set_pos(7,3);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(56*4,56,56,56));
    p[index]->get_s().setPosition(75*4,68*7);
    p[index]->set_pos(7,4);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(56*2,56,56,56));
    p[index]->get_s().setPosition(75*5,68*7);
    p[index]->set_pos(7,5);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(56*1,56,56,56));
    p[index]->get_s().setPosition(75*6,68*7);
    p[index]->set_pos(7,6);
    index++;
    p[index]->get_s().setTextureRect(sf::IntRect(0,56,56,56));
    p[index]->get_s().setPosition(75*7,68*7);
    p[index]->set_pos(7,7);
    index++;

}


bool is_in_chess1(int viz[8][8],std::vector<Piece*>& p,bool white)
{
    bool is_chess=0;
    if(!white)
    {
        for(int i=0;i<16;++i)
        {
            int x=p[i]->get_x();
            int y=p[i]->get_y();
            //cout<<i<<' '<<x<<' '<<y<<endl;
            for(auto& it: (p[i]->get_moves(x,y,viz,p,white)) )
            {
                //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                if(viz[it.first][it.second]==6)
                {
                    //cout<<"Sah la "<<(!white ? "Alb" : "Negru")<<'\n';
                    is_chess=1;
                    break;
                }
            }
        }
    }
    else
    {
        for(int i=16;i<32;++i)
        {
            int x=p[i]->get_x();
            int y=p[i]->get_y();
            //cout<<i<<' '<<x<<' '<<y<<endl;
            for(auto& it: (p[i]->get_moves(x,y,viz,p,white)) )
            {
                //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                if(viz[it.first][it.second]==-6)
                {
                    //cout<<"Sah la "<<(!white ? "Alb" : "Negru")<<'\n';
                    is_chess=1;
                    break;
                }
            }
        }

    }
    return is_chess;

}

bool is_in_chess(const table& T,bool white){

bool is_chess=0;
    if(!white)
    {
        for(int i=0;i<16;++i)
        {
            int x=T.p[i]->get_x();
            int y=T.p[i]->get_y();
            //cout<<i<<' '<<x<<' '<<y<<endl;
            for(auto& it: ( (T.p[i])->get_moves(x,y,const_cast<table*>(&T)->tabla,const_cast<table*>(&T)->p,white)) )
            {
                //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                if(T.tabla[it.first][it.second]==6)
                {
                    //cout<<"Sah la "<<(!white ? "Alb" : "Negru")<<'\n';
                    is_chess=1;
                    break;
                }
            }
        }
    }
    else
    {
        for(int i=16;i<32;++i)
        {
            int x=T.p[i]->get_x();
            int y=T.p[i]->get_y();
            //cout<<i<<' '<<x<<' '<<y<<endl;
            for(auto& it: (T.p[i]->get_moves(x,y,const_cast<table*>(&T)->tabla,const_cast<table*>(&T)->p,white)) )
            {
                //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                if(T.tabla[it.first][it.second]==-6)
                {
                    //cout<<"Sah la "<<(!white ? "Alb" : "Negru")<<'\n';
                    is_chess=1;
                    break;
                }
            }
        }

    }
    return is_chess;

}


bool is_in_chess_(int viz[8][8],std::vector<Piece*>& p,bool white)
{
    bool is_chess=0;
    if(!white)
    {
        for(int i=0;i<16;++i)
        {
            int x=p[i]->get_x();
            int y=p[i]->get_y();
            //cout<<i<<' '<<x<<' '<<y<<endl;
            for(auto& it: (p[i]->get_moves(x,y,viz,p,white)) )
            {
                //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                if(viz[it.first][it.second]==6)
                {
                    //cout<<"Sah la "<<(!white ? "Alb" : "Negru")<<'\n';
                    is_chess=1;
                    break;
                }
            }
        }
    }
    else
    {
        for(int i=16;i<32;++i)
        {
            int x=p[i]->get_x();
            int y=p[i]->get_y();
            //cout<<i<<' '<<x<<' '<<y<<endl;
            for(auto& it: (p[i]->get_moves(x,y,viz,p,white)) )
            {
                //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                if(viz[it.first][it.second]==-6)
                {
                    //cout<<"Sah la "<<(!white ? "Alb" : "Negru")<<'\n';
                    is_chess=1;
                    break;
                }
            }
        }

    }
    return is_chess;

}


bool is_chess_Mate(table& T,int viz[8][8],std::vector<Piece*>& p,bool white)
{
    //creez o copie pentru tabla de joc
    int viz2[8][8];
    for(int i=0;i<8;++i)
        for(int j=0;j<8;++j)
            viz2[i][j]=viz[i][j];

    bool is_chess=0;
    bool is_mat=1;
    //cout<<white;
    if(!white)
    {
        for(int i=0;i<16;++i)
        {
            int x=p[i]->get_x();
            int y=p[i]->get_y();
            //cout<<i<<endl;
            //cout<<i<<' '<<x<<' '<<y<<endl;
            for(auto& it: (p[i]->get_moves(x,y,viz,p,white)) )
            {
                //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                if(viz[it.first][it.second]==6)
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
                int tip=viz[x][y];
                //cout<<i<<' '<<x<<' '<<y<<endl;
                //cout<<i<<' '<<x<<' '<<y<<endl;
                for(auto& it: (p[i]->get_moves(x,y,viz,p,!white)) )
                {
                    //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                    if(!viz[it.first][it.second])
                    {
                        //spot liber si incerc mutarea
                        viz[it.first][it.second]=viz[x][y];
                        viz[x][y]=0;
                        p[i]->set_pos(it.first,it.second);
                        if(!is_in_chess_(viz,p,white))
                        {
                            //cout<<"Nu e sah\n";
                            is_mat=0;
                            viz[it.first][it.second]=0;
                            viz[x][y]=tip;
                            p[i]->set_pos(x,y);
                            break;
                        }
                        viz[it.first][it.second]=0;
                        viz[x][y]=tip;
                        p[i]->set_pos(x,y);
                    }
                    else
                    if(viz[it.first][it.second]<0)
                    {
                        int before=viz[it.first][it.second];
                        viz[it.first][it.second]=viz[x][y];
                        viz[x][y]=0;
                        p[i]->set_pos(it.first,it.second);
                        int j;
                        for(int idx=16;idx<32;++idx)
                            if(p[idx]->get_x()==it.first && p[idx]->get_y()==it.second)
                        {
                            j=idx;
                            break;
                        }
                        p[j]->set_pos(-100,-100);
                        if(!is_in_chess_(viz,p,white))
                        {
                            is_mat=0;
                            viz[it.first][it.second]=before;
                            viz[x][y]=tip;
                            p[i]->set_pos(x,y);
                            p[j]->set_pos(it.first,it.second);
                            break;
                        }
                        viz[it.first][it.second]=before;
                        viz[x][y]=tip;
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
            for(auto& it: (p[i]->get_moves(x,y,viz,p,white)) )
            {
                //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                if(viz[it.first][it.second]==-6)
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
                int tip=viz[x][y];
                //cout<<i<<' '<<x<<' '<<y<<endl;
                //cout<<i<<' '<<x<<' '<<y<<endl;
                for(auto& it: (p[i]->get_moves(x,y,viz,p,!white)) )
                {
                    //cout<<it.first<<' '<<it.second<<' '<<viz[it.first][it.second]<<'\n';
                    if(!viz[it.first][it.second])
                    {
                        //spot liber si incerc mutarea
                        viz[it.first][it.second]=viz[x][y];
                        viz[x][y]=0;
                        p[i]->set_pos(it.first,it.second);
                        if(!is_in_chess_(viz,p,white))
                        {
                            //cout<<"Nu e sah\n";
                            is_mat=0;
                            viz[it.first][it.second]=0;
                            viz[x][y]=tip;
                            p[i]->set_pos(x,y);
                            break;
                        }
                        viz[it.first][it.second]=0;
                        viz[x][y]=tip;
                        p[i]->set_pos(x,y);
                    }
                    else
                    if(viz[it.first][it.second]>0)
                    {
                        int before=viz[it.first][it.second];
                        viz[it.first][it.second]=viz[x][y];
                        viz[x][y]=0;
                        p[i]->set_pos(it.first,it.second);
                        int j;
                        for(int idx=0;idx<16;++idx)
                            if(p[idx]->get_x()==it.first && p[idx]->get_y()==it.second)
                        {
                            j=idx;
                            break;
                        }
                        p[j]->set_pos(-100,-100);
                        if(!is_in_chess_(viz,p,white))
                        {
                            is_mat=0;
                            viz[it.first][it.second]=before;
                            viz[x][y]=tip;
                            p[i]->set_pos(x,y);
                            p[j]->set_pos(it.first,it.second);
                            break;
                        }
                        viz[it.first][it.second]=before;
                        viz[x][y]=tip;
                        p[i]->set_pos(x,y);
                        p[j]->set_pos(it.first,it.second);

                    }
                }
            }

        }

    }

    //cout<<"Este sah mat:"<<is_mat<<endl;
    return is_mat;

}




void table::notify() {
  for (int i = 0; i < static_cast<int>(views.size()); i++)
    views[i]->update();
}

std::string& table::operator[](int index)
{
    try{
    if (index >= nr_moves) {
            throw My_Exception("Array index out of bound, exiting");
    }
    }
    catch(My_Exception& e){
        std::cout<<e.what();
    }
    return move_count[index];
    int i=0;
    std::vector< std::string >::iterator it=move_count.begin();
    while(i<index)
        ++it;
    return *it;
}

/*table& table::operator=(const table& rhs)
{
    if(this!=&rhs)
    {
        for(int i=0;i<8;++i)
            for(int j=0;j<8;++j)
            this->tabla[i][j]=rhs.tabla[i][j];

        this->p.reserve(rhs.p.size());
        for(std::size_t i=0;i<rhs.p.size();++i)
        {
            //Piece* x;
            //this->p[i]=rhs.p[i]->Clone();
            //sau, clasic, cum e mai jos comentat (merg ambele variante)
            if(dynamic_cast<Pawn*>(rhs.p[i]))
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
                    this->p[i]=Piece::Create(Nebun);

        }

        this->turn=rhs.turn;
        this->nr_moves=rhs.nr_moves;
        this->move_count.reserve(rhs.nr_moves);
        for(const auto& it:rhs.move_count)
            this->move_count.emplace_back(it);

        this->views.reserve(rhs.views.size());
        for(const auto& it:rhs.views)
            this->views.emplace_back(it);

        //this->sp.reserve(rhs.sp.size());
        //for(const auto& it:rhs.sp)
         //   this->sp.emplace_back(std::shared_ptr<Piece>(new Piece(*it)));
    }
    return *this;
}*/


std::ostream& operator<<(std::ostream& out,const table& T){
    out<<"Mutarea numarul: "<<T.nr_moves<<'\n';
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
            out<<T.tabla[i][j];
        out<<'\n';
    }
    return out;
}


std::pair<int,int> table::curr_pieces()
{
    int nm=0,am=0;
    assert(this->p.size()==32);
    for(int i=0;i<16;++i)
        if(p[i]->get_x()!=-100)
            if(dynamic_cast<kinig*>(p[i])==nullptr)
                nm=std::max(nm,this->tabla[p[i]->get_x()][p[i]->get_y()]);
    for(int i=16;i<32;++i)
        if(p[i]->get_x()!=-100)
            if(dynamic_cast<kinig*>(p[i])==nullptr)
                am=std::max(am,this->tabla[p[i]->get_x()][p[i]->get_y()]);

    for(int i=0;i<8;++i)
        for(int j=0;j<8;++j)
            if(fabs(tabla[i][j])!=6)
                {am=std::max(am,tabla[i][j]);
                nm=std::min(nm,tabla[i][j]);
                }

    return std::make_pair(nm,am);
}


table::~table()
{
   for(auto& x:p)
    {
        delete x;
    }
    p.clear();

    sp.clear();
    views.clear();
    move_count.clear();
}

Observer::~Observer()
{
    delete subject;
}
