#pragma once
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
#include <SoapySDR/Formats.hpp>
#include <SoapySDR/Errors.hpp>
#include <SoapySDR/Device.hpp>

class SdrDeviceChannel
{
public:
	SdrDeviceChannel(SoapySDR::Device *dev, int dir, int no);
	~SdrDeviceChannel();

	std::string probeChannel();
	
private:
	SoapySDR::Device	*soapyDevice {nullptr};

	int		dir {0};
	int		chan {0};
	
	bool								full_duplex {false};
	bool								agc {false};
	std::string							formats;
	double								fullScale {0.0};
	std::string							Native_format;
	std::string							streamArgs;
	std::string							antennas;
	std::vector<std::string>			correctionsList;
	SoapySDR::Range						full_gain_range;
	std::vector<std::string>			gainsList;
	std::vector<SoapySDR::Range>		gain_range;
	SoapySDR::RangeList					full_frequency_range;
	std::vector<std::string>			freqsList;
	std::vector <SoapySDR::RangeList>	frequency_range;
	std::string							freqArgs;
	SoapySDR::RangeList					sample_range;
	std::vector<double>					sample_rates;
	SoapySDR::RangeList					bandwidth_range;
	std::string							sensors;
	std::string							settings;
};


class SdrDevice
{
public:
	SdrDevice(std::string driver);
	~SdrDevice();
	int SoapySDRRateTest(const std::string &argStr, const double sampleRate, const std::string &channelStr, const std::string &directionStr);
	static int checkDriver(const std::string &driverName);
	
private:
	std::string						driver;
	int								active_channel;
	SoapySDR::Device				*soapyDevice;
	std::vector<std::unique_ptr<SdrDeviceChannel>>	channels;
	
	int								makeDevice();
	std::string						SoapySDRDeviceProbe();
	std::string						driver_name, hardware;
	std::vector<std::string>		information;
	size_t							numRxChans {0};
	size_t							numTxChans {0};
	bool							bTimestamps {false};
	std::string						clockSources;
	std::string						timeSources;
	std::string						sensors;
	std::string						registers;
	std::string						settings;
	std::string						gpios;
	std::string						uarts;
};

