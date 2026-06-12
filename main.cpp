#include "TV.h"
#include "AirConditioner.h"
#include "SmartRemote.h"
#include <iostream>

int main()
{
    TV livingRoomTV("Sony Bravia", 30, 50);
    AirConditioner bedroomAC("Daiki", 16, 26);

    SmartRemote remote;
    remote.addDevice(&livingRoomTV);
    remote.addDevice(&bedroomAC);

    std::cout << "--- Testing TV Control ---" << std::endl;
    remote.selectDevice(0);
    remote.pressPower();
    remote.pressPlus();
    remote.pressPlus();
    remote.pressNext();
    remote.showRemoteStatus();

    std::cout << "\n--- Testing Switching to AC Control ---" << std::endl;
    remote.selectDevice(1);
    remote.pressPower();
    remote.pressMinus();
    remote.pressMinus();
    remote.pressNext();
    remote.showRemoteStatus();

    std::cout << "\n--- Verifying Global State of Devices ---" << std::endl;
    livingRoomTV.showInfo();
    bedroomAC.showInfo();

    return 0;
}