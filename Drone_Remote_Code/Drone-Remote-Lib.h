#include <Arduino.h>

#define BT_RX 0
#define BT_TX 1

#define LEFT_JS_X A0
#define LEFT_JS_Y A1
#define RIGHT_JS_X A2
#define RIGHT_JS_Y A3

#define POWER_3.3V 2

class Remote 
{
    public:
        void Init();
        void ConnectToDrone();
        void CheckConnection();
        void PingDrone();

        void RequestAutoLand();
        void HoverPlane();

    private:

}