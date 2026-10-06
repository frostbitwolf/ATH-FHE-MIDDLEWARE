#ifndef MIDDLEWARE_CORE_H
#define MIDDLEWARE_CORE_H

#include "CryptoManager.h"
#include <vector>
#include <string>

class MiddlewareCore {
public:
    MiddlewareCore(const CryptoManager& cryptoMgr);

    // Encrypt client telemetry data
    Ciphertext<DCRTPoly> encryptData(const std::vector<double>& rawData);

    // Perform secure multi-cloud analytics (Homomorphic Addition & Multiplication)
    Ciphertext<DCRTPoly> executeSecureAnalytics(const Ciphertext<DCRTPoly>& cipher1, const Ciphertext<DCRTPoly>& cipher2);

    // Decrypt final results (Client Side)
    std::vector<double> decryptResult(const Ciphertext<DCRTPoly>& cipherResult);

private:
    CryptoManager cryptoManager;
};

#endif // MIDDLEWARE_CORE_H