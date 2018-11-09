#include "robot-config.h"

// port 1 = Front Left Drive Motor (Fl)
// port 2 = Front Right Drive Motor (Fr)
// port 3 = Back Right Drive Motor (Br)
// port 4 = Back Left Drive Motor (Bl)
// port 5 = Flywheel Motor (Fly1)
// port 6 = Flywheel Motor (Fly2) *this motor is reversed
// port 7 = Intake Motor (Intake)
// port 8 = Descoring Arm Motor (Descoring)
// port 20 = Vision Sensor (Vision1)
// port A = Gyroscope Sensor (Gyro1)

int flyvelocity = 200;
bool flytoggle = false;
bool braketoggle = false;
bool colorred = false;

//----------------------------------------------------------------------------------------------------------------------
//                                             Autonomous Functions
//----------------------------------------------------------------------------------------------------------------------

void initialize()
{
    Fl.resetRotation();
    Fr.resetRotation();
    Br.resetRotation();
    Bl.resetRotation();
}

void forward(float x, int speed) //simple forward function
{
    x=((x/12.56636)*0.90001470339);
    initialize();
    while(Fl.rotation(rotationUnits::rev)<x || Fr.rotation(rotationUnits::rev)>-x || Br.rotation(rotationUnits::rev)>-x || Bl.rotation(rotationUnits::rev)<x)
    {
        if(Fl.rotation(rotationUnits::rev)<x)
        {
            Fl.spin(directionType::fwd, speed, velocityUnits::rpm);
        }
        else
        {
            Fl.stop();
        }
        if(Fr.rotation(rotationUnits::rev)>-x)
        {
            Fr.spin(directionType::fwd, -speed, velocityUnits::rpm);
        }
        else
        {
            Fr.stop();
        }
        if(Br.rotation(rotationUnits::rev)>-x)
        {
            Br.spin(directionType::fwd, -speed, velocityUnits::rpm);
        }
        else
        {
            Br.stop();
        }
        if(Bl.rotation(rotationUnits::rev)<x)
        {
            Bl.spin(directionType::fwd, speed, velocityUnits::rpm);
        }
        else
        {
            Bl.stop();
        }
    }
}
void backward(float x, int speed) //simple backward function
{
    x=(x/12.56636)*0.90001470339;
    initialize();
    while(Fl.rotation(rotationUnits::rev)>-x || Fr.rotation(rotationUnits::rev)<x || Br.rotation(rotationUnits::rev)<x || Bl.rotation(rotationUnits::rev)>-x)
    {
        if(Fl.rotation(rotationUnits::rev)>-x)
        {
            Fl.spin(directionType::fwd, -speed, velocityUnits::rpm);
        }
        else
        {
            Fl.stop();
        }
        if(Fr.rotation(rotationUnits::rev)<x)
        {
            Fr.spin(directionType::fwd, speed, velocityUnits::rpm);
        }
        else
        {
            Fr.stop();
        }
        if(Br.rotation(rotationUnits::rev)<x)
        {
            Br.spin(directionType::fwd, speed, velocityUnits::rpm);
        }
        else
        {
            Br.stop();
        }
        if(Bl.rotation(rotationUnits::rev)>-x)
        {
            Bl.spin(directionType::fwd, -speed, velocityUnits::rpm);
        }
        else
        {
            Bl.stop();
        }
    }
}
void turnright(float x) //simple turning function
{
    
    initialize();
    while(Fl.rotation(rotationUnits::rev)<=x)
    {
        Fl.spin(directionType::fwd, 100, velocityUnits::rpm);
        Fr.spin(directionType::fwd, 100, velocityUnits::rpm);
        Br.spin(directionType::fwd, 100, velocityUnits::rpm);
        Bl.spin(directionType::fwd, 100, velocityUnits::rpm);
    }
    Fl.stop();
    Fr.stop();
    Br.stop();
    Bl.stop();
}
void turnleft(float x) //simple turning function
{
    
    initialize();
    while(Fl.rotation(rotationUnits::rev)>=-x)
    {
        Fl.spin(directionType::fwd, -100, velocityUnits::rpm);
        Fr.spin(directionType::fwd, -100, velocityUnits::rpm);
        Br.spin(directionType::fwd, -100, velocityUnits::rpm);
        Bl.spin(directionType::fwd, -100, velocityUnits::rpm);
    }
    Fl.stop();
    Fr.stop();
    Br.stop();
    Bl.stop();
}
void strafeleft(int x) //simple strafing function in the left direction
{
    initialize();
    while(Fl.rotation(rotationUnits::rev)>-x || Fr.rotation(rotationUnits::rev)>-x || Br.rotation(rotationUnits::rev)<x || Bl.rotation(rotationUnits::rev)<x)
    {
        if(Fl.rotation(rotationUnits::rev)<-x)
        {
            Fl.spin(directionType::fwd, -100, velocityUnits::rpm);
        }
        else
        {
            Fl.stop();
        }
        if(Fr.rotation(rotationUnits::rev)>-x)
        {
            Fr.spin(directionType::fwd, -100, velocityUnits::rpm);
        }
        else
        {
            Fr.stop();
        }
        if(Br.rotation(rotationUnits::rev)<x)
        {
            Br.spin(directionType::fwd, 100, velocityUnits::rpm);
        }
        else
        {
            Br.stop();
        }
        if(Bl.rotation(rotationUnits::rev)<x)
        {
            Bl.spin(directionType::fwd, 100, velocityUnits::rpm);
        }
        else
        {
            Bl.stop();
        }
    }
}
void straferight(int x) //simple strafing function in the right direction
{
    initialize();
    while(Fl.rotation(rotationUnits::rev)<x || Fr.rotation(rotationUnits::rev)<x || Br.rotation(rotationUnits::rev)>-x || Bl.rotation(rotationUnits::rev)>-x)
    {
        if(Fl.rotation(rotationUnits::rev)<x)
        {
            Fl.spin(directionType::fwd, 100, velocityUnits::rpm);
        }
        else
        {
            Fl.stop();
        }
        if(Fr.rotation(rotationUnits::rev)<x)
        {
            Fr.spin(directionType::fwd, 100, velocityUnits::rpm);
        }
        else
        {
            Fr.stop();
        }
        if(Br.rotation(rotationUnits::rev)>-x)
        {
            Br.spin(directionType::fwd, -100, velocityUnits::rpm);
        }
        else
        {
            Br.stop();
        }
        if(Bl.rotation(rotationUnits::rev)>-x)
        {
            Bl.spin(directionType::fwd, -100, velocityUnits::rpm);
        }
        else
        {
            Bl.stop();
        }
    }
}
void autonsetting()
{
    Intake.setStopping(brakeType::coast);
    Fly2.setStopping(brakeType::coast);
    Fly1.setStopping(brakeType::coast);
    Descoring.setStopping(brakeType::hold);
    Fr.setStopping(brakeType::brake);
    Fl.setStopping(brakeType::brake);
    Bl.setStopping(brakeType::brake);
    Br.setStopping(brakeType::brake);
}
void farfire()
{
 //fires the two balls at the flags during a far auton. 
}
void closefire()
{
    Intake.spin(directionType::rev,50,velocityUnits::pct);
    vex::task::sleep(1000);
    Intake.stop();
    Fly1.spin(directionType::fwd,135,velocityUnits::rpm);
    Fly2.spin(directionType::fwd,135,velocityUnits::rpm);
    vex::task::sleep(1000);
    Intake.spin(directionType::rev,50,velocityUnits::pct);
    vex::task::sleep(1500);
    Fly1.stop();
    Fly2.stop();
    Intake.stop();
}
void auton()
{
    autonsetting();
    Intake.spin(directionType::fwd, -100, velocityUnits::pct);
	forward(41.81, 150);
    vex::task::sleep(100);
	backward(46, 100);
    vex::task::sleep(400);
    forward(5, 150);
    Intake.stop();
    vex::task::sleep(10);
    Intake.spin(directionType::fwd,50,velocityUnits::pct);
    vex::task::sleep(120);
    Intake.stop();
    Fly1.spin(directionType::fwd, 200, velocityUnits::rpm);
    Fly2.spin(directionType::fwd, 200, velocityUnits::rpm);
    turnright(0.81);
    forward(6, 150);
    vex::task::sleep(3000);
    closefire();
    straferight(0.125);
	forward(35, 150);
	backward(40, 150);
	//turnleft(1.85);
	//backward(10, 100);
	//forward(81, 100);
}

