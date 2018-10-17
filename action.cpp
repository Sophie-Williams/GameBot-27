#include "action.h"

Action::Action(int _type, int _ms)
{
    type=_type;
    ms=_ms;
}
//-----------------------------------------------
Action::Action(int _type, QPoint _target):
    type(_type), target(_target)
{
}
//-----------------------------------------------
void Action::moveToTarget()
{
    QPoint position=cursor->pos();

        int incX = position.x()<target.x() ? 1 : -1,
            incY = position.y()<target.y() ? 1 : -1;

        while(position!=target)
        {
            if(position.x() !=  target.x())
                position.setX( position.x()+incX );
            if(position.y() != target.y())
                position.setY( position.y()+incY );

            cursor->setPos(QApplication::screens().first(), position);
            Sleep(2);
        }
}
//-----------------------------------------------
void Action::exec()
{
    if(type==act_type::wait) Sleep(ms);
    else
    {
        if(type==act_type::left_click)
        {
            moveToTarget();
            leftClick(target);
        }
        else if(type==act_type::right_click)
        {
            moveToTarget();
            rightClick(target);
        }
    }
}
//-----------------------------------------------
void Action::setCursor(QCursor *c)
{
    cursor=c;
}






//-----------------------------------------------
//-----------------------------------------------
void rightClick(QPoint target, int keyModifiers)
{
    mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP,
                target.x(), target.y(), 0, 0);
}

void leftClick(QPoint target, int keyModifiers)
{
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,
                target.x(), target.y(), 0, 0);
}