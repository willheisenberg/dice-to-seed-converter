#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <bitset>
#include <openssl/evp.h>
#include "wortliste.h"

std::string toBinaryString(int num) {
    return std::bitset<4>(num - 1).to_string();  // -1 because dice roll is from 1 to 16, but index from 0 to 15
}

std::string toHexString(int num) {
    std::stringstream stream;
    stream << std::hex << (num - 1);  // -1 because dice roll is from 1 to 16, but index from 0 to 15
    return stream.str();
}

std::string calculateSHA256(const unsigned char *data, size_t len) {
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    const EVP_MD* algorithm = EVP_sha256();
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int lengthOfHash = 0;

    EVP_DigestInit_ex(context, algorithm, nullptr);
    EVP_DigestUpdate(context, data, len);
    EVP_DigestFinal_ex(context, hash, &lengthOfHash);
    EVP_MD_CTX_free(context);

    std::string result = "";
    for (unsigned int i = 0; i < lengthOfHash; ++i) {
        result += std::bitset<8>(hash[i]).to_string();
    }
    return result;
}

std::vector<int> convertTo24Words(const std::string &binaryData) {
    std::vector<int> words;
    for (int i = 0; i < 24; ++i) {
        int wordIndex = 0;
        for (int j = 0; j < 11; ++j) {
            wordIndex = (wordIndex << 1) | (binaryData[i * 11 + j] == '1' ? 1 : 0);
        }
        words.push_back(wordIndex);
    }
    return words;
}


void berechneUndZeigeWoerterAn(const std::string &eingabenInHex, const std::string &eingabenInBinary) {
    // Convert Hex string to byte array
    std::vector<unsigned char> binaryData(eingabenInHex.length() / 2);
    for (size_t i = 0; i < eingabenInHex.length(); i += 2) {
        binaryData[i / 2] = static_cast<unsigned char>(strtoul(eingabenInHex.substr(i, 2).c_str(), nullptr, 16));
    }

    // Calculate SHA-256 hash
    std::string hashBinary = calculateSHA256(binaryData.data(), binaryData.size());

    // Append the first 8 bits of hash to the binary string
    std::string finalBinary = eingabenInBinary + hashBinary.substr(0, 8);

    // Convert to 24 words
    std::vector<int> wordIndices = convertTo24Words(finalBinary);

    for (int i = 0; i < 24; ++i) {
        std::cout << (i + 1) << ". " << wortListe[wordIndices[i]] << std::endl;
    }
}

int main() {
    std::string eingabenInHex, eingabenInBinary;
    std::cout << "Geben Sie die 64 Würfe (1-16) ein:\n";
    for (int i = 0; i < 64; ++i) {
        int roll;
        std::cout << "Wurf " << (i + 1) << ": ";
        std::cin >> roll;
        if (roll < 1 || roll > 16) {
            std::cerr << "Fehler: Ungültiger Wert! Bitte geben Sie eine Zahl zwischen 1 und 16 ein." << std::endl;
            return 1;
        }
        eingabenInHex += toHexString(roll);
        eingabenInBinary += toBinaryString(roll);
    }

    berechneUndZeigeWoerterAn(eingabenInHex, eingabenInBinary);
    return 0;
}