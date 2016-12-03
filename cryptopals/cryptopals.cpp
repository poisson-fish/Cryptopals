// This is the main DLL file.

#include "stdafx.h"

#include "cryptopals.h"
using namespace Cryptopals;


std::list<BYTE> Basic::hexToBase64(BYTE* hex,size_t inLength) {
	if (hex) {
		size_t base;
		size_t newLength = sizeof(size_t) * ((inLength + 2) / 3);

		std::list<BYTE> result;
		for (size_t i = 0; i < inLength; i += 3) {
			if (hex[i] == '\0') break;

			base = (hex[i] & 0xFC) >> 2; //AND our 8 bit char value with 1111 1100 then shift the result to the right twice.
			result.push_back(Basic::encodeCharacterTable[base]);
			base = (hex[i] & 0x03) << 4;
			if ((i + 1) < inLength) {
				base |= (hex[i + 1] & 0xF0) >> 4;
				result.push_back(Basic::encodeCharacterTable[base]);
				base = (hex[i + 1] & 0x0F) << 2;

				if (i + 2 < inLength) {
					base |= (hex[i + 2] & 0xC0) >> 6;
					result.push_back(Basic::encodeCharacterTable[base]);
					base = hex[i + 2] & 0x3F;
					result.push_back(Basic::encodeCharacterTable[base]);
				}
				else {
					result.push_back(Basic::encodeCharacterTable[base]);
					result.push_back('=');
				}
			}
			else {
				result.push_back(Basic::encodeCharacterTable[base]);
				result.push_back('=');
				result.push_back('=');
			}

		}

		return result;
	}
}