#include "CloudSimulator.h"
#include "MiddlewareCore.h"

CloudSimulator::CloudSimulator(const std::string& cloudName, const CryptoManager& cryptoMgr) 
    : name(cloudName), cryptoManager(cryptoMgr) {}

Ciphertext<DCRTPoly> CloudSimulator::processCloudNodeData(const std::vector<double>& telemetryData) {
    MiddlewareCore middleware(cryptoManager);
    return middleware.encryptData(telemetryData);
}

Ciphertext<DCRTPoly> CloudSimulator::aggregateCloudData(const Ciphertext<DCRTPoly>& cipher1, const Ciphertext<DCRTPoly>& cipher2) {
    MiddlewareCore middleware(cryptoManager);
    return middleware.executeSecureAnalytics(cipher1, cipher2);
}

std::string CloudSimulator::getCloudName() const {
    return name;
}