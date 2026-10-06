
#ifndef CLOUD_SIMULATOR_H
#define CLOUD_SIMULATOR_H

#include "CryptoManager.h"
#include "MiddlewareCore.h"
#include <string>
#include <vector>

class CloudSimulator {
public:
    CloudSimulator(const std::string& cloudName, const CryptoManager& cryptoMgr);

    // Simulate Cloud A receiving and processing telemetry data
    Ciphertext<DCRTPoly> processCloudNodeData(const std::vector<double>& telemetryData);

    // Simulate secure multi-cloud aggregation
    Ciphertext<DCRTPoly> aggregateCloudData(const Ciphertext<DCRTPoly>& cipher1, const Ciphertext<DCRTPoly>& cipher2);

    std::string getCloudName() const;

private:
    std::string name;
    CryptoManager cryptoManager;
};

#endif // CLOUD_SIMULATOR_H