//----------------------------------------------------------------------------------------------------------------------
//                                            Driver Control Functions
//----------------------------------------------------------------------------------------------------------------------


void colordetermine()
{
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("Press X for Red or or A for Blue");
    while(Controller1.ButtonX.pressing()==false && Controller1.ButtonA.pressing()==false)
    {
        Controller1.rumble("-");
        vex::task::sleep(500);
    }
    if(Controller1.ButtonX.pressing()==true)
    {
        colorred=true;
        Vision1.setLedColor(255,0,0);
    }
    else if(Controller1.ButtonA.pressing()==true)
    {
        colorred=false;
        Vision1.setLedColor(0,0,255);
    }
    
}
void flyvelcalc()
{
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print(flyvelocity);
    Controller1.Screen.newLine();
    Controller1.Screen.print(Fly1.velocity(velocityUnits::rpm));
}
void driver()
{
    Intake.setStopping(brakeType::brake);
    Fly2.setStopping(brakeType::coast);
    Fly1.setStopping(brakeType::coast);
    Descoring.setStopping(brakeType::hold);
    int timer = 12;
    Controller1.Screen.clearScreen();
 while(true)
 {
     float three = Controller1.Axis3.position(percentUnits::pct);
     float four = Controller1.Axis4.position(percentUnits::pct);
     float one = Controller1.Axis1.position(percentUnits::pct);
     
     
     if(braketoggle==false)
     {
         Fr.setStopping(brakeType::brake);
         Fl.setStopping(brakeType::brake);
         Bl.setStopping(brakeType::brake);
         Br.setStopping(brakeType::brake);
         Fl.spin(directionType::fwd, three+(0.5*four)+(.875*one), velocityUnits::pct);
         Fr.spin(directionType::fwd, -three+(0.5*four)+(.875*one), velocityUnits::pct);
         Br.spin(directionType::fwd, -three-(0.5*four)+(.875*one), velocityUnits::pct);
         Bl.spin(directionType::fwd, three-(0.5*four)+(.875*one), velocityUnits::pct);     
     }
     else
     {
         Fr.setStopping(brakeType::hold);
         Fl.setStopping(brakeType::hold);
         Bl.setStopping(brakeType::hold);
         Br.setStopping(brakeType::hold);
         Fl.stop();
         Fr.stop();
         Br.stop();
         Bl.stop();
     }
     Descoring.spin(directionType::fwd, 100*(Controller1.ButtonL1.pressing()-Controller1.ButtonL2.pressing()), velocityUnits::pct); 
     Intake.spin(directionType::fwd, 100*(Controller1.ButtonR1.pressing()-Controller1.ButtonR2.pressing()), velocityUnits::pct);
     if(flytoggle==true)
     {
         Fly1.spin(directionType::fwd, flyvelocity, velocityUnits::rpm);
         Fly2.spin(directionType::fwd, flyvelocity, velocityUnits::rpm);
     }
     else
     {
         Fly1.stop();
         Fly2.stop();
     }
     if(Controller1.ButtonY.pressing()==true)
     {
         if(flytoggle==false)
         {
             flytoggle=true;
         }
         else
         {
             flytoggle=false;
         }
         while(Controller1.ButtonY.pressing()==true)
         {
             vex::task::sleep(1);
         }
     }
     if(Controller1.ButtonB.pressing()==true)
     {
         if(braketoggle==false)
         {
             braketoggle=true;
         }
         else
         {
             braketoggle=false;
         }
         while(Controller1.ButtonB.pressing()==true)
         {
             vex::task::sleep(1);
         }
     }
     if(Controller1.ButtonUp.pressing()==true)
     {
         flyvelocity+=10;
     }
     else if(Controller1.ButtonDown.pressing()==true)
     {
         flyvelocity-=10;
     }
     else if(Controller1.ButtonLeft.pressing()==true)
     {
         flyvelocity-=5;
     }
     else if(Controller1.ButtonRight.pressing()==true)
     {
         flyvelocity+=5;
     }
     else if(Controller1.ButtonA.pressing()==true)
     {
         flyvelocity=200;
     }
     while(Controller1.ButtonUp.pressing()==true || Controller1.ButtonDown.pressing()==true || Controller1.ButtonLeft.pressing()==true || Controller1.ButtonRight.pressing()==true || Controller1.ButtonA.pressing()==true)
     {
         vex::task::sleep(1);
     }
     if(flyvelocity>200)
     {
         flyvelocity=200;
     }
     else if(flyvelocity<0)
     {
         flyvelocity=0;
     }
     timer-=1;
     if(timer==0)
     {
         flyvelcalc();
         timer=24;
     }
    vex::task::sleep(10);
 }
}
//----------------------------------------------------------------------------------------------------------------------
//                                              Competition Control
//----------------------------------------------------------------------------------------------------------------------
int main() {
    Fly2.setReversed(true);
    //colordetermine();
    Competition.drivercontrol(driver);
    Competition.autonomous(auton);
    while(1)
    {
        vex::task::sleep(1);
    }
}



