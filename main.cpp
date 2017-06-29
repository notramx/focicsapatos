#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include "statictext.hpp"
#include "texteditor.hpp"
#include "window.hpp"
#include "pushbutton.hpp"
#include "szambeallito.hpp"
#include "selector.hpp"

#include <vector>
#include <string>
#include <sstream>

using namespace std;
using namespace genv;


///////////////////////////////////////////////////
class ValamiButton;
class MyWindow;



class MyWindow : public Window
{

public:




    TextEditor *ed5;
    TextEditor *ed6;
    TextEditor *ed7;
    TextEditor *ed8;

    Selector * Kijelolos;
    Selector * Nem_Kijelolos1;
    Selector * Nem_Kijelolos2;
    Selector * Nem_Kijelolos3;
    Selector * Nem_Kijelolos4;

    ValamiButton * Torol;
    ValamiButton * Feltolt;
    ValamiButton * Hozzaad;
    ValamiButton * Kiadas;

    ValamiButton * Tovabbjut1;
    ValamiButton * Tovabbjut2;
    ValamiButton * Tovabbjut3;
    ValamiButton * Tovabbjut4;
    ValamiButton * Tovabbjut5;
    ValamiButton * Tovabbjut6;
    ValamiButton * Tovabbjut7;
    ValamiButton * Tovabbjut8;

    MyWindow() ;

    void esemeny(string mitortent) {

    }
    static void fv(Window *);
    void feltolt_valami()
    {




        Kijelolos->setvs(vs);
        Nem_Kijelolos1->setvs(vs);
    }
    void hozzaad_valami()
    {
        ls.s= ed5->value();
        //ls.fagyi_ertek = _szambeallito->value();

        vs.push_back(ls);

        Kijelolos->setvs(vs);
        Nem_Kijelolos1->setvs(vs);
    }
    void torol_valami()
    {
        //for(int i=Kijelolos->getselected();i<vs.size()-1;i++ ){vs[i]=vs[i+1];}vs.pop_back();
        for(int i=Nem_Kijelolos1->getselected();i<vs.size()-1;i++ ){vs[i]=vs[i+1];}vs.pop_back();
        //for(int i=Nem_Kijelolos2->getselected();i<vs.size()-1;i++ ){vs[i]=vs[i+1];}vs.pop_back();
        //for(int i=Nem_Kijelolos3->getselected();i<vs.size()-1;i++ ){vs[i]=vs[i+1];}vs.pop_back();
        //for(int i=Nem_Kijelolos4->getselected();i<vs.size()-1;i++ ){vs[i]=vs[i+1];}vs.pop_back();

        Kijelolos->setvs(vs);
        Nem_Kijelolos1->setvs(vs);

    }
    void kiadas_valami()
    {
//    if(vs[Kijelolos->getselected()].fagyi_ertek - _szambeallito->value()>=0)
//    vs[Kijelolos->getselected()].fagyi_ertek = vs[Kijelolos->getselected()].fagyi_ertek - _szambeallito->value();

        Kijelolos->setvs(vs);
        Nem_Kijelolos1->setvs(vs);
    }
};

class ValamiButton : public PushButton
{
    MyWindow * mywparent;
    string _azonosito;
public:
    ValamiButton(MyWindow * parent, int x, int y, int sx,
                 int sy, std::string s, string azonosito)
        :PushButton(x, y, sx, sy, s),_azonosito(azonosito)
    {
        mywparent = parent;

    }
    virtual void action() ;
};


MyWindow::MyWindow()
{
        ls.s = "FTC";

        vs.push_back(ls);
        ls.s = "FTC2";

        vs.push_back(ls);
        ls.s = "FTC3";

        vs.push_back(ls);


        Nem_Kijelolos1 = new Selector(20,20,140,40,vs,false,1);  Tovabbjut1 = new ValamiButton(this, 170,20,100,40,"Továbbjut","tovabbjut1");
        Nem_Kijelolos2 = new Selector(20,80,140,40,vs,false,1);  Tovabbjut2 = new ValamiButton(this, 170,80,100,40,"Továbbjut","tovabbjut2");
        Nem_Kijelolos3 = new Selector(20,140,140,40,vs,false,1); Tovabbjut3 = new ValamiButton(this, 170,140,100,40,"Továbbjut","tovabbjut3");
        Nem_Kijelolos4 = new Selector(20,200,140,40,vs,false,1); Tovabbjut4 = new ValamiButton(this, 170,200,100,40,"Továbbjut","tovabbjut4");

        ed5 = new TextEditor(20,260,100,40,"editor5"); Tovabbjut5 = new ValamiButton(this, 170,260,100,40,"Továbbjut","tovabbjut5");
        ed6 = new TextEditor(20,320,100,40,"editor6"); Tovabbjut6 = new ValamiButton(this, 170,320,100,40,"Továbbjut","tovabbjut6");
        ed7 = new TextEditor(20,380,100,40,"editor7"); Tovabbjut7 = new ValamiButton(this, 170,380,100,40,"Továbbjut","tovabbjut7");
        ed8 = new TextEditor(20,440,100,40,"editor8"); Tovabbjut8 = new ValamiButton(this, 170,440,100,40,"Továbbjut","tovabbjut8");



        Feltolt = new ValamiButton(this, 350,440,100,40,"Feltölt","feltolt");
        Torol = new ValamiButton(this, 460,440,100,40,"Töröl","torol");
        Hozzaad = new ValamiButton(this, 570,440,100,40,"Hozzáad","hozzaad");
        Kiadas = new ValamiButton(this, 680,440,100,40,"Kiadás","kiadas");



        Kijelolos = new Selector(610,10,180,40,vs,true,4);




        widgets.push_back(ed5);
        widgets.push_back(ed6);
        widgets.push_back(ed7);
        widgets.push_back(ed8);

        widgets.push_back(Feltolt);
        widgets.push_back(Torol);
        widgets.push_back(Hozzaad);
        widgets.push_back(Kiadas);

        widgets.push_back(Kijelolos);
        widgets.push_back(Nem_Kijelolos1);
        widgets.push_back(Nem_Kijelolos2);
        widgets.push_back(Nem_Kijelolos3);
        widgets.push_back(Nem_Kijelolos4);

        widgets.push_back(Tovabbjut1);
        widgets.push_back(Tovabbjut2);
        widgets.push_back(Tovabbjut3);
        widgets.push_back(Tovabbjut4);
        widgets.push_back(Tovabbjut5);
        widgets.push_back(Tovabbjut6);
        widgets.push_back(Tovabbjut7);
        widgets.push_back(Tovabbjut8);






}




void ValamiButton::action()
{
    if(_azonosito == "feltolt")

     mywparent->feltolt_valami();

     if(_azonosito == "hozzaad")

     mywparent->hozzaad_valami();

     if (_azonosito == "torol")

     mywparent->torol_valami();

     if (_azonosito == "kiadas")

     mywparent->kiadas_valami();

}

int main()
{
    gout.open(800,500);
    MyWindow *mywindow = new MyWindow;
    mywindow->event_loop();
    return 0;
}
