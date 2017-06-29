#include "selector.hpp"
#include "graphics.hpp"
#include "window.hpp"
#include <vector>
#include <sstream>


using namespace genv;
using namespace std;

Selector::Selector(int x, int y, int sx, int sy, vector<Widget::elem> vs,bool kijelolos, int meret)
    : Widget(x,y,sx,sy)
{
    _checked=false;
    _checked2=false;
    _selected=0;
    _s="";
    _start=0;
    _nyit=true;
    _vs=vs;
    _kijelolos_e = kijelolos;
    _meret = meret;
//
//    if(_vs.size()<4) _items=_vs.size();
//            else _items=4;
}

void Selector::draw()
{

        if(_vs.size()<_meret)
        _items=_vs.size();
            else _items=_meret;

        gout << move_to(_x,_y) << color(255,255,255) << box(_size_x,_size_y*_meret);
        gout << move_to(_x+2,_y+2) << color(0,0,0) << box(_size_x-4,_size_y*_meret-4);



        for(int i=0; i<_items; i++)
        {


            gout << move_to(_x,_y+i*_size_y) << color(255,255,255) << box(_size_x, _size_y);
            gout << move_to(_x+2,_y+i*_size_y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

                if(_selected == _start+i)
                {
                gout << move_to(_x+4,_y+i*_size_y+2*_size_y/3) << color(0,255,0) << text(_vs[_start+i].s);
                }
                else

                gout << move_to(_x+4,_y+i*_size_y+2*_size_y/3) << color(255,255,255) << text(_vs[_start+i].s);


            gout << move_to(_x+_size_x-_size_y,_y+i*_size_y) << color(255,255,255) << box(_size_y,_size_y);
            gout << move_to(_x+_size_x-_size_y+2,_y+i*_size_y+2) << color (0,0,0) << box(_size_y-4,_size_y-4);


        }
        if(_vs.size()>_meret && _meret == 4)
        {
            gout << move_to(_x+_size_x-_size_y,_y+_items*_size_y) << genv::move(_size_y/2, -_size_y/4) << color(255,255,255) << line(-_size_y/4,-_size_y/2) << line(_size_y/2,0) << line(-_size_y/4,_size_y/2);
            gout << move_to(_x+_size_x-_size_y,_y) << genv::move(_size_y/2, _size_y/4) << color(255,255,255) << line(-_size_y/4,_size_y/2) << line(_size_y/2,0) << line(-_size_y/4,-_size_y/2);
        }
}



void Selector::handle(event ev)
{
    if (ev.type == ev_mouse && _nyit==true && ev.button==btn_left) {
        if(_mouse_over3(ev.pos_x, ev.pos_y, _items)==1 && _start>0)
            _start--;
        if(_mouse_over3(ev.pos_x, ev.pos_y, _items)==2 && _start<_vs.size()-_items)
            _start++;
    _selected = _select(ev.pos_x,ev.pos_y+_size_y,_items)+_start;
    }

    if(_vs.size()<_meret) _items=_vs.size();
        else _items=_meret;


}
