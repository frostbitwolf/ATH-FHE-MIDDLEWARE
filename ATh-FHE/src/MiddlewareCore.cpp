#include "MiddlewareCore.h"

MiddlewareCore::MiddlewareCore(const CryptoManager& cryptoMgr) : cryptoManager(cryptoMgr) {}

Ciphertext<DCRTPoly> MiddlewareCore::encryptData(const std::vector<double>& rawData) {
    CryptoContext<DCRTPoly> cc = cryptoManager.getCryptoContext();
    PublicKey<DCRTPoly> pk = cryptoManager.getPublicKey();
    
    Plaintext plaintext = cc->MakeCKKSPackedPlaintext(rawData);
    Ciphertext<DCRTPoly> ciphertext = cc->Encrypt(pk, plaintext);
    return ciphertext;
}

Ciphertext<DCRTPoly> MiddlewareCore::executeSecureAnalytics(const Ciphertext<DCRTPoly>& cipher1, const Ciphertext<DCRTPoly>& cipher2) {
    CryptoContext<DCRTPoly> cc = cryptoManager.getCryptoContext();
    
    // Homomorphic Addition between two ciphertexts (Multi-Cloud secure aggregation)
    Ciphertext<DCRTPoly> result = cc->EvalAdd(cipher1, cipher2);
    return result;
}

std::vector<double> MiddlewareCore::decryptResult(const Ciphertext<DCRTPoly>& cipherResult) {
    CryptoContext<DCRTPoly> cc = cryptoManager.getCryptoContext();
    PrivateKey<DCRTPoly> sk = cryptoManager.getPrivateKey();
    
    Plaintext plaintextResult;
    cc->Decrypt(sk, cipherResult, &plaintextResult);
    
    plaintextResult->SetLength(8);
    return plaintextResult->GetRealPackedValue();
}