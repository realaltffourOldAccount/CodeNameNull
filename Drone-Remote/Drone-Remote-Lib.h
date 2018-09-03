#include <Arduino.h>

#define BT_RX 0
#define BT_TX 1

#define LEFT_JS_X A0
#define LEFT_JS_Y A1
#define RIGHT_JS_X A2
#define RIGHT_JS_Y A3
#define RIGHT_JS_SW 13
#define LEFT_JS_SW 12

#define POWER_3.3V 2

#define CONNECTION_STR "<START>"
#define END_CONNECTION_STR "<END>"

#define HOVER_STR "<HOVER>"
#define AUTO_LAND "<LAND>"

#define PING_DRONE_STR "<PING?>"
#define ALTITUDE_DRONE_STR "<ALTITUDE?>"


#define CONNECTION_STARTED_STR "<CONNECTED!>"

class Remote 
{
    public:
        void Init();
        void ConnectToDrone();
        void CheckConnection();
        void PingDrone();

        void IgniteEngines();
        void IDLE_Engine();
        void SetClimbRate(float rate = 0.3);
        void ShutDownEngines();        

        void RequestAutoLand();
        void StartClimb();
        void HoverPlane();
        
        float GetAltitude();
        float GetDistance();
    private:
        bool connected = false;
        bool inAir = false;
        bool hoverMode = false;
        bool enginesIgnited = false;
        bool engine_idled = false;
        float approxDist = 0.0f;
};

void Remote::Init()
{

}

void Remote::ConnectToDrone()
{

}

void Remote::CheckConnection()
{

}

void Remote::PingDrone()
{

}

void Remote::IgniteEngines()
{

}

void Remote::IDLE_Engine()
{

}

void Remote::SetClimbRate(float rate)
{

}

void Remote::ShutDownEngines()
{

}

void Remote::RequestAutoLand()
{

}

void Remote::StartClimb()
{

}

void Remote::HoverPlane()
{

}

float Remote::GetAltitude()
{

}

float Remote::GetDistance()
{

}