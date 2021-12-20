#include <iostream>
#include <string>
#include <vector>
#include <atomic>
#include <memory>

#include <SoapySDR/Version.hpp>
#include <SoapySDR/Modules.hpp>
#include <SoapySDR/Registry.hpp>
#include <SoapySDR/ConverterRegistry.hpp>
#include <SoapySDR/Types.hpp>
#include <SoapySDR/Device.hpp>
#include "SdrDevice.h"

using namespace std;

int printInfo(void);

int main(int argc, char *argv[])
{
	printInfo();

	SoapySDR::ModuleManager mm(false);
	SdrDevice::checkDriver("sdrplay");
	
	std::unique_ptr<SdrDevice> device(new SdrDevice("driver=sdrplay"));
		
	do 
	{
		cout << '\n' << "Press a key to continue...";
	} while (cin.get() != '\n');

	string channelStr = "0";
	string directionStr = "RX";
	
	device->SoapySDRRateTest("", 1000000.0, channelStr, directionStr);
	return 0;
